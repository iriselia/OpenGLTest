#pragma once
#include <vector>
#include "glm/vec3.hpp"

class Path
{
public:
	Path();
	virtual ~Path();

	virtual glm::vec3 getVal(float _dt);

	void PushPoint(glm::vec3 _inVec3);

protected:
	std::vector<glm::vec3> m_ctrlPts;

};