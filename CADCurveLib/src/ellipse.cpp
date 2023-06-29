#include <cmath>

#include "ellipse.h"

using namespace Geometry;

Ellipse::Ellipse(Vec3 center, double a, double b)
	: Curve(center)
	, m_xRadius(a)
	, m_yRadius(b)
{}

Vec3 Ellipse::getPoint(double t) const
{
	return {
		m_center.x + m_xRadius * std::cos(t),
		m_center.y + m_yRadius * std::sin(t),
		0.0f
	};
}

Vec3 Ellipse::getDerivative(double t) const
{
	return {
		m_xRadius * -std::sin(t),
		m_yRadius * std::cos(t),
		0.0f
	};
}
