#include <cmath>

#include "circle.h"

using namespace Geometry;

Circle::Circle(Vec3 center, double radius)
	: Ellipse(center, radius, radius)
{}

bool Circle::operator<(const Circle& circle) const
{
	return m_xRadius < circle.m_xRadius;
}
