#include "TextMesh.h"

TextMesh::TextMesh() {
}

TextMesh::~TextMesh() {
}

void TextMesh::createMesh(Letter letter) {
	const float rowSize = 1.0f / 8.0f;

	float startX = rowSize * letterPositions[letter].u;
	float endX = startX + rowSize / 3.0f;
	float startY = rowSize * letterPositions[letter].v;
	float endY = startY + rowSize / 2.0f;

	GLfloat textVertices[] = {
		0.0f, 1.0f, 0.0f, startX, startY,
		1.0f, 1.0f, 0.0f, endX, startY,
		0.0f, 0.0f, 0.0f, startX, endY,
		1.0f, 0.0f, 0.0f, endX, endY
	};

	indexCount = numOfIndices;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * numOfIndices, indices, GL_STATIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textVertices[0]) * numOfVertices, textVertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(textVertices[0]) * 5, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(textVertices[0]) * 5, (void*)(sizeof(textVertices[0]) * 3));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}