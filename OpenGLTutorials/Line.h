#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ShaderManager.h"
#include "Color.h"

class Line
{
public:
	Line(float width, float height, glm::vec3 pos, glm::vec3 color, float rounding);
	~Line();
	void Draw();


	float GetX();
	float GetY();

private:
	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indices;

	glm::vec3 m_color;

	unsigned int VBO, VAO, EBO;

	const Shader* m_shader;
};