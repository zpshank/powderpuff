#include "SampleGame.h"
#include "SDL.h"
#include <iostream>

SampleGame::SampleGame()
    :game_width(250)
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
    face.loadTexture(asset_store.image("face"));

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

    if(face_x + face.frameWidth() > game_width
        || face_x < 0)
    {
        face_x_speed *= -1;
    }

    if(face_y + face.frameHeight() > game_height
        || face_y < 0)
    {
        face_y_speed *= -1;
    }
}

void SampleGame::render(double distance_between_ticks)
{
    if (!assets_loaded)
    {
        return;
    }
    // Clear Screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect background{0, 0, game_width, game_height};
    SDL_RenderFillRect(renderer, &background);

    face.draw(renderer, face_x + (face_x_speed * distance_between_ticks), face_y + (face_y_speed * distance_between_ticks));

    SDL_RenderPresent(renderer);
}
