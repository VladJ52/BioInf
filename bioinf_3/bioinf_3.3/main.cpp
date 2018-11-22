
#include <iostream>
#include "task3.h"



int main()
{
	string N;
	int n;
    string v;
	string spectrum;
	getline(cin, N);
	getline(cin, spectrum);
	n = atoi(N.c_str());
	v = task3(spectrum, n);
	cout << v;
}