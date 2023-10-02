#include "PhoneBook.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Other_function.h"


PhoneBook::PhoneBook()
{
	std::vector<Person>temp;
	pb = temp;
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	copy_from(other);
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
	if (this == &other)
		return *this;
	
	copy_from(other);

	return *this;
}

PhoneBook::~PhoneBook()
{
}

const std::vector<Person>& PhoneBook::getPb() const
{
	return pb;
}

void PhoneBook::search()
{
	std::string searchPrefix;

	std::cout << "Введите фамилию, имя или телефон: ";

	std::cin >> searchPrefix;
	
	std::vector<Person>result;
	
	std::copy_if(pb.begin(), pb.end(), std::back_inserter(result), [&](const Person& word)
		{ return startsPrefix(word, searchPrefix); });
	
		for (int i = 0; i < result.size(); i++)
		{
			std::cout << result[i];
		}
		
		if (result.size() == 0)
		std::cout << "Совпадений не найдено. " << std::endl;	
}

void PhoneBook::Mysort()
{
	std::string searchPrefix;

	std::cout << "Введите критерий сортировки: фамилия, имя или телефон: ";

	std::cin >> searchPrefix;

	Person word;

	std::sort(pb.begin(), pb.end(), [&](const Person& elem1, const Person& elem2)
		{return sortPrefix(elem1, elem2, searchPrefix); });
}

void PhoneBook::readFile(std::string path)
{
	std::ifstream in(path.c_str());

	if (!in.is_open())
	{
		std::cerr << "Файл не найден! Проверьте правильность пути. " << std::endl;
	}
	while(!in.eof())
		{			
			Person temp;

			in>>temp.surname;

			in>> temp.name;

			in>> temp.number;
			
			pb.push_back(temp);
		}
	
	in.close();
}

void PhoneBook::print()
{
	int num = pb.size();

	std::cout << "Фамилия\tИмя\tНомер телефона\n";

	for (int i = 0; i < num; i++)
	{
		Person temp = pb[i];

		std::cout << temp.surname << "\t" << temp.name << "\t" << temp.number << std::endl;
	}
}

void PhoneBook::copy_from(const PhoneBook& other)
{
	pb = other.getPb();
}

