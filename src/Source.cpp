#include <iostream>

#include "GLFW/Window.h"
#include <GLFW/glfw3.h>
#include "GLFW/GLFW.h"

using namespace std;
int main() {
	try {
		GLFW glfw;
		Window w("Engine", 800,500);
		w.loop();
	}
	catch (const std::runtime_error& e) {
		cout << "EXCEPTION: "<<e.what()<<'\n';
	}
}