#pragma once
#include <vector>
#include "shader_s.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class LineDrawer
{
public:
	LineDrawer() = default;
	LineDrawer(const LineDrawer&) = delete;
	LineDrawer& operator=(const LineDrawer&) = delete;
public:

	virtual void Draw() = 0;
	virtual void Initialize(const glm::vec2& point) = 0;
	virtual void Clear(const glm::vec2& point) = 0;

	virtual void GetPoints(int pos, glm::vec2& points)const = 0;
	virtual void GetPoints(int posStart,int posEnd, glm::vec2& points)const = 0;

	virtual void AddPoints(const std::vector<glm::vec2> & points) = 0;
	virtual void AddPoints(const glm::vec2& point) = 0;

	virtual void InsertPoints(int pos, const glm::vec2& point) = 0;
	virtual void InsertPoints(int pos, const std::vector<glm::vec2>& points) = 0;

	virtual void ChangePoints(int pos, const std::vector<glm::vec2>& points) = 0;
	virtual void ChangePoints(int pos, const glm::vec2& point) = 0;

	virtual void SetColor(const glm::vec3& point) = 0;


private:
	Shader* shaderProgram = nullptr;

	std::vector<float> m_vertices;

	unsigned int VBO, VAO;
};
