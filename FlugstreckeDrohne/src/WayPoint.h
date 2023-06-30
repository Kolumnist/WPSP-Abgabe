#pragma once
#include <string>
#include <iostream>

using LOCATION = std::pair<double, double>;
static const double PI = atan(1.0) * 4;

class WayPoint
{
private:
	std::string m_name;
	LOCATION m_coords{ 0.0, 0.0 };

public:
	WayPoint() = default;
	WayPoint(const WayPoint& orig); //= default;
	WayPoint& operator=(const WayPoint&) = default;
	~WayPoint() = default;

	WayPoint(const std::string& name, double latitude, double longitude);

	// Getter - Setter
	std::string name() const;
	void name(const std::string& arg);

	double latitude() const;
	void latitude(double arg);

	double longitude() const;
	void longitude(double arg);

	void print() const;

	// Helper
	static double radians(double arg);
	static double distance(const WayPoint& from, const WayPoint& to);
	static std::string Degree2GMS(double latitude, double longitude);
};