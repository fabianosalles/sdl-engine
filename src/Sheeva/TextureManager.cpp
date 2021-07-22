#include "TextureManager.h"
#include <SDL_image.h>
#include <iostream>

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer)
{
    SDL_Surface* temp = IMG_Load(fileName.c_str());
    if (temp == NULL) {
        std::cout << "Could not load " << fileName.c_str() << ".\n";
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
    SDL_FreeSurface(temp);
    if (texture == NULL) {
        std::cout << "Could not create a texture for " << fileName.c_str() << ".\n";
        return false;
    }
    _textures[id] = texture;
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int w, int h,
    SDL_Renderer* renderer,
    SDL_RendererFlip flip)
{
    SDL_Rect src = { 0 };
    SDL_Rect dst = { 0 };
    src.w = dst.w = w;
    src.h = dst.h = h;
    dst.x = x;
    dst.y = y;

    SDL_RenderCopyEx(renderer, _textures[id], &src, &dst, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int w, int h, int row, 
    int frame, 
    SDL_Renderer* renderer, 
    SDL_RendererFlip flip)
{
    SDL_Rect src = { 0 };
    SDL_Rect dst = { 0 };
    src.x = w * frame;
    src.y = h * (row - 1);
    src.w = dst.w = w;
    src.h = dst.h = h;
    dst.x = x;
    dst.y = y;
    SDL_RenderCopyEx(renderer, _textures[id], &src, &dst, 0, 0, flip);
}

void TextureManager::remove(const std::string id) {
    _textures.erase(id);
}


