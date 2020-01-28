#ifndef _SAMPLEGAME_H_
#define _SAMPLEGAME_H_
#include "Game.h"
#include "Sprite.h"

namespace pp = powderpuff;

class SampleGame : public pp::Game
{
    public:
        explicit SampleGame();
        void start();
    private:
        bool assets_loaded = false;
        pp::Sprite face;
        double face_x = 0;
        double face_x_speed = 0.5;
        double face_y = 50;
        double face_y_speed = 0.5;

        int game_width;
        int game_height;

        void update() override;
        void render(double distance_between_ticks) override;
        void loadAssets();


};
#endif
