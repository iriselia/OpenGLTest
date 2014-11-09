#include "Path.h"




Path::~Path()
{

}

Path::Path()
{

}

glm::vec3 Path::getVal(float _dt)
{
	return glm::vec3();
}

void Path::PushPoint(glm::vec3 _inVec3)
{
	m_ctrlPts.push_back(_inVec3);
}
