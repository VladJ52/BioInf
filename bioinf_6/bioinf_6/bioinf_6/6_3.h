#pragma once

#include <vector>
#include <string>

using namespace std;
string reverse(string t)
{
	string res;
	int n = t.length();
	for (int i = n-1; i >= 0; i--)
		res += t[i];
	return res;
}

string task3(string s, string t)
{
	string res = "";
	int n = s.length();
	int m = t.length();
	vector<vector<int>> ma;
	vector<int> a;
	string backtrack;
	for (int i = 0; i <= m; i++) // s - горизонталь
		a.push_back(0);
	for (int i = 0; i <= n; i++) // t - вертикаль
		ma.push_back(a);
	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j <= m; j++)
		{
			if (ma[i - 1][j] > max)
			{
				max = ma[i - 1][j];
			}
			if (ma[i][j - 1] > max)
			{
				max = ma[i][j - 1];
			}
			if (ma[i - 1][j - 1] + 1 > max && s[i - 1] == t[j - 1])
			{
				max = ma[i - 1][j - 1] + 1;
			}
			ma[i][j] += max;
		}
		int k = n, kk = m;
		while (k > 0 && kk > 0)
		{
			if (ma[k][kk] == ma[k][kk - 1])
			{
				backtrack += 'r';
				kk--;
			}
			else if (ma[k][kk] == ma[k - 1][kk])
			{
				backtrack += 'd';
				k--;
			}
			else if (ma[k][kk] == (ma[k - 1][kk - 1] + 1))
			{
				backtrack += 'z';
				k--;
				kk--;
				res += s[k];
			}
		}
	}
	res = reverse(res);
	return res;
}


