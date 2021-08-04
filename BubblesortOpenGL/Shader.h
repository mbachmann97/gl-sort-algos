#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>

class Shader{
public:
	Shader();
	~Shader();

	void createFromString(const char* vertexCode, const char* fragmentCode);
	void createFromFiles(const char* vertexLocation, const char* fragmentLocation);

	std::string readFile(const char* fileLocation);

	GLuint getProjectionLocation();
	GLuint getModelLocation();
	
	GLuint getColorLocation();
	GLuint getColorWeigthLocation();

	void useShader();
	void clearShader();

	GLuint getShaderID();

private:
	GLuint shaderID, uniformProjection, uniformModel, uniformColor, uniformColorWeigth;

	void compileShader(const char* vertexCode, const char* fragmentCode);
	void addShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
};

