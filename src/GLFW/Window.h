#pragma once
#include <gg.h>
#include <GLFW/glfw3.h>
#include <string>
using namespace std;

class Window {
private:
	GLFWwindow* mWindow;
public:
	Window(const string &title, int width, int height);
	void setContextCurrent();
	void loop();
	~Window();
};

