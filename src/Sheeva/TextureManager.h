#pragma once
#include <map>
#include <string>
#include <SDL.h>

class TextureManager
{
public:
	bool load(std::string fileName, std::string id, SDL_Renderer* renderer);
	
	void draw(std::string id, int x, int y, int w, int h, 
		SDL_Renderer* renderer, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	void drawFrame(std::string id, int x, int y, int w, int h, int riw, int frame, 
		SDL_Renderer* renderer, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	std::map<std::string, SDL_Texture*> _textures;
};

