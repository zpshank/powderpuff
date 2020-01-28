#include "Sprite.h"
#include <iostream>

using namespace powderpuff;

bool Sprite::loadTexture(SDL_Texture* texture, const int & total_frame_count)
{
    int texture_width = 0;
    int texture_height = 0;

    if(SDL_QueryTexture(texture, NULL, NULL, &texture_width, &texture_height) != 0)
    {
        std::cout << "Unable to initialize texture: " << SDL_GetError() << std::endl;
        return false;
    }
    
    this->frame_width = texture_width / total_frame_count;
    this->frame_height = texture_height;
    this->total_frame_count = total_frame_count;
    this->texture = texture;

    return true;
}

bool Sprite::draw(SDL_Renderer* renderer, const int & x, const int & y, const int & frame_count)
{
    if (frame_count > total_frame_count)
    {
        std::cout << "Frame count " << frame_count 
            << " is larger than the available number of frames (" << total_frame_count << ")" << std::endl;
        return false;
    }

    SDL_Rect source { frame_count * frame_width, 0, frame_width, frame_height };
    SDL_Rect dest { x, y, frame_width, frame_height };
    if(SDL_RenderCopyEx(renderer, texture, &source, &dest, rotation, NULL, SDL_FLIP_NONE) != 0)
    {
        std::cout << "Unable to render sprite" << std::endl;
        return false;
    }

    return true;
}

int Sprite::getTotalFrameCount()
{
    return total_frame_count;
}

double Sprite::getRotation()
{
    return rotation;
}

void Sprite::setRotation(double rotation)
{
    rotation = rotation;
}

int Sprite::getFrameWidth()
{
    return frame_width;
}

int Sprite::getFrameHeight()
{
    return frame_height;
}
