#include <stdexcept>
#include <cmath>
#include <sstream>
#include <iostream>

#include "WayPoint.h"

WayPoint::WayPoint(const WayPoint& orig)
	: m_name(orig.m_name), m_coords(orig.m_coords)
{
	std::cout << "NOOO COPIED" << this << std::endl;
}

WayPoint::WayPoint(const std::string& name, double latitude, double longitude)
	: m_name(name)
{
	if (std::abs(static_cast<int>(latitude)) > 90)
		throw std::out_of_range("Latitude is out of range");

	if (std::abs(static_cast<int>(longitude)) > 180)
		throw std::out_of_range("Longitude is out of range");

	m_coords.first = latitude;
	m_coords.second = longitude;
}

std::string WayPoint::name() const
{
	return this->m_name;
}

void WayPoint::name(const std::string& arg)
{
	this->m_name = arg;
}

double WayPoint::latitude() const
{
	return this->m_coords.first;
}

void WayPoint::latitude(double arg)
{
	this->m_coords.first = arg;
}

double WayPoint::longitude() const
{
	return this->m_coords.second;
}

void WayPoint::longitude(double arg)
{
	this->m_coords.second = arg;
}

void WayPoint::print() const
{
	std::string output = "Name: ";
	if (this->m_name.empty())
	{
		 output += "<Empty>";
	}
	else
	{
		output += this->m_name;
	}
	
	output += " - (" + Degree2GMS(this->m_coords.first, this->m_coords.second) + ")";

	std::cout << output << std::endl;
}

// Helper
double WayPoint::radians(double arg)
{
	return arg * PI / 180.0;
}

double WayPoint::distance(const WayPoint& from, const WayPoint& to)
{
	double lat = radians((from.latitude() + to.latitude()) / 2.0);
	double dx = 111.3 * std::cos(lat) * (from.longitude() - to.longitude());
	double dy = 111.3 * (from.latitude() - to.latitude());

	return std::sqrt(dx * dx + dy * dy);
}

std::string WayPoint::Degree2GMS(double latitude, double longitude)
{
	std::stringstream ss;
	ss << (int)latitude << char(0xF8);

	double x = latitude - (int)latitude;
	x *= 60;
	ss << (int)x << char(0x27);

	x -= (int)x;
	x *= 60;
	ss << (int)x << char(0x22) << "N ";

	ss << (int)longitude << char(0xF8);
	x = longitude - (int)longitude;
	x *= 60;
	ss << (int)x << char(0x27);

	x -= (int)x;
	x *= 60;
	ss << (int)x << char(0x22) << 'E';

	return ss.str();
}
