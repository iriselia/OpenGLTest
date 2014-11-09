#pragma once
#include <vector>
#include "glm/vec3.hpp"
#include "CatmullRomPath3D.h"

class TranslateAnimation3D;

class AnimationFactory
{
public:
	AnimationFactory();
	~AnimationFactory();

	int readFile(const char* _fileNmae);

	TranslateAnimation3D* createCatmullRomAnim3D();

private:


	int m_nSplines = 0;
	int m_nControlPts = 0;
	float m_duration = 0.0f;

	std::vector<glm::vec3> m_splinePos;
	std::vector<glm::vec3> m_splineRot;

};