//
//  IndexBuffer.cpp
//  OpenGLAirCinema
//
//  Created by Umut Ercan on 8.07.2022.
//

#include "IndexBuffer.hpp"
#include "Renderer.hpp"

IndexBuffer::IndexBuffer(const void* data,unsigned int count)
    : m_Count(count)
{
    
    GLCall(glGenBuffers(1,&m_RendererId));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererId));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER,count*sizeof(unsigned int),data,GL_STATIC_DRAW));
    
}

IndexBuffer::~IndexBuffer(){

    GLCall(glDeleteBuffers(1,&m_RendererId));
    
}

void IndexBuffer::Bind() const{
     
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_RendererId));
    
    
}
void IndexBuffer::Unbind() const{
    
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0));

}
