#include "Main.h"

int main()
{
#if WINDOWS
	FreeConsole();
#endif // WINDOWS

	// Graphics setup
	if (!glfwInit())
		return -1;

	GLFWwindow *window = glfwCreateWindow(720, 480, "Hello World!", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	// Audio setup
	ALCdevice *audioDevice = alcOpenDevice(NULL);
	if (!audioDevice)
	{
		glfwTerminate();
		return -1;
	}

	ALCcontext *audioContext = alcCreateContext(audioDevice, NULL);
	if (!audioContext)
	{
		alcCloseDevice(audioDevice);
		glfwTerminate();
		return -1;
	}

	if (!alcMakeContextCurrent(audioContext))
	{
		alcMakeContextCurrent(NULL);
		alcDestroyContext(audioContext);
		alcCloseDevice(audioDevice);
	}


	// Main loop
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	// Audio cleanup
	alcMakeContextCurrent(NULL);
	alcDestroyContext(audioContext);
	alcCloseDevice(audioDevice);

	// Graphics cleanup
	glfwTerminate();

	// Done
	return 0;
}
