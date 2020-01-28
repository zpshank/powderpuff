#include "SampleGame.h"
#include "SDL.h"
#include <iostream>

namespace chrono = std::chrono;

SampleGame::SampleGame()
    :game_width(200)
     , game_height(200)
{
}

void SampleGame::start()
{
    init("Hello World!"
            , 800, 600
            , SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI
            , game_width, game_height
        );
    run();
}

void SampleGame::loadAssets()
{
    std::string base_path(SDL_GetBasePath());
    asset_store.addImage(renderer, "face", base_path + std::string("face.png"));
    face.loadTexture(asset_store.getImage("face"));

    assets_loaded = true;
}

void SampleGame::update()
{
    if(!assets_loaded)
    {
        loadAssets();
    }

    face_x += face_x_speed;
    face_y += face_y_speed;

    if(face_x + face.getFrameWidth() > game_width
        || face_x < 0)
    {
        face_x_speed *= -1;
    }

    if(face_y + face.getFrameHeight() > game_height
        || face_y < 0)
    {
        face_y_speed *= -1;
    }
}

void SampleGame::render(double distance_between_ticks)
{
    // Clear Screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect rectangle {0, 0, 200, 200};
    SDL_RenderFillRect(renderer, &rectangle);

    face.draw(renderer, face_x + (face_x_speed * distance_between_ticks), face_y + (face_y_speed * distance_between_ticks));

    SDL_RenderPresent(renderer);
}
