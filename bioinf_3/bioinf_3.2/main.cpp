#include "task2.h"
#include <iostream>

int main()
{
	string pep, spectrum;
	getline(cin, pep);
	getline(cin, spectrum);
	cout << task2(pep, spectrum);
	return 0;
}