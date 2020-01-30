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
            int totalFrameCount();
            double rotation();
            void setRotation(double rotation);
            int frameWidth();
            int frameHeight();

        private:
            SDL_Texture* texture_;
            int total_frame_count_;
            int frame_width_;
            int frame_height_;
            double rotation_;
    };
}
#endif
