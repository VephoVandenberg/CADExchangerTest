#pragma once

#include "curve.h"

namespace Geometry
{
	class __declspec(dllexport) Helix : public Curve
	{
	public:
		Helix(Vec3 center, double radius, double step);

		inline CurveType getType() const override { return CurveType::Helix; }

		Vec3 getPoint(double t) const override;
		Vec3 getDerivative(double t) const override;

		Helix() = default;
		~Helix() = default;

	private:
		double m_radius;
		double m_step;
	};
}
