#pragma once

#include <iostream>

namespace Geometry
{
	struct Vec3
	{
		double x, y, z;

		friend std::ostream& operator<<(std::ostream& o, Vec3& p)
		{
			o << "x: " << p.x << " y: " << p.y << " z: " << p.z;
			return o;
 		}
	};

	enum class CurveType
	{
		Ellipse,
		Circle,
		Helix
	};

	class Curve
	{
	public:
		Curve(Vec3 center);

		Curve() = default;
		virtual ~Curve() = default;
		
		virtual inline CurveType getType() const = 0;
		virtual Vec3 getPoint(double t) const = 0;
		virtual Vec3 getDerivative(double t) const = 0;

	protected:
		Vec3 m_center;
	};

	std::ostream& operator<<(std::ostream& o, CurveType type);

}
