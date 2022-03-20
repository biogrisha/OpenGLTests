#version 330 core
out vec4 FragColor;
in vec3 fColor;

in vec3 primeVer;
in vec3 Ver1;
in vec3 Ver2;

vec3 fVect3 = vec3(0.0,0.0,1.0);
vec3 Vect3_1 = vec3(-1.0,-1.0,1.0);
vec3 fVect3_2 = vec3(-0.5,-0.5,1.0);

mat3 aMat3_1 = mat3(1.0, 0.0, 0.0,  // 1. column
                  0.0, 1.0, 0.0,  // 2. column
                  0.0, 0.0, 1.0); // 3. column

mat3 aMat3_2 = mat3(1.0, 0.0, 0.0,  // 1. column
                    0.0, 1.0, 0.0,  // 2. column
                    -1.0,-1.0,1.0); // 3. column

float widthCoef;
float heightCoef;
uniform int mode;
uniform vec3 color;

void main()
{
    if(mode == 1)
    {
        aMat3_1[0][0] = 0.0025;
        aMat3_1[1][1] = 0.0033333;

        fVect3.x = gl_FragCoord.x;
        fVect3.y = gl_FragCoord.y;

        fVect3 = aMat3_2 * aMat3_1 * fVect3;
    
        //triangle translation
        heightCoef = abs(primeVer.y - Ver1.y);
        widthCoef = abs(primeVer.x - Ver2.x);
        fVect3_2 = Ver1 + Ver2 - primeVer;
        fVect3_2.x = -fVect3_2.x;
        fVect3_2.y = -fVect3_2.y;

        fVect3 = fVect3 + fVect3_2;
        fVect3.x = fVect3.x*(1/widthCoef);
        fVect3.y = fVect3.y*(1/heightCoef);

        if((fVect3.y *fVect3.y)+(fVect3.x *fVect3.x)<1)
        {
            FragColor = vec4(color, 1.0f);
        }
        else
        {
        discard;
        }  
    }
    else if(mode == 2)
    {
        FragColor = vec4(color, 1.0f);
    }
  
}  