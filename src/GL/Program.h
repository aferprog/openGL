#pragma once
#include "gg.h"
#include <string>

namespace GL {
	class Program {
	private:
		GLuint mProgram;
		GLuint mVertexShader;
		GLuint mFragmentShader;
		GLuint loadShader(const std::string &name, GLenum shaderType);
	public:
		Program(const std::string &name);
		void link();
		void use();
		void bindAttribute(GLuint index, const std::string& name);
		~Program();
	};
};