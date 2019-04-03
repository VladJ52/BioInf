#include <iostream>
#include "6_1.h"
#include "6_2.h"
#include "6_3.h"

int main()
{
	//int money;
	//int res;
	//string s;
	//cin >> money;
	//cin >> s;
	//res = task1(money, s);
	//cout << res;
	//return 0;

	//-----------------------------------
	/*int n, m;
	int res;
	vector<string> s;
	string temp;
	cin >> n >> m;
	while (!cin.eof())
	{
		cin >> temp;
		s.push_back(temp);
	}
	s.pop_back();
	res = task2(n, m, s);
	cout << res;
	return 0;*/
	//-------------------------------------
	string s, t, res;
	cin >> s;
	cin >> t;
	res = task3(s, t);
	cout << res;
	return 0;
}