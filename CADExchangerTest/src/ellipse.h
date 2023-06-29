#pragma once

#include "curve.h"

namespace Geometry
{
	class Ellipse : public Curve
	{
	public:
		Ellipse(Vec3 center, double a, double b);

		Ellipse() = default;
		~Ellipse() = default;

		inline CurveType getType() const override { return CurveType::Ellipse; }

		Vec3 getPoint(double t) const override;
		Vec3 getDerivative(double t) const override;

	protected:
		double m_xRadius;
		double m_yRadius;
	};
}
