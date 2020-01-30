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
    
    this->frame_width_ = texture_width / total_frame_count;
    this->frame_height_ = texture_height;
    this->total_frame_count_ = total_frame_count;
    this->texture_ = texture;

    return true;
}

bool Sprite::draw(SDL_Renderer* renderer, const int & x, const int & y, const int & frame_count)
{
    if (frame_count > total_frame_count_)
    {
        std::cout << "Frame count " << frame_count 
            << " is larger than the available number of frames (" << total_frame_count_ << ")" << std::endl;
        return false;
    }

    SDL_Rect source { frame_count * frame_width_, 0, frame_width_, frame_height_ };
    SDL_Rect dest { x, y, frame_width_, frame_height_ };
    if(SDL_RenderCopyEx(renderer, texture_, &source, &dest, rotation_, NULL, SDL_FLIP_NONE) != 0)
    {
        std::cout << "Unable to render sprite: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

int Sprite::totalFrameCount()
{
    return total_frame_count_;
}

double Sprite::rotation()
{
    return rotation_;
}

void Sprite::setRotation(double rotation)
{
    rotation = rotation;
}

int Sprite::frameWidth()
{
    return frame_width_;
}

int Sprite::frameHeight()
{
    return frame_height_;
}
