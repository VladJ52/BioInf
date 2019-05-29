#include "9_1.h"
#include "9_2.h"
#include <iostream>

using namespace std;



int main()
{
	//Ёйлеровы цикл и путь
	vector<string> links;
	string temp;
	while (!cin.eof())
	{
		getline(cin, temp);
		links.push_back(temp);
	}
	links.pop_back();
	string res;
	//res = task1(links);
	res = task2(links);
	cout << res;
	return 0;
}