#pragma once
#include <gg.h>
#include <vector>

namespace GL {
	class VAO {
	private:
		GLuint mVao;
		std::vector<GLuint> mBuffers;
	public:
		VAO();
		void bind();
		void addVertexBufferObject(const std::vector<float> &data);
		void draw(GLsizei count);
		VAO(const VAO&) = delete;
		~VAO();
	};
};