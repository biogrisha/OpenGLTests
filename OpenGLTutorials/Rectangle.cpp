#include "Rectangle.h"

Rectangle::Rectangle(float width, float height, glm::vec3 Pos, float rounding) :Pos {Pos}
{

    shManager = ShaderManager::getInstance();
    float halfWidth = width / 2;
    float halfHeight = height / 2;
    float xRounding = halfWidth - rounding;
    float yRounding = halfHeight - rounding;
	vertices = {
        //x    y     z
        // first triangle
        -halfWidth, halfHeight, 1.0f,      // 1 top left
        -halfWidth, yRounding, 1.0f,       // 2 bottom left   1 
        -xRounding, halfHeight, 1.0f,      // 3 top right  3
        // second triangle
         halfWidth,  halfHeight, 1.0f,     // 4 top right
         halfWidth,  yRounding, 1.0f,      // 5 bottom right 7
         xRounding,  halfHeight, 1.0f,     // 6 top left 5
        // second triangle
        -halfWidth, -halfHeight, 1.0f,     // 7 bottom left
        -halfWidth, -yRounding, 1.0f,      // 8 top left    2
        -xRounding, -halfHeight, 1.0f,     // 9 bottom right 4
        // fourth triangle
        halfWidth, -halfHeight, 1.0f,      // 10 bottom right
        halfWidth, -yRounding, 1.0f,       // 11 top right 8
        xRounding, -halfHeight, 1.0f,      // 12 bottom left 6
    };

    indices = { 2, 8, 3, 9, 6, 12, 5, 11};
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);


}

Rectangle::~Rectangle()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Rectangle::Draw()
{

    glBindVertexArray(VAO);
    shManager->GetProgramm("RoundRect")->setVec3("transform", Pos);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    /*glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);*/
}

void Rectangle::SetX(float x)
{
    Pos.x = x;
}

void Rectangle::SetY(float y)
{
    Pos.y = y;
}

float Rectangle::GetX()
{
    return Pos.x;
}

float Rectangle::GetY()
{
    return Pos.y;
}
