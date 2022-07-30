//
//  main.cpp
//  OpenGLAirCinema
//
//  Created by Umut Ercan on 11.06.2022.
//

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"Shader.hpp"
#include"WindowManager.hpp"
#include "CameraClass.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include"stb_img.h"

#include"Renderer.hpp"

#include"VertexBuffer.hpp"
#include"IndexBuffer.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_NAME "OGL Work Version 0.1"

#define VIEW_PORT_WIDTH 800
#define VIEW_PORT_HEIGHT 800

#define ROTATION_SCALE 0.1f




void loadTexture(unsigned int& texture, const char* dir, GLint colorDim){
    
    GLCall(glGenTextures(1,&texture));
    GLCall(glBindTexture(GL_TEXTURE_2D, texture));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_CLAMP_TO_BORDER));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_CLAMP_TO_BORDER));
    //GLCall(glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_COLOR));
   // GLCall(glEnable(GL_BLEND));

    int texWidth, texHeight, texNrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* texImg = stbi_load(dir, &texWidth, &texHeight, &texNrChannels, 0);

    
    if (texImg) {
        glTexImage2D(GL_TEXTURE_2D, 0, colorDim, texWidth, texHeight, 0, colorDim, GL_UNSIGNED_BYTE, texImg);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "ERROR::LOADING::TEXTURE::IMG" << std::endl;
    }

    stbi_image_free(texImg);
    GLCall(glBindTexture(GL_TEXTURE_2D,0));
    
}

/*--------------------------------------------camera------------------------------------------*/
CameraClass* camera= new CameraClass();

void processInput(GLFWwindow *window,const float deltaTime)
{
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera->ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera->ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera->ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera->ProcessKeyboard(RIGHT, deltaTime);
}


int main() {

    /*------------------------------------------Window------------------------------------------*/
    WindowManager* windowManager= new WindowManager(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
    
    
    gladLoadGL();

    glViewport(0,0, VIEW_PORT_WIDTH, VIEW_PORT_HEIGHT);

    /*-------------------------------------------Object------------------------------------------*/
    /*float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   0.7f, 0.0f, 0.6f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
    };*/
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    
    
//
//    unsigned int indices[] = {
//        0, 1, 3, // first triangle
//        1, 2, 3  // second triangle
//    };
    
    GLuint VAO;//buffer object

    GLCall(glGenVertexArrays(1, &VAO));
    GLCall(glBindVertexArray(VAO));
    
    VertexBuffer VBO(vertices,sizeof(vertices));
    //IndexBuffer EBO(indices,sizeof(indices)/sizeof(indices[0]));

    VBO.Bind();
    GLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0));
    GLCall(glEnableVertexAttribArray(0));
    
    //GLCall(glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(GLfloat),(void*)(3*sizeof(GLfloat))));
    //GLCall(glEnableVertexAttribArray(1));

    /*-------------------------------------------Texture-----------------------------------------*/
    
    unsigned int texture1,texture2;
    //glGenTextures(1, &texture);
    
    loadTexture(texture1, "/Users/umutercan/Desktop/OpenGLAirCinema/OpenGLAirCinema/widgets/asfalt_texture.jpeg",GL_RGB);
    loadTexture(texture2, "/Users/umutercan/Desktop/OpenGLAirCinema/OpenGLAirCinema/widgets/frame.png",GL_RGBA);
    
    //call the load texture function

    GLCall(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat))));
    GLCall(glEnableVertexAttribArray(1));

    /*--------------------------------------------Shaders------------------------------------------*/

    Shader* myShaders = new Shader("/Users/umutercan/Desktop/OpenGLAirCinema/OpenGLAirCinema/vertexShader.vs", "/Users/umutercan/Desktop/OpenGLAirCinema/OpenGLAirCinema/fragmentShader.fs");
    
    
    /*--------------------------------------------camera------------------------------------------*/
    
    float lastFrame=0.0f,deltaTime;
    uint32_t rotateDegree=0;
    
    /*--------------------------------------------Render-------------------------------------------*/
    while (!windowManager->WindowShouldClose()) {
        
        GLCall(glClearColor(0.2f, 0.3f, 0.3f, 1.0f));
        GLCall(glEnable(GL_DEPTH_TEST));
        GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
        
        myShaders->use();
        
        //model
        glm::mat4 model=glm::mat4(1.0f);
        model = glm::rotate(model,glm::radians(rotateDegree*ROTATION_SCALE),glm::vec3(1.0f,1.0f,1.0f));
        unsigned int modelLoc = glGetUniformLocation(myShaders->ID,"model");
        rotateDegree++;
        GLCall(glUniformMatrix4fv(modelLoc,1,GL_FALSE,glm::value_ptr(model)));
        
        //view
        glm::mat4 view=glm::mat4(1);
        view= camera->GetViewMatrix();
        unsigned int viewLoc= glGetUniformLocation(myShaders->ID,"view");
        GLCall(glUniformMatrix4fv(viewLoc,1,GL_FALSE, glm::value_ptr(view)));
        
        //proj
        glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)windowManager->windowWidth/(float)windowManager->windowHeight , 0.1f, 100.0f);
        unsigned int projLoc= glGetUniformLocation(myShaders->ID,"proj");
        GLCall(glUniformMatrix4fv(projLoc,1,GL_FALSE,glm::value_ptr(proj)));
        
        GLCall(glUniform1i(glGetUniformLocation(myShaders->ID, "texImg1"), 0));
        GLCall(glActiveTexture(GL_TEXTURE0));
        GLCall(glBindTexture(GL_TEXTURE_2D, texture1));
       
        GLCall(glUniform1i(glGetUniformLocation(myShaders->ID, "texImg2"), 1));
        GLCall(glActiveTexture(GL_TEXTURE1));
        GLCall(glBindTexture(GL_TEXTURE_2D, texture2));
        
        GLCall(glBindVertexArray(VAO));
        
        GLCall(glDrawArrays(GL_TRIANGLES,0,36));
        windowManager->SwapBuffers();
        windowManager->PollEvents();
        
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        processInput(windowManager->window,deltaTime);
        
    }

    glDeleteVertexArrays(1, &VAO);
    return 0;
}
