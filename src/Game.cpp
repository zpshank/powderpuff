#include "Game.h"
#include <iostream>
#include "SDL_image.h"
#include <chrono>

namespace chrono = std::chrono;

using namespace powderpuff;

Game:: Game()
    :is_running(false)
    , milliseconds_per_tick(10)
     , milliseconds_per_frame(16)
{
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

bool Game::init(const std::string window_title
        , const int & window_width, const int & window_height
        , const int & window_flags
        , const int & game_width, const int & game_height)
{

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "Unable to initialize SDL:" << SDL_GetError() << std::endl;
        return false;
    }

    int img_flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if((IMG_Init(img_flags) & img_flags) != img_flags)
    {
        std::cout << "Unable to initialize SDL Image: " << IMG_GetError() << std::endl; 
        return false;
    }


    window = SDL_CreateWindow(window_title.c_str()
            , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
            , window_width, window_height
            , window_flags);

    if(window == NULL)
    {
        std::cout << "Unable to create SDL window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Setup Game Width and Height if given
    if (game_width != -1 && game_height != -1)
    {
        if(SDL_RenderSetLogicalSize(renderer, game_width, game_height) != 0)
        {
            std::cout << "Unable to set game resolution: " << SDL_GetError() << std::endl;
            return false;
        }
    }

    return true;
}

void Game::run()
{
    chrono::time_point<chrono::system_clock> previous_loop_time = chrono::system_clock::now();
    double frame_lag_milliseconds = 0;
    is_running = true;
    while(is_running)
    {
        // Calculate timings
        chrono::time_point<chrono::system_clock> current_loop_time = chrono::system_clock::now();
        chrono::duration<double, std::milli> loop_time_elapsed = chrono::duration<double, std::milli>(current_loop_time - previous_loop_time);
        previous_loop_time = current_loop_time;

        frame_lag_milliseconds += loop_time_elapsed.count();

        // Handle input events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            handleEvent(event);
            switch(event.type)
            {
                case SDL_QUIT:
                    is_running = false;
                    break;
            }
        }

        // Fixed updated intervals
        while(frame_lag_milliseconds >= milliseconds_per_tick)
        {
            update();
            frame_lag_milliseconds -= milliseconds_per_tick;
        }

        // Render with distance between updates
        render(frame_lag_milliseconds / milliseconds_per_tick);

        // Throttle FPS for power consumption if necessary
        if(loop_time_elapsed.count() < milliseconds_per_frame)
        {
            SDL_Delay(milliseconds_per_frame - loop_time_elapsed.count());
        }

    }

}
