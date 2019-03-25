#include "5_1.h"
#include "5_2.h"
#include "5_3.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//===============task1=============
	/*string text, res = "", temp = "";
	int k, i = 0;
	vector<string> matrix;
	getline(cin, text);
	cin >> k;
	while (i <= 4)
	{
		getline(cin, temp);
		matrix.push_back(temp);
		if (i == 0)
			matrix.pop_back();
		i++;
	}
	res = task1(matrix, text, k);
	cout << res;
	return 0;*/

	//===================================

	//=============task2,3=================

	int t, k;
	vector<string> matrix, res;
	string temp = "";
	cin >> k >> t;
	while (!cin.eof())
	{
		cin >> temp;
		matrix.push_back(temp);
	}
	matrix.pop_back();
	res = task3(matrix, k, t);
	for (int i = 0; i < t; i++)
		cout << res[i] << endl;
	return 0;
}