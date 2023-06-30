#include "WayPoint.h"
#include "WayPointContainer.h"


int main()
{
	WayPoint* waypoints[] =
	{
		new WayPoint("Stadt Stuttgart, Schnellzentrum Schlossplatz", 48, 9),
		new WayPoint("Schwanenapotheke", 48.5, 9.5),
		new WayPoint("Stadt Stuttgart, Schnelltestzentrum Hohe Strasse", 48.2, 9.3),
		new WayPoint("Charlotten-Aphoteke", 48.8, 9.1),
		new WayPoint("Coronastation Koenigsbau-Passagen", 48.8, 9.3),
		new WayPoint("Europa Apotheke", 48.2, 9),
		new WayPoint("Internationale Apotheke", 48, 9.4),
		new WayPoint("NK Medical Services GmbH", 48.9, 9.4),
		new WayPoint("Schnelltestzentrum Olgaeck des Emma 64 Mobiler Pflege- und Sozialdienst", 48, 9.4),
		new WayPoint("Zahnarztpraxis Dr. Hendrik Putze", 48, 9.4),
		new WayPoint("15minutentest.de (Testzentrum Dorotheenquartier)", 48, 9.4),
		new WayPoint("Airbrushtanning", 48.1, 9.4),
		new WayPoint("Gesundhaus Apotheke im Milaneo", 48, 9.4),
		new WayPoint("Privomed GmbH - Corona Buergertestzentrum", 48, 9.4),
		new WayPoint("Medicare Schnelltestzentrum Stuttgart-Mitte", 48, 9.3),
		new WayPoint("Zahnarztpraxis Dr. Michael Huss", 48, 9.2),
		new WayPoint("Teststelle Kronenstrasse", 48.6, 9.4),
		new WayPoint("Teststelle Bohnenviertel", 48, 9.0),
	};

	 
	std::cout << "----------------------------\n"
		<< "The Original Container\n"
		<< "----------------------------" << std::endl;

	WayPointContainer* origin_container = new WayPointContainer();

	for (int i = 0; i < 18; i++)
	{
		origin_container->add(*waypoints[i]);
	}
	origin_container->print();


	std::cout << "----------------------------\n"
		<< "With copy ctor\n"
		<< "----------------------------" << std::endl;

	WayPointContainer copy_container(*origin_container);
	copy_container.print();


	std::cout << "----------------------------\n"
		<< "With assignment operator ctor\n"
		<< "----------------------------" << std::endl;

	WayPointContainer assignment_container = *origin_container;
	assignment_container.print();


	WayPoint* p = new WayPoint();
	origin_container->add(*p);


	waypoints[0]->latitude(10.0);
	std::cout << "\n\n\n\n\n" << std::endl;
	origin_container->print();
	copy_container.print();
	assignment_container.print();

	std::cin.get();
}