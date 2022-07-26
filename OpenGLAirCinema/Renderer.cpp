//
//  Renderer.cpp
//  OpenGLAirCinema
//
//  Created by Umut Ercan on 8.07.2022.
//

#include "Renderer.hpp"
#include <glad/glad.h>
#include <iostream>

void GLClearError(){
    
    while(glGetError()!=GL_NO_ERROR);
    
}

bool GLLogCall(){
    
    
    while(GLenum error= glGetError()){
        
        std::cout<<"GL::ERROR::CODE("<<error<<")"<<std::endl;
        return false;
    }
    return true;
}






