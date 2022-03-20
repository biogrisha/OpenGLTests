#include "Rectangle.h"

Rectangle::Rectangle(float width, float height, glm::vec3 pos, glm::vec3 color, float rounding) :m_pos {pos},m_color{color}
{

    m_shader = ShaderManager::getInstance()->GetProgram("RoundRect");
    float halfWidth = width / 2;
    float halfHeight = height / 2;
    float xRounding = halfWidth - rounding;
    float yRounding = halfHeight - rounding;
	m_vertices = {
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

    m_indices = { 1,7,2,8,5,11,4,10 };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)* m_vertices.size(), &m_vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * m_indices.size(), &m_indices[0], GL_STATIC_DRAW);

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
    m_shader->setVec3("transform", m_pos);
    m_shader->setVec3("color", m_color);
    m_shader->setInt("mode", 1);
    glDrawArrays(GL_TRIANGLES, 0, 12);
    m_shader->setInt("mode", 2);
    glDrawElements(GL_TRIANGLE_STRIP, 8, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Rectangle::SetX(float x)
{
    m_pos.x = x;
}

void Rectangle::SetY(float y)
{
    m_pos.y = y;
}

float Rectangle::GetX()
{
    return m_pos.x;
}

float Rectangle::GetY()
{
    return m_pos.y;
}
