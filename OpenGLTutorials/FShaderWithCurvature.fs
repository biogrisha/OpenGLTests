#version 330 core
out vec4 FragColor;


vec3 fVect3 = vec3(0.0,0.0,1.0);
vec3 Vect3_1 = vec3(-1.0,-1.0,1.0);
vec3 fVect3_2 = vec3(-0.4,-0.6,1.0);

mat3 aMat3_1 = mat3(1.0, 0.0, 0.0,  // 1. column
                  0.0, 1.0, 0.0,  // 2. column
                  0.0, 0.0, 1.0); // 3. column

mat3 aMat3_2 = mat3(1.0, 0.0, 0.0,  // 1. column
                    0.0, 1.0, 0.0,  // 2. column
                    -1.0,-1.0,1.0); // 3. column

void main()
{

    aMat3_1[0][0] = 0.0025;
    aMat3_1[1][1] = 0.0033333;


    fVect3.x = gl_FragCoord.x;
    fVect3.y = gl_FragCoord.y;

    fVect3 = aMat3_2 * aMat3_1 * fVect3;
    
    fVect3 = fVect3 + fVect3_2;
    fVect3.x = fVect3.x*10;
    fVect3.y = fVect3.y*10;

    if((fVect3.y *fVect3.y)+(fVect3.x *fVect3.x)<1)
    {
        FragColor = vec4(0.0f, 0.5f, 0.2f, 1.0f);
    }
    else
    {
    discard;
    }

}