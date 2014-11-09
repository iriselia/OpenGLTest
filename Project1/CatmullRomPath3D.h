#pragma once
#include <vector>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "Path.h"

class CatmullRomPath3D : public Path
{
public:
	CatmullRomPath3D(std::vector<glm::vec3> _inPos);
	virtual ~CatmullRomPath3D();

	void SetTension(float _tension);

	glm::vec3 interpolate(float x, glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);

	virtual glm::vec3 getVal(float _dt);

private:
	float m_tension;
	glm::mat4x4 m_matrix;
};