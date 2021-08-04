#pragma once

#include <string>
#include <vector>

#include "TextMesh.h"

class TextLine
{
public:
	TextLine();
	~TextLine();

	void genFromString(std::string text);
	std::vector<TextMesh*> getLetters();

private:
	std::vector<TextMesh*> letters;
};

