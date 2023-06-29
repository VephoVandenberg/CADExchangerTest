#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <omp.h>

#include "src/circle.h"
#include "src/ellipse.h"
#include "src/helix.h"


constexpr unsigned int g_numberOfCurves = 1000;
constexpr double g_radiusMax = 500.0f;
constexpr double g_stepMax = 10.0f;
constexpr Geometry::Vec3 g_minPos = { -400.0f, -400.0f, 0.0f };
constexpr Geometry::Vec3 g_maxPos = { 800.0f, 800.0f, 0.0f };

int main(int argc, char** argv)
{
	// 1.	Populate a container of objects of 
	//		these types created in random manner with random parameters
	std::vector<std::shared_ptr<Geometry::Curve>> curves;
	curves.reserve(g_numberOfCurves);

	for (unsigned int i = 0; i < g_numberOfCurves; i++)
	{
		int curveType = rand() % 3;
		Geometry::Vec3 position = {
			g_minPos.x + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (g_maxPos.x - g_minPos.x))),
			g_minPos.y + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (g_maxPos.y - g_minPos.y))),
			0.0f
		};

		switch (curveType)
		{
		case 0:
		{
			double radius = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / g_radiusMax));
			curves.push_back(std::make_shared<Geometry::Circle>(position, radius));
		}break;
		case 1:
		{
			double a = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / g_radiusMax));
			double b = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / g_radiusMax));
			curves.push_back(std::make_shared<Geometry::Ellipse>(position, a, b));
		}break;
		case 2:
		{
			double radius = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / g_radiusMax));
			double step = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / g_stepMax));
			curves.push_back(std::make_shared<Geometry::Helix>(position, radius, step));
		}break;
		}
	}

	// 2.	Print coordinates of points and derivatives of all curves at t=PI/4
	std::cout << "Points and derivatives at t = PI / 4";
	for (auto& curve : curves)
	{
		auto p = curve->getPoint(M_PI / 4);
		auto d = curve->getDerivative(M_PI / 4);
		std::cout << "=====================" << std::endl;
		std::cout << curve->getType() << std::endl;
		std::cout << p << std::endl;
		std::cout << d << std::endl;
		std::cout << "=====================" << std::endl;
	}

	// 3.	Populate a second container that would contain only circles from the first container,
	//		make sure the second container shares circles of the first one, via pointers.
	std::vector<std::shared_ptr<Geometry::Circle>> circles;
	std::cout << "Populating second container with circles." << std::endl;
	for (auto& curve : curves)
	{
		if (curve->getType() == Geometry::CurveType::Circle)
		{
			circles.push_back(std::dynamic_pointer_cast<Geometry::Circle>(curve));
			std::cout << "R: " << circles.back()->getRadius() << std::endl;
		}
	}

	// 4.	Sort the second container in ascending order of circles' radii.
	std::cout << "Sorting circles by radius." << std::endl;
	std::sort(
		circles.begin(), circles.end(), 
		[](const std::shared_ptr<Geometry::Circle>& c1, const std::shared_ptr<Geometry::Circle>& c2) {
			return *c1 < *c2;
		});
	for (auto& circle : circles)
	{
		std::cout << "R: " << circle->getRadius() << std::endl;
	}

	// 5.	Compute total sum of radii of all curvers in second container
	std::cout << "Total sum of radii in second container" << std::endl;
	double total = 0;
#pragma omp parallel for reduction(+:total)
	for (auto& circle : circles)
	{
		total += circle->getRadius();
	}
	std::cout << "Total = " << total << std::endl;

	return 0;
}
