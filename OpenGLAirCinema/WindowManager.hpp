//
//  WindowManager.hpp
//  OpenGLAirCinema
//
//  Created by Umut Ercan on 11.06.2022.
//

#pragma once
#include<cstdint>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 800
#define DEFAULT_WINDOW_TITLE "Linuk"

class WindowManager
{
public:
    WindowManager();
    WindowManager(uint16_t width, uint16_t height, std::string title);
    ~WindowManager();
    void CreateWindow();
    void CreateWindow(uint16_t width, uint16_t height, std::string title);
    int WindowShouldClose();
    void PollEvents();
    void SwapBuffers();
    void DestroyWindow();

    uint16_t windowWidth;
    uint16_t windowHeight;
    std::string windowTitle;
private:
 
    GLFWwindow* window;

};
