#include "TextLine.h"

TextLine::TextLine() {

}

TextLine::~TextLine() {
}

std::vector<TextMesh*> TextLine::getLetters() {
	return letters;
}

void TextLine::genFromString(std::string text) {
	for (TextMesh* t : letters) {
		delete(t);
	}
	letters.clear();

	for (char c : text) {
		switch (c) {
			case 'a':
			case 'A': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::A);
				break;
			}
			case 'b':
			case 'B': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::B);
				break;
			}
			case 'c':
			case 'C': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::C);
				break;
			}
			case 'd':
			case 'D': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::D);
				break;
			}
			case 'e':
			case 'E': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::E);
				break;
			}
			case 'f':
			case 'F': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::F);
				break;
			}
			case 'g':
			case 'G': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::G);
				break;
			}
			case 'h':
			case 'H': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::H);
				break;
			}
			case 'i':
			case 'I': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::I);
				break;
			}
			case 'j':
			case 'J': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::J);
				break;
			}
			case 'k':
			case 'K': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::K);
				break;
			}
			case 'l':
			case 'L': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::L);
				break;
			}
			case 'm':
			case 'M': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::M);
				break;
			}
			case 'n':
			case 'N': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::N);
				break;
			}
			case 'o':
			case 'O': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::O);
				break;
			}
			case 'p':
			case 'P': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::P);
				break;
			}
			case 'q':
			case 'Q': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::Q);
				break;
			}
			case 'r':
			case 'R': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::R);
				break;
			}
			case 's':
			case 'S': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::S);
				break;
			}
			case 't':
			case 'T': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::T);
				break;
			}
			case 'u':
			case 'U': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::U);
				break;
			}
			case 'v':
			case 'V': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::V);
				break;
			}
			case 'w':
			case 'W': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::W);
				break;
			}
			case 'x':
			case 'X': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::X);
				break;
			}
			case 'y':
			case 'Y': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::Y);
				break;
			}
			case 'z':
			case 'Z': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::Z);
				break;
			}
			case '0': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::ZERO);
				break;
			}
			case '1': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::ONE);
				break;
			}
			case '2': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::TWO);
				break;
			}
			case '3': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::THREE);
				break;
			}
			case '4': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::FOUR);
				break;
			}
			case '5': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::FIVE);
				break;
			}
			case '6': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::SIX);
				break;
			}
			case '7': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::SEVEN);
				break;
			}
			case '8': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::EIGHT);
				break;
			}
			case '9': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::NINE);
				break;
			}
			case ' ': {
				letters.push_back(new TextMesh());
				letters[letters.size() - 1]->createMesh(Letter::SPACE);
				break;
			}
		}
	}
}
