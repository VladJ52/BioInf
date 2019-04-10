#include <iostream>
#include <fstream>
#include <string>
#include "7_1.h"
#include "7_2.h"
#include "7_3.h"

using namespace std;

const char fname[] = "BLOSUM62.txt";
const char f1name[] = "PAM250_1.txt";

int main()
{
	//string matr;
	//char c;
	//int count = 0;
	//ifstream f(fname);
	//while (!f.eof())
	//{
	//	f.get(c);
	//	count++;
	//}
	//f.close();
	//for (int i = 0; i < count; i++)
	//{
	//	ifstream f2(fname);
	//	while (!f2.eof())
	//	{
	//		f2.get(c);
	//		matr += c;
	//		i++;
	//	}
	//	f2.close();
	//}
	//vector<vector<int>> matrix = convert(matr);

	//string a;
	//string b;
	//getline(cin, a);
	//getline(cin, b);
	//int cnt;
	//vector<string> res = task1(matrix, a, b);
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << res[i] << endl;
	//}

	//----------------------------------------------------task3
	string a;
	string b;
	int res;
	getline(cin, a);
	getline(cin, b);
	res = task3(a, b);
	cout << res;
	return 0;
}

