#pragma once


#include <vector>
#include <string>

using namespace std;
vector<vector<int>> getmatr(vector<string> s, int n, int m)
{
	vector<vector<int>> res;
	vector<int> temp;
	for (int i = 0; i < m; i++)
	{
		temp.push_back(0);
	}
	for (int j = 0; j < n; j++)
	{
		res.push_back(temp);
	}
	int kk = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res[i][j] = atoi(s[kk].c_str());
			kk++;
		}
	}
	return res;
}

int task2(int n, int m, vector<string> s)
{
	int res = 0;
	vector<vector<int>> down, right;
	vector<string> s1,s2;
	for (int i = 0; i<s.size(); i++)
	{
		if (i < n * (m+1) && s[i] != "-")
			s1.push_back(s[i]);
		else if (s[i] != "-")
			s2.push_back(s[i]);
	}
	down = getmatr(s1, n, m + 1);
	right = getmatr(s2, n + 1, m);
	vector<vector<int>> matrix;
	vector<int> temp;
	for (int i = 0; i <= m; i++)
		temp.push_back(0);
	for (int j = 0; j <= n; j++)
		matrix.push_back(temp);
	for (int i = 1; i <= n; i++)
	{
		matrix[i][0] = matrix[i-1][0] + down[i-1][0];
	}
	for (int i = 1; i <= m; i++)
	{
		matrix[0][i] = matrix[0][i-1] + right[0][i-1];
	}
	for (int i = 1; i <= n; i++)
	{
		int max = 0;
		for (int j = 1; j <= m; j++)
		{
			if ((matrix[i - 1][j] + down[i-1][j]) > max)
				max = matrix[i - 1][j] + down[i-1][j];
			if (max < (matrix[i][j - 1] + right[i][j-1]))
				max = matrix[i][j - 1] + right[i][j-1];
			matrix[i][j] = max;
		}
	}
	res = matrix[n][m];
	return res;
}