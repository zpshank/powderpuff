#include "SampleGame.h"
#include "SDL.h"
#include <iostream>

namespace chrono = std::chrono;

SampleGame::SampleGame()
    :game_width(200)
     , game_height(300)
{
}

void SampleGame::start()
{
    init("Hello World!"
            , 800, 600
            , SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
            , 200, 200
        );
    run();
}

void SampleGame::update()
{
}

void SampleGame::render(double distance_between_ticks)
{
    // Clear Screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rectangle {0, 0, 100, 100};
    SDL_RenderFillRect(renderer, &rectangle);

    SDL_RenderPresent(renderer);
}
