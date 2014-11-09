#pragma once
#include "glm/vec3.hpp"
class Path;

class TranslateAnimation3D
{
public:
	TranslateAnimation3D(Path* _pPath);
	~TranslateAnimation3D();

	void SetDuration(float _time)
	{
		m_duration = _time;
	}

	void Start()
	{
		m_bIsPlaying = true;
		m_currentTime = 0.0f;
	}

	glm::vec3 Update(float _dt);
private:
	bool m_bIsPlaying;
	float m_duration;
	float m_currentTime;

	Path* m_pPath;
};