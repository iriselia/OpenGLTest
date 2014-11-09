#include "TranslateAnimation3D.h"
#include "Path.h"

TranslateAnimation3D::~TranslateAnimation3D()
{

}

TranslateAnimation3D::TranslateAnimation3D(Path* _pPath)
{
	m_pPath = _pPath;
}

glm::vec3 TranslateAnimation3D::Update(float _dt)
{
	m_currentTime += _dt;

	if (m_currentTime > m_duration)
	{
		//m_currentTime = m_duration;
		m_currentTime = fmod(m_currentTime, m_duration);
	}
	glm::vec3 result = m_pPath->getVal(m_currentTime / m_duration);
	return result;
}

