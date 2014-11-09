#pragma once
#include <vector>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "Path.h"

class BSplinePath3D : public Path
{
public:
	BSplinePath3D(std::vector<glm::vec3> _inPos);
	virtual ~BSplinePath3D();

	glm::vec3 interpolate(float x, glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);

	virtual glm::vec3 getVal(float _dt);

private:

};