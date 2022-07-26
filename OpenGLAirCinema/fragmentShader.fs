#version 330 core
in vec2 texCoord;
//in vec3 ourColor;

uniform sampler2D texImg1;
uniform sampler2D texImg2;

out vec4 FragColor;
void main()
{
    FragColor = mix(texture(texImg1,texCoord),texture(texImg2,texCoord),0.5);//*vec4(ourColor,1.0f);
}
