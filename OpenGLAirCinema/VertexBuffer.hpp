//
//  VertexBuffer.hpp
//  OpenGLAirCinema
//
//  Created by Umut Ercan on 8.07.2022.
//

#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp


class VertexBuffer{
private:
    unsigned int m_RendererId;
public:
    VertexBuffer(const void* data,unsigned int size);
    ~VertexBuffer();
    
    void Bind() const;
    void Unbind() const;

};

#endif /* VertexBuffer_hpp */
