#version 330 core
layout (location = 0) in vec3 aPos;

flat out VS_OUT {
    vec3 pos;
} vs_out;

void main()
{
    vs_out.pos = aPos;
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0); 
}  