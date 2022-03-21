#pragma once
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ShaderManager.h"
#include "Color.h"

class Line
{
	/*
	Draw simple line
	Line line();
	line.SetDrawer(simpleLineDrawer);
	line.AddPoints(points);
	line.AddInsert(point,4);
	line.RemovePoints(2,6);
	line.ChangePoints(2,point);
	line.ChangePoints(2,points);
	line.SetColor(color);
	line.SetWidth(0.3);
	line.Draw();

	==============================
	line.SetDrawer(bezierLineDrawer);
	line.Draw();
	line.SetDrawer(emptyLineDrawer);
	line.Draw();
	line.SetDrawer(thinLineDrawer);
	line.Draw();
	*/
public:
	Line(glm::vec3 color, std::vector<glm::vec2>points)
	{

	}
	~Line() 
	{

	}

	void Draw()
	{

	}

	const glm::vec2* GetPoint(int ind)
	{
		return nullptr;
	}
	void ChangePoint(int ind, glm::vec2 point)
	{

	}
	void AddPoint(int ind, glm::vec2 point)
	{

	}

private:

};