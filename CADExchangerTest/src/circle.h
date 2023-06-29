#pragma once

#include "ellipse.h"

namespace Geometry
{
	class Circle : public Ellipse
	{
	public:
		Circle(Vec3 center, double radius);

		inline CurveType getType() const override { return CurveType::Circle; }
		inline double getRadius() const { return m_xRadius; }

		bool operator<(const Circle& circle) const;

		Circle() = default;
		~Circle() = default;
	};
}
