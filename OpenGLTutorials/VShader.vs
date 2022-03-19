#version 330 core
layout (location = 0) in vec3 aPos;

flat out VS_OUT {
    vec3 pos;
} vs_out;

uniform vec3 transform;
void main()
{
    vs_out.pos = aPos + transform;
    gl_Position = vec4(aPos + transform, 1.0); 
}  