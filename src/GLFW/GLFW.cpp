#include "GLFW.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

GLFW::GLFW() {
	if (!glfwInit()) {
		throw std::runtime_error("INITIALING ERROR");
	}
}
GLFW::~GLFW() {
	glfwTerminate();
}