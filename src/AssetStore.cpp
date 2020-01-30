#include "AssetStore.h"
#include "SDL_image.h"
#include <iostream>

AssetStore::~AssetStore()
{
    for(auto image_iterator : images)
    {
        SDL_Texture* texture = image_iterator.second;

        SDL_DestroyTexture(texture);
    }
}

bool AssetStore::addImage(SDL_Renderer* renderer, const std::string & asset_name, const std::string & asset_path)
{
    SDL_Surface* surface = IMG_Load(asset_path.c_str());
    if (surface == NULL)
    {
        std::cout  << "Unable to load image " << asset_name << ": " << IMG_GetError() << std::endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    images.insert(std::pair<std::string, SDL_Texture*>(asset_name, texture));

    // Clean up surface
    SDL_FreeSurface(surface);

    return true;
}

SDL_Texture* AssetStore::image(const std::string & asset_name)
{
    auto texture_iterator = images.find(asset_name);
    return (texture_iterator == images.end()) ? NULL : texture_iterator->second;
}
