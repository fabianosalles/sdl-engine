#pragma once
#include <string>

class LoaderParams {
public:
	LoaderParams(int x, int y, int w, int h, std::string textureID)
		: x(x), y(y), w(w), h(h), textureID(textureID)
	{

	}

	int x, y, w, h;
	std::string textureID;
};