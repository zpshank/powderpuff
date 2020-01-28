#ifndef _SAMPLEGAME_H_
#define _SAMPLEGAME_H_
#include "Game.h"

namespace pp = powderpuff;

class SampleGame : public pp::Game
{
    public:
        explicit SampleGame();
        void start();
    private:
        int game_width;
        int game_height;
        void update() override;
        void render(double distance_between_ticks) override;

        
};
#endif
