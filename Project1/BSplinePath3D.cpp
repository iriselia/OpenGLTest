#include "BSplinePath3D.h"
#include <glm/vec4.hpp>

BSplinePath3D::~BSplinePath3D()
{

}

BSplinePath3D::BSplinePath3D(std::vector<glm::vec3> _inPos) : Path()
{

	for (auto i : _inPos)
	{
		PushPoint(i);
	}
}

glm::vec3 BSplinePath3D::interpolate(float x, glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3)
{
	int nCtrlPts = m_ctrlPts.size();

	int i, j;
	float a, b, c, d;

	for (i = 0; i <= nCtrlPts - 3; i++)
	{
		for (j = 0; j <= 100; j++)
		{
			float x, y, t, it;
			t = j / 100.0;
			it = 1 - t;

			a = it*it*it / 6.0f;
			b = (3 * t*t*t - 6 * t*t + 4) / 6.0f;
			c = (-3 * t*t*t + 3 * t*t + 3 * t + 1) / 6.0f;
			d = t*t*t / 6.0f;


			x = a*m_ctrlPts[i].x + b*m_ctrlPts[i + 1].x + c*m_ctrlPts[i + 2].x + d*m_ctrlPts[i + 3].x;
			y = a*m_ctrlPts[i].y + b*m_ctrlPts[i + 1].y + c*m_ctrlPts[i + 2].y + d*m_ctrlPts[i + 3].y;
		}
	}


	return glm::vec3();
}

glm::vec3 BSplinePath3D::getVal(float _dt)
{
		int nCtrlPts = m_ctrlPts.size();
		float unitTime = 1.0f / nCtrlPts;
		float x = fmod(_dt, unitTime) / unitTime;


		int idxV1 = _dt / unitTime;
		glm::vec3 v0, v1, v2, v3;
		if ((idxV1 - 1) < nCtrlPts &&
			(idxV1 - 1) >= 0)
		{
			v0 = m_ctrlPts[idxV1 - 1];
		}
		if ((idxV1) < nCtrlPts &&
			(idxV1) >= 0)
		{
			v1 = m_ctrlPts[idxV1];
		}
		if ((idxV1 + 1) < nCtrlPts &&
			(idxV1 + 1) >= 0)
		{
			v2 = m_ctrlPts[idxV1 + 1];
		}
		if ((idxV1 + 2) < nCtrlPts &&
			(idxV1 + 2) >= 0)
		{
			v3 = m_ctrlPts[idxV1 + 2];
		}

		return interpolate(x, v0, v1, v2, v3);
	}
