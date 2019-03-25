#pragma once
#include <string>
#include <vector>

using namespace std;

vector<double> strtodouble(string mat) // перевод строки в массив чисел..
{
	vector<double> res;
	string temp = "";
	for (int j = 0; j < mat.length(); j++)
	{
		while (mat[j] != ' ' && j < mat.length())
		{
			temp += mat[j];
			j++;
		}
		res.push_back(atof(temp.c_str()));
		temp = " ";
	}
	return res;
}



string task1(vector<string> mat, string dna, int k)
{
	string res = "", temp = "";
	vector<vector<double>> matd;
	double max = 0.0, curmax = 1.0;
	for (int i = 0; i < 4; i++)
	{
		vector<double> temp;
		temp = strtodouble(mat[i]);
		matd.push_back(temp);
	}
	for (int n = 0; n < dna.length() - k; n++)
	{
		for (int i = n; i < n+k; i++)
		{
			temp += dna[i];
		}
		for (int i = 0; i < k; i++)
		{
			if (temp[i] == 'A')
			{
				curmax = curmax * matd[0][i];
			}
			else if (temp[i] == 'C')
			{
				curmax = curmax * matd[1][i];
			}
			else if (temp[i] == 'G')
			{
				curmax = curmax * matd[2][i];
			}
			else if (temp[i] == 'T')
			{
				curmax = curmax * matd[3][i];
			}
		}
		if (curmax > max)
		{
			max = curmax;
			res = temp;
		}
		temp = "";
		curmax = 1.0;
	}
	return res;
}