#include "Person.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Person& p)
{	
	out << p.surname << "\t" << p.name << "\t" << p.number << std::endl;

	return out;
}