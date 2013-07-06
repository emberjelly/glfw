#include "Main.h"

int main()
{
#if WINDOWS
	FreeConsole();
#endif // WINDOWS

	if (!glfwInit())
		return -1;

	GLFWwindow *window = glfwCreateWindow(720, 480, "Hello World!", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
