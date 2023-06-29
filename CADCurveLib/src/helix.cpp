#define _USE_MATH_DEFINES

#include <cmath>

#include "helix.h"

using namespace Geometry;

Helix::Helix(Vec3 center, double radius, double step)
	: Curve(center)
	, m_radius(radius)
	, m_step(step)
{}

Vec3 Helix::getPoint(double t) const
{
	return {
		m_center.x + m_radius * std::cos(t),
		m_center.y + m_radius * std::sin(t),
		m_step * t / (2 * M_PI)
	};
}

Vec3 Helix::getDerivative(double t) const
{
	return {
		m_radius * -std::sin(t),
		m_radius * std::cos(t),
		m_step / (2 * M_PI)
	};
}
