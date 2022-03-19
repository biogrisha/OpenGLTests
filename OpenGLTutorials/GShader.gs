#version 330 core
layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

flat in VS_OUT {
     vec3 pos;
} gs_in[];


out vec3 primeVer;
out vec3 Ver1;
out vec3 Ver2;


void main() {  
    
    primeVer = gs_in[0].pos;
    Ver1 = gs_in[1].pos;
    Ver2 = gs_in[2].pos;

    gl_Position = gl_in[0].gl_Position; 
    EmitVertex();
    gl_Position = gl_in[1].gl_Position; 
    EmitVertex();
    gl_Position = gl_in[2].gl_Position; 
    EmitVertex();
    EndPrimitive();

}