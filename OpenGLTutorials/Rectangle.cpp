#include "Rectangle.h"

Rectangle::Rectangle(float width, float height, glm::vec3 Pos, float rounding) :Pos {Pos}
{

    shader = ShaderManager::getInstance()->GetProgram("RoundRect");
    float halfWidth = width / 2;
    float halfHeight = height / 2;
    float xRounding = halfWidth - rounding;
    float yRounding = halfHeight - rounding;
	vertices = {
        //x    y     z
        // first triangle
        -halfWidth, halfHeight, 1.0f,      // 0 top left
        -halfWidth, yRounding, 1.0f,       // 1 bottom left   1 
        -xRounding, halfHeight, 1.0f,      // 2 top right  3
        // second triangle
         halfWidth,  halfHeight, 1.0f,     // 3 top right
         halfWidth,  yRounding, 1.0f,      // 4 bottom right 7
         xRounding,  halfHeight, 1.0f,     // 5 top left 5
        // second triangle
        -halfWidth, -halfHeight, 1.0f,     // 6 bottom left
        -halfWidth, -yRounding, 1.0f,      // 7 top left    2
        -xRounding, -halfHeight, 1.0f,     // 8 bottom right 4
        // fourth triangle
        halfWidth, -halfHeight, 1.0f,      // 9 bottom right
        halfWidth, -yRounding, 1.0f,       // 10 top right 8
        xRounding, -halfHeight, 1.0f,      // 11 bottom left 6
    };

    indices = { 1,7,2,8,5,11,4,10 };
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
    shader->setVec3("transform", Pos);
    shader->setInt("mode", 1);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    shader->setInt("mode", 2);
    glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_INT, 0);
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
