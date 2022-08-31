#include <iostream>
#include <string>
//OpenGL
#include <glad/glad.h> //Needs to be included before GLFW
#include <GLFW/glfw3.h>
//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "WindowHandler.h"
#include "fileHandler.h"
//#include "Shader.h"
//#include "Camera.h"

const int WIDTH = 1000;
const int HEIGHT = 700;
const char* WINDOW_NAME = "Summer Engine";

const char* VERTEX_SHADER_PATH = "Shaders/vertex_shader.vert";
const char* FRAGMENT_SHADER_PATH = "Shaders/fragment_shader.frag";
const char* CONTAINER_IMAGE_PATH = "Images/LearnOpenGL/container.jpg";
const char* AWESOMEFACE_IMAGE_PATH = "Images/LearnOpenGL/awesomeface.png";

void frame_buffer_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() {
	WindowHandler windowH(WIDTH, HEIGHT, WINDOW_NAME);

	int result = windowH.init();
	if (result == -1) //If there was an error when creating the window exit the application
	{
		return -1;
	}

	//GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR :: Unable to initialize GLAD";
		return -1;
	}

	glViewport(0, 0, windowH.getHeight(), windowH.getWidth());
	glfwSetFramebufferSizeCallback(windowH.getWindow(), frame_buffer_callback);

	while (!glfwWindowShouldClose(windowH.getWindow()))
	{
		processInput(windowH.getWindow());

		glfwSwapBuffers(windowH.getWindow());
		glfwPollEvents();
	}


	glfwTerminate();

	return 0;
}

void processInput(GLFWwindow * window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

void frame_buffer_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}