#ifndef _SPRITE_H_
#define _SPRITE_H_
#include <SDL_render.h>

namespace powderpuff {
    class Sprite
    {
        public:
            explicit Sprite(){};
            bool loadTexture(SDL_Texture* texture, const int & total_frame_count = 1);
            bool draw(SDL_Renderer* renderer, const int & x, const int & y, const int & frame_count = 0);
            int getTotalFrameCount();
            double getRotation();
            void setRotation(double rotation);
            int getFrameWidth();
            int getFrameHeight();

        private:
            SDL_Texture* texture;
            int total_frame_count;
            int frame_width;
            int frame_height;
            double rotation;
    };
}
#endif
