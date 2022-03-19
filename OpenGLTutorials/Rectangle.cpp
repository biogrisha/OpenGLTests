#include "Rectangle.h"

Rectangle::Rectangle(float width, float height, glm::vec3 Pos, float rounding, const Shader* shader) : shader {shader},Pos {Pos}
{
    float halfWidth = width / 2;
    float halfHeight = height / 2;
    float xRounding = halfWidth - rounding;
    float yRounding = halfHeight - rounding;
	vertices = {
        //x    y     z
        // first triangle
        -halfWidth, halfHeight, 1.0f,      // top left
        -halfWidth, yRounding, 1.0f,     // bottom left
        -xRounding, halfHeight, 1.0f,       // top right
        // second triangle
         halfWidth,  halfHeight, 1.0f,     // top right
         halfWidth,  yRounding, 1.0f,      // bottom right
         xRounding,  halfHeight, 1.0f,      // top left 
        // second triangle
        -halfWidth, -halfHeight, 1.0f,  // bottom left
        -halfWidth, -yRounding, 1.0f,   // top left
        -xRounding, -halfHeight, 1.0f,  // bottom right
        // fourth triangle
        halfWidth, -halfHeight, 1.0f,  // bottom right
        halfWidth, -yRounding, 1.0f,   // top right
        xRounding, -halfHeight, 1.0f,  // bottom left
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* vertices.size(), &vertices[0], GL_STATIC_DRAW);

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
    shader->setVec3("transform", Pos);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    glBindVertexArray(0);
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
