#include <stdexcept>
#include <iostream>

#include "WayPointContainer.h"

WayPointContainer::WayPointContainer(const WayPointContainer& orig)
{
	this->m_anzElems = orig.m_anzElems;

	for (int i = 0; i < this->m_anzElems; ++i)
	{
		this->m_containerArray[i] = new WayPoint(*orig.m_containerArray[i]);
	}
}

WayPointContainer::~WayPointContainer()
{
	for (int i = 0; i < this->m_anzElems; ++i) 
	{
		std::cout << "DESTROYED " << i << std::endl;
		delete this->m_containerArray[i];
	}
}

WayPoint& WayPointContainer::operator[](int idx) const
{
	if (idx < 0 || idx > m_anzElems)
		throw std::out_of_range("index is out of range");
	return *this->m_containerArray[idx];
}

WayPointContainer& WayPointContainer::operator=(const WayPointContainer& rhs)
{
	if (this == &rhs) 
	{
		return *this;
	}

	for (int i = 0; i < this->m_anzElems; ++i)
	{
		delete this->m_containerArray[i];
	}

	this->m_anzElems = rhs.m_anzElems;

	for (int i = 0; i < this->m_anzElems; ++i)
	{
		this->m_containerArray[i] = new WayPoint(*rhs.m_containerArray[i]);
	}

	return *this;
}

int WayPointContainer::count() const
{
	return this->m_anzElems;
}

void WayPointContainer::add(WayPoint& arg)
{
	this->m_containerArray[this->m_anzElems++] = &arg;
}

void WayPointContainer::print() const
{
	std::cout << "Anzahl Wegepunkte: " << this->m_anzElems << "\n"
		<< "---------------------" << std::endl;

	for (int i = 0; i < this->m_anzElems; ++i)
	{
		std::cout << "[" << i << "] ";
		this->m_containerArray[i]->print();
	}

	std::cout << "\nGesamte Distanz: " << this->distance() << std::endl;
}

double WayPointContainer::distance() const
{
	double distance = 0;
	for (int i = 0; i < this->m_anzElems; ++i)
	{
		if (this->m_containerArray[i + 1] != nullptr)
		{
			WayPoint* from = this->m_containerArray[i];
			WayPoint* to = this->m_containerArray[i+1];
			distance += this->m_containerArray[i]->distance(*from, *to);

			continue;
		}
		return distance;
	}
	return distance;
}
