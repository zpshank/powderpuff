#ifndef _GAME_H_
#define _GAME_H_
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "AssetStore.h"
#include <string>

namespace powderpuff
{
    class Game
    {
        public:
            Game();
            ~Game();
            /*
             * Initializes SDL
             * return true if initialization was succesfull. Otherwise false.
             */
            bool init(const std::string window_title
                    , const int & window_width, const int & window_height
                    , const int & window_flags
                    , const int & game_width = -1, const int & game_height = -1);
        private:
            std::string window_title;
            int milliseconds_per_tick;
            int milliseconds_per_frame;
            bool is_running;
            int game_width;
            int game_height;
        protected:
            void run();
            virtual void draw(){};
            virtual void update(){};
            virtual void render(double distance_between_ticks){};
            virtual void handleEvent(const SDL_Event & event){};
            SDL_Window* window;
            SDL_Renderer* renderer;
            AssetStore asset_store;

    };
}

#endif
