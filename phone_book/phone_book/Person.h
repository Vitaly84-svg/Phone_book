#pragma once
#include <string>


struct Person
{
	std::string surname;

	std::string name;

	std::string number;

	friend std::ostream& operator<<(std::ostream&, const Person&);	
};