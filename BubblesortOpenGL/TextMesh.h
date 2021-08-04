#pragma once

#include "Mesh.h"

enum Letter {
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,

	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,

	SPACE
};

struct UV {
	float u;
	float v;
};

class TextMesh : public Mesh
{
public:
	TextMesh();
	~TextMesh();

	void createMesh(Letter letter);

private:
	unsigned int numOfVertices = 20;
	unsigned int numOfIndices = 6;

	unsigned int indices[6] = {
		1, 2, 0,
		1, 2, 3
	};

	UV letterPositions[37]{
		UV{1.0f, 3.5f},
		UV{2.0f, 3.5f},
		UV{3.0f, 3.5f},
		UV{4.0f, 3.5f},
		UV{5.0f, 3.5f},
		UV{6.0f, 3.5f},
		UV{7.0f, 3.5f},

		UV{0.0f, 2.5f},
		UV{1.0f, 2.5f},
		UV{2.0f, 2.5f},
		UV{3.0f, 2.5f},
		UV{4.0f, 2.5f},
		UV{5.0f, 2.5f},
		UV{6.0f, 2.5f},
		UV{7.0f, 2.5f},

		UV{0.0f, 1.5f},
		UV{1.0f, 1.5f},
		UV{2.0f, 1.5f},
		UV{3.0f, 1.5f},
		UV{4.0f, 1.5f},
		UV{5.0f, 1.5f},
		UV{6.0f, 1.5f},
		UV{7.0f, 1.5f},

		UV{0.0f, 0.5f},
		UV{1.0f, 0.5f},
		UV{2.0f, 0.5f},


		UV{0.0f, 5.5f},
		UV{1.0f, 5.5f},
		UV{2.0f, 5.5f},
		UV{3.0f, 5.5f},
		UV{4.0f, 5.5f},
		UV{5.0f, 5.5f},
		UV{6.0f, 5.5f},
		UV{7.0f, 5.5f},

		UV{0.0f, 4.5f},
		UV{1.0f, 4.5f},

		UV{0.0f, 7.5f}
	};

};

