#pragma once
#include <string>
#include <vector>
using namespace std;

int task3(string s, string s1)
{
	int res = 0;
	int heigth = s.length();
	int width = s1.length();
	int minscore;
	vector<int> a(width + 1);
	vector<vector<int>> score;
	for (int i = 0; i <= heigth; i++)
		score.push_back(a);
	for (int i = 1; i <= heigth; i++)
	{
		score[i][0] = score[i - 1][0] + 1;
	}
	for (int i = 1; i <= width; i++)
	{
		score[0][i] = score[0][i-1] + 1;
	}
	for (int i = 1; i <= heigth; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			minscore = 100000;
			if ((score[i - 1][j] + 1) < minscore)
			{
				minscore = score[i - 1][j] + 1;
			}
			if ((score[i][j - 1] + 1) < minscore)
			{
				minscore = score[i][j - 1] + 1;
			}
			if ((score[i - 1][j - 1] + 1) < minscore && (s[i-1] != s1[j - 1]))
			{
				minscore = score[i - 1][j - 1] + 1;
			}
			if (score[i - 1][j - 1] < minscore && (s[i-1] == s1[j-1]))
			{
				minscore = score[i - 1][j - 1];
			}
			score[i][j] += minscore;
		}
	}
	res = minscore;

	return res;
}