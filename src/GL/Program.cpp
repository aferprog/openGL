#include "Program.h"
#include <iostream>
#include <iterator>
#include <fstream>

GL::Program::Program(const std::string &name) {
	mProgram = glCreateProgram();
	mVertexShader = loadShader("res/glsl/"+name+".vert",GL_VERTEX_SHADER);
	mFragmentShader = loadShader("res/glsl/" + name + ".frag", GL_FRAGMENT_SHADER);
}
GL::Program::~Program() {
	glDetachShader(mProgram, mVertexShader);
	glDetachShader(mProgram, mFragmentShader);
	glDeleteShader(mFragmentShader);
	glDeleteShader(mVertexShader);
	glDeleteProgram(mProgram);
}


void GL::Program::link() {
	glAttachShader(mProgram, mVertexShader);
	glAttachShader(mProgram, mFragmentShader);
	glLinkProgram(mProgram);
}

void GL::Program::use() {
	glUseProgram(mProgram);
}

void GL::Program::bindAttribute(GLuint index, const std::string &name) {
	glBindAttribLocation(mProgram, index, name.c_str());
}

GLuint GL::Program::loadShader(const std::string &path, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);
	std::ifstream fis(path);
	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>() };
	const char *c = shaderCode.c_str();
	glShaderSource(shader, 1, &c, nullptr);
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	GLsizei len;
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);
	if (len > 0) {
		std::cout << buf << std::endl;
	}
	else std::cout << shaderCode<<"\n\n\n";
	return shader;
}