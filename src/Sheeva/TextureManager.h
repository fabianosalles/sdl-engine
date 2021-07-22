#pragma once
#include <map>
#include <string>
#include <SDL.h>

#include "Singleton.h"

class TextureManager
{
public:
	static auto& instance() {
		static TextureManager _instance;
		return _instance;
	}

	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	TextureManager(TextureManager&&) = delete;
	TextureManager& operator=(TextureManager&&) = delete;

	bool load(std::string fileName, std::string id, SDL_Renderer* renderer);
	
	void draw(std::string id, int x, int y, int w, int h, 
		SDL_Renderer* renderer, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	void drawFrame(std::string id, int x, int y, int w, int h, int row, int frame, 
		SDL_Renderer* renderer, 
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void remove(const std::string id);

private:
	TextureManager() {}
	std::map<std::string, SDL_Texture*> _textures;
};