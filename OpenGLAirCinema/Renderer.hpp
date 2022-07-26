//
//  Renderer.hpp
//  OpenGLAirCinema
//
//  Created by Umut Ercan on 8.07.2022.
//

#ifndef Renderer_hpp
#define Renderer_hpp
#include <glad/glad.h>
#include<cassert>
#if DEBUG

#define GLCall(x) GLClearError();\
x;\
assert(GLLogCall())
#else
#define GLCall(x) x;
#endif

void GLClearError();
bool GLLogCall();
#endif /* Renderer_hpp */
