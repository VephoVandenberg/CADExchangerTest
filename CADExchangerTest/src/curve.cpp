#include "curve.h"

using namespace Geometry;

Curve::Curve(Vec3 center)
	: m_center(center)
{}

std::ostream& Geometry::operator<<(std::ostream& o, CurveType type)
{
	switch (type)
	{
	case Geometry::CurveType::Ellipse:
		o << "Ellipse";
		break;
	case Geometry::CurveType::Circle:
		o << "Circle";
		break;
	case Geometry::CurveType::Helix:
		o << "Helix";
		break;
	}

	return o;
}
