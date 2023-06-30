#include <vector>

#include "WayPoint.h"

class WayPointContainer
{
private:
	static const int cMaxElements = 100;
	WayPoint* m_containerArray[cMaxElements]{ nullptr };
	int m_anzElems{ 0 };	

public:
	WayPointContainer() = default;

	WayPointContainer(const WayPointContainer& orig);
	virtual ~WayPointContainer();

	WayPoint& operator[](int idx) const;
	WayPointContainer& operator=(const WayPointContainer& rhs);

	int count() const;

	void add(WayPoint& arg);
	void print() const;

	double distance() const;
};