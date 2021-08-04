#pragma once

#include <GL/glew.h>

#include "stb_image.h"

enum TextureFormat {
	PNG,
	BMP
};

class Texture
{
public:
	Texture();
	Texture(const char* fileLoc, TextureFormat fmt);
	~Texture();

	void loadTexture();
	void useTexture();
	void clearTexture();

private:
	GLuint textureID;
	int width, height, bitDepth;

	const char* fileLocation;
	TextureFormat format;
};

