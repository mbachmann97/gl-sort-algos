#define STB_IMAGE_IMPLEMENTATION

#include <stdio.h>
#include <vector>
#include <ctime> 

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"
#include "Mesh.h"
#include "TextMesh.h"
#include "Shader.h"
#include "Texture.h"
#include "TextLine.h"

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<TextMesh*> helloWorld;
std::vector<Shader> shaderList;

TextLine line1;
TextLine line2;
TextLine line3;

Shader shaderBar;
Shader shaderText;

Texture brickTexture;
Texture consolasTexture;

int activeIndex = 0;

// Vertex Shader
static const char* vShader = "Shaders/shader.vert";
static const char* vTextShader = "Shaders/textShader.vert";

// Fragment Shader
static const char* fShader = "Shaders/shader.frag";
static const char* fTextShader = "Shaders/textShader.frag";

void createObjects() {
	unsigned int indices[] = {
		1, 2, 0,
		1, 2, 3
	};

	GLfloat vertices[] = {
		0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
	};

	//Lfloat textVertices[] = {
	//	0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
	//	1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
	//	0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	//	1.0f, 0.0f, 0.0f, 1.0f, 1.0f
	//;

	const float rowSize = 1.0f / 8.0f;

	float startX = rowSize * 5.0f;
	float endX = startX + rowSize / 3.0f;
	float startY = rowSize * 2.5f;
	float endY = startY + rowSize / 2.0f;

	GLfloat textVertices[] = {
		0.0f, 1.0f, 0.0f, startX, startY,
		1.0f, 1.0f, 0.0f, endX, startY,
		0.0f, 0.0f, 0.0f, startX, endY,
		1.0f, 0.0f, 0.0f, endX, endY
	};

	Mesh *obj1 = new Mesh();
	obj1->createMesh(vertices, indices, 12, 6);
	meshList.push_back(obj1);

	line1.genFromString("active index");
	line2.genFromString("array accesses");
	line3.genFromString("comparisons");
}

void createShaders() {
	Shader *shader1 = new Shader();
	shader1->createFromFiles(vShader, fShader);
	shaderBar = *shader1;

	Shader *shader2 = new Shader();
	shader2->createFromFiles(vTextShader, fTextShader);
	shaderText = *shader2;
}

int main() {
	const int ITEM_COUNT = 2048;

	mainWindow = Window(1900, 1000);
	mainWindow.initialize();

	createObjects();
	createShaders();

	// brickTexture = Texture("Textures/brick.png");
	// brickTexture.loadTexture();

	consolasTexture = Texture("Textures/consolas.bmp", TextureFormat::BMP);
	consolasTexture.loadTexture();

	GLuint uniformProjection = 0, uniformModel = 0, uniformColorWeigth; // uniformColor = 0;

	glm::mat4 projection = glm::ortho(0.0f, 100.0f, 100.0f, 0.0f, 0.1f, 100.0f);

	srand((unsigned)time(0));
	float randArray[ITEM_COUNT];
	for (int i = 0; i < ITEM_COUNT; i++) {
		randArray[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 100));
	}

	const float relWidth = 1000.0f / mainWindow.getBufferWidth();
	const float relHeight = 1000.0f / mainWindow.getBufferHeight();

	const float xPixel = 100.0f / mainWindow.getBufferWidth();
	const float yPixel = 100.0f / mainWindow.getBufferHeight();

	// VARS Bubblesort
	//int index = 1;
	//int swapCount = 99;
	//bool sorted = false;
	//int tempItemCount = ITEM_COUNT;

	// VARS Selectionsort
	int index = 0;
	int minPos = 0;
	int arrAccess = 0;
	int comparisons = 0;

	while (!mainWindow.getShouldClose()) {
		// Handle User Input
		glfwPollEvents();

		// Clear Window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shaderText.useShader();
		uniformModel = shaderText.getModelLocation();
		uniformProjection = shaderText.getProjectionLocation();
		uniformColorWeigth = shaderText.getColorWeigthLocation();

		line1.genFromString("active index " + std::to_string(index));

		for (size_t i = 0; i < line1.getLetters().size(); i++) {
			glm::mat4 model(1.0f);
			model = glm::translate(model, glm::vec3((relWidth * 3.0f) + i * (xPixel * 16.0f), (relHeight * 3.0f), -0.1f));
			model = glm::scale(model, glm::vec3(xPixel * 16.0f, yPixel * 16.0f, 1.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			glUniform1f(uniformColorWeigth, 99.0f);
			consolasTexture.useTexture();
			line1.getLetters().at(i)->renderMesh();
		}

		line2.genFromString("array accesses " + std::to_string(arrAccess));

		for (size_t i = 0; i < line2.getLetters().size(); i++) {
			glm::mat4 model(1.0f);
			model = glm::translate(model, glm::vec3((relWidth * 3.0f) + i * (xPixel * 16.0f), (relHeight * 5.0f), -0.1f));
			model = glm::scale(model, glm::vec3(xPixel * 16.0f, yPixel * 16.0f, 1.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			glUniform1f(uniformColorWeigth, 99.0f);
			consolasTexture.useTexture();
			line2.getLetters().at(i)->renderMesh();
		}

		line3.genFromString("comparisons " + std::to_string(comparisons));

		for (size_t i = 0; i < line3.getLetters().size(); i++) {
			glm::mat4 model(1.0f);
			model = glm::translate(model, glm::vec3((relWidth * 3.0f) + i * (xPixel * 16.0f), (relHeight * 7.0f), -0.1f));
			model = glm::scale(model, glm::vec3(xPixel * 16.0f, yPixel * 16.0f, 1.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			glUniform1f(uniformColorWeigth, 99.0f);
			consolasTexture.useTexture();
			line3.getLetters().at(i)->renderMesh();
		}

		shaderBar.useShader();
		uniformModel = shaderBar.getModelLocation();
		uniformProjection = shaderBar.getProjectionLocation();
		uniformColorWeigth = shaderBar.getColorWeigthLocation();

		for (size_t i = 0; i < ITEM_COUNT; i++) {
			glm::mat4 model(1.0f);
			model = glm::translate(model, glm::vec3(i * (100.0f / ITEM_COUNT), 100.0f - randArray[i], -0.1f));
			model = glm::scale(model, glm::vec3(100.0f / ITEM_COUNT, randArray[i], 1.0f));
			glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
			//if (i == index) {
			//	model = glm::scale(model, glm::vec3((100.0f / ITEM_COUNT) * 20, randArray[i], 1.0f));
			//	glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
			//	glUniform3f(uniformColor, 1.0f, 1.0f, 1.0f);
			//}
			//else {
			//	glUniform3f(uniformColor, ((float)randArray[i] / 100.0f) + 0.5f, 1.3f - ((float)randArray[i] / 100.0f), (float)randArray[i] / 100.0f);
			//}
			glUniform1f(uniformColorWeigth, (float)randArray[i]);
			meshList[0]->renderMesh();
		}
		// Bubblesort
		// #####################
	
		//if (index < tempItemCount && !sorted) {
		//	if (randArray[index] < randArray[index - 1]) {
		//		float temp = randArray[index];
		//		randArray[index] = randArray[index - 1];
		//		randArray[index - 1] = temp;
		//		index++;
		//		swapCount++;
		//	}
		//	else {
		//		index++;
		//	}
		//}
		//else {
		//	if (swapCount > 0) {
		//		index = 1;
		//		swapCount = 0;
		//		tempItemCount--;
		//	}
		//	else {
		//		sorted = true;
		//	}
		//}

		// #####################
		// Selectionsort
		// #####################

		for (size_t i = index; i < ITEM_COUNT; i++) {
			if (randArray[i] < randArray[minPos]){
				minPos = i;
				comparisons++;
			}
		}
		if (randArray[index] > randArray[minPos]) {
			float temp = randArray[index];
			randArray[index] = randArray[minPos];
			randArray[minPos] = temp;
			arrAccess += 2;
			comparisons++;
		}
		if (index < ITEM_COUNT - 1) {
			index++;
			minPos = index;
		}

		// #####################

		glUseProgram(0);

		mainWindow.swapBuffers();
	}

	return 0;
}