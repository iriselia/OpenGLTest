/* Module      : spline.cpp
* Author      : Yong Piao
* Email       : ypiao@wpi.edu
* Course      : CS4732
*
* Description : Processes mouse and keyboard input
*				and generates view and projection matrices
*
* Date        : 11/6/2014
*
* History:
* Revision      Date          Changed By
* --------      ----------    ----------
* 01.00         11/6/2014		Yong Piao
* First release.
*
* (c) Copyright 2013, Worcester Polytechnic Institute.
*/

/* -- INCLUDE FILES ------------------------------------------------------ */
#include "AnimationFactory.h"
#include "CatmullRomPath3D.h"
#include "TranslateAnimation3D.h"
#include <fstream>
#include <iostream>
#include <string>

#include "glm/vec3.hpp"

/* -- DATA STRUCTURES ---------------------------------------------------- */

/* -- GLOBAL VARIABLES --------------------------------------------------- */

/* -- LOCAL VARIABLES ---------------------------------------------------- */

AnimationFactory::~AnimationFactory()
{

}

AnimationFactory::AnimationFactory()
{

}


TranslateAnimation3D* AnimationFactory::createCatmullRomAnim3D()
{
// 	if (_fileName)
// 	{
// 		if (readFile(_fileName))
// 		{
// 			return nullptr;
// 		}
// 	}

	auto pPath = new CatmullRomPath3D(m_splinePos);
	auto pAnim = new TranslateAnimation3D(pPath);

	pAnim->SetDuration(m_duration);

	return pAnim;
}

int AnimationFactory::readFile(const char* _fileNmae)
{
	std::ifstream ifs;
	std::string line;
	char ch;

	ifs.open(_fileNmae, std::ios::in);

	if (!ifs.is_open())
	{
		printf("Error opening file.\n");
		return -1;
	}

	// Start parsing file

	// Skip comments
	for (int i = 0; i < 19; i++)
	{
		std::getline(ifs, line);
	}

	// Get nSplines
	ifs >> m_nSplines;

	// Skip comments
	for (int i = 0; i < 4; i++)
	{
		std::getline(ifs, line);
	}

	// Get nSplines
	ifs >> m_nControlPts;

	// Skip comments
	for (int i = 0; i < 2; i++)
	{
		std::getline(ifs, line);
	}
	// Get duration
	ifs >> m_duration;

	// Skip comments "For Each Point:"
	for (int i = 0; i < 2; i++)
	{
		std::getline(ifs, line);
	}
	// Inject all points
	for (int i = 0; i < m_nControlPts; i++)
	{
		glm::vec3 pos;
		glm::vec3 rot;
		// Skip comments
		for (int i = 0; i < 2; i++)
		{
			std::getline(ifs, line);
		}

		ifs >> pos.x >> ch >> pos.y >> ch >> pos.z >> ch;
		std::getline(ifs, line);
		ifs >> rot.x >> ch >> rot.y >> ch >> rot.z >> ch;
		std::getline(ifs, line);

		m_splinePos.push_back(pos);
		m_splineRot.push_back(rot);
	}

	return 0;
}