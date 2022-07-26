//
//  WindowManager.cpp
//  OpenGLAirCinema
//
//  Created by Umut Ercan on 11.06.2022.
//
#include "WindowManager.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    
    glViewport(0, 0, width, height);
    
}

WindowManager::WindowManager()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->windowWidth = DEFAULT_WINDOW_WIDTH;
    this->windowHeight = DEFAULT_WINDOW_HEIGHT;
    this->windowTitle = DEFAULT_WINDOW_TITLE;

    this->CreateWindow();
    
    if (this->window == NULL) {

        std::cout << "Failed creating window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(this->window);

}
//TODO: Fix the title assignement problem due to char* and string confusion
WindowManager::WindowManager(uint16_t width, uint16_t height, std::string title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->windowWidth = width;
    this->windowHeight = height;
    this->windowTitle = title;

    this->CreateWindow();

    if (this->window == NULL) {

        std::cout << "Failed creating window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);
}
WindowManager::~WindowManager()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

void WindowManager::CreateWindow()
{
    this->window = glfwCreateWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str(), NULL, NULL);
}

void WindowManager::CreateWindow(uint16_t width, uint16_t height, std::string title)
{
    this->windowWidth = width;
    this->windowHeight = height;
    this->windowTitle = title;

    this->window = glfwCreateWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str(), NULL, NULL);
}

int WindowManager::WindowShouldClose()
{
    return glfwWindowShouldClose(this->window);
}

void WindowManager::PollEvents()
{
     glfwPollEvents();
}

void WindowManager::SwapBuffers()
{
    glfwSwapBuffers(this->window);
}

void WindowManager::DestroyWindow()
{
    glfwDestroyWindow(this->window);
}

