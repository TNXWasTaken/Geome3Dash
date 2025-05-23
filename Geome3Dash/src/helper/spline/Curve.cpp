#include "pch.h"
#include "Curve.h"

namespace g3d
{
	Curve::Curve(glm::vec3 p1, glm::vec3 m1, glm::vec3 m2, glm::vec3 p2) : p1(p1), m1(m1), m2(m2), p2(p2) {};

	float Curve::length(int steps) {
		float length = 0.f;
		glm::vec3 prevPoint = get(0.0f);
		for (int i = 1; i <= steps; i++) {
			float t = i / float(steps);
			glm::vec3 currentPoint = get(t);
			length += glm::length(currentPoint - prevPoint);
			prevPoint = currentPoint;
		}
		return length;
	}

	glm::vec3 Curve::get(float t) {
		auto a = lerp(p1, m1, t);
		auto b = lerp(m1, m2, t);
		auto c = lerp(m2, p2, t);
		auto d = lerp(a, b, t);
		auto e = lerp(b, c, t);
		auto P = lerp(d, e, t);
		return P;
	}

	glm::vec3 Curve::lerp(glm::vec3 p0, glm::vec3 p1, float t) {
		return glm::vec3(std::lerp(p0.x, p1.x, t), std::lerp(p0.y, p1.y, t), std::lerp(p0.z, p1.z, t));
	}

	glm::vec3 Curve::tangent(float t) {
		float delta = 1e-4f;
		glm::vec3 p0 = get(std::max(0.0f, t - delta));
		glm::vec3 p1 = get(std::min(1.0f, t + delta));
		return glm::normalize(p1 - p0);
	}

	glm::vec3 Curve::normal(float t) {
		glm::vec3 tangentVec = tangent(t);

		auto angle = std::lerp(p1NormalAngle, p2NormalAngle, t);

		glm::vec3 binormal = glm::normalize(glm::cross(tangentVec, glm::vec3(0.0f, 1.0f, 0.0f)));

		if (glm::length(binormal) < 1e-6f) {
			binormal = glm::normalize(glm::cross(tangentVec, glm::vec3(1.0f, 0.0f, 0.0f)));
		}

		glm::vec3 baseNormal = glm::normalize(glm::cross(binormal, tangentVec));

		return glm::rotate(baseNormal, angle, tangentVec);
	}

	float Curve::closestParameter(glm::vec3 point, int steps) {
		float minDistance = std::numeric_limits<float>::max();
		float closestT = 0.0f;
		for (int i = 0; i <= steps; ++i) {
			float t = i / float(steps);
			float distance = glm::length(get(t) - point);
			if (distance < minDistance) {
				minDistance = distance;
				closestT = t;
			}
		}
		return closestT;
	}
}