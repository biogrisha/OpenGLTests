#pragma once
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader_s.h"
#include "Color.h"

class Rectangle
{
public:
	Rectangle(float width, float height, glm::vec3 Pos, float rounding, const Shader* shader);
	~Rectangle();
	void Draw();

	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();

private:
	std::vector<float> vertices;

	glm::vec3 Pos;

	unsigned int VBO, VAO;

	const Shader* shader;
};
