#include "SampleGame.h"
#include <iostream>
#include "SDL.h"
#undef main

int main(int argc, char *argv[])
{
    SampleGame g;
    g.start();
    return 0;
}
