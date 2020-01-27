#ifndef _ASSETSTORE_H_
#define _ASSETSTORE_H_
#include "SDL_render.h"
#include <map>
#include <string>

class AssetStore
{
    public:
        ~AssetStore();
        /*
         * Adds an image to the asset store.
         * return true if succesfull. False otherwise
         */
        bool addImage(SDL_Renderer* renderer, std::string asset_name, std::string asset_path);
        SDL_Texture* getImage(std::string asset_name);
    private:
        std::map<std::string, SDL_Texture*> images;
};
#endif
