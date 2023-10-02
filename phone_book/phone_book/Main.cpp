#include "PhoneBook.h"
#include <fstream>
#include <iostream>


int main()
{
	system("chcp 1251>nul");
	
	PhoneBook p1;

	p1.readFile("phone_book.txt");

	p1.print();
	
	p1.search();

	p1.Mysort();

	p1.print();
				
	return 0;
}