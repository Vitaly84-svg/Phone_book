#include "Other_function.h"

bool startsPrefix(const Person& word, const std::string& prefix)
{
	if (word.surname.substr(0, prefix.length()) == prefix)
		return true;

	if (word.name.substr(0, prefix.length()) == prefix)
		return true;

	if (word.number.substr(0, prefix.length()) == prefix)
		return true;

	return false;
}

bool sortPrefix(const Person& elem1, const Person& elem2, const std::string& prefix)
{
	if (prefix == "�������")
		return elem1.surname < elem2.surname;

	if (prefix == "���") 
		return elem1.name < elem2.name;

	if (prefix == "�������") 
		return elem1.number < elem2.number;

	return false;
}

