#pragma once
#include "Person.h"
#include <vector>



class PhoneBook
{
public:
	PhoneBook();
		
	PhoneBook(const PhoneBook&);

	PhoneBook& operator=(const PhoneBook&);

	~PhoneBook();

	const std::vector<Person>& getPb() const;

	void readFile(std::string);

	void print();
		
	void search();

	void Mysort();
			
private:
	std::vector<Person>pb;
		
	void copy_from(const PhoneBook&);
};

