#pragma once

#include <vector>
#include <algorithm>

using namespace std;

vector<int> findmax(vector<vector<int>> ma)
{
	vector<int> res;
	int max = 0;
	int maxi, maxj;
	for (int i = 0; i < ma.size(); i++)
	{
		for (int j = 0; j < ma[0].size(); j++)
		{
			if (ma[i][j] > max)
			{
				max = ma[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}
	res.push_back(maxi);
	res.push_back(maxj);
	return res;
}

vector<string> task2(vector<vector<int>> ma, string s, string s1)
{
	vector<string> res;
	int maxscore = 0;
	int maxmax = 0;
	int heigth = s.length(), width = s1.length();
	vector<int> a(width+1);
	vector<vector<int>> score;
	string res1 = "", res2 = "";
	string backtrack;
	vector<int> index;
	for (int i = 0; i <= heigth; i++)
		score.push_back(a);
	for (int i = 1; i <= heigth; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			maxscore = -1000;
			if ((score[i - 1][j] - 5) > maxscore)
			{
				maxscore = score[i - 1][j] - 5;
			}
			if ((score[i][j - 1] - 5) > maxscore)
			{
				maxscore = score[i][j - 1] - 5;
			}
			if ((score[i - 1][j - 1] + ma[ind(s[i - 1])][ind(s1[j - 1])]) > maxscore)
			{
				maxscore = score[i - 1][j - 1] + ma[ind(s[i - 1])][ind(s1[j - 1])];
			}
			if (maxscore < 0)
				maxscore = 0;
			if (maxscore > maxmax)
				maxmax = maxscore;
			score[i][j] += maxscore;
		}
	}
	index = findmax(score);
	int n = index[0];
	int m = index[1];
	while (n > 0 && m > 0)
	{
		if (score[n][m] == (score[n - 1][m] - 5))
		{
			backtrack += 'r';
			n--;
		}
		else if (score[n][m] == (score[n][m - 1] - 5))
		{
			backtrack += 'd';
			m--;
		}
		else if (score[n][m] == (score[n - 1][m - 1] + ma[ind(s[n - 1])][ind(s1[m - 1])]))
		{
			backtrack += 'z';
			n--;
			m--;
		}
		else
		{
			backtrack += 'e'; // end
			n = m = 0;
		}
	}
	if (n != 0)
		backtrack += 'r';
	if (m != 0)
		backtrack += 'd';
	n = index[0] - 1; m = index[1] - 1;
	for (int i = 0; i < backtrack.length(); i++)
	{
		if (backtrack[i] == 'r')
		{
			res1 += s[n];
			res2 += '-';
			n--;
		}
		if (backtrack[i] == 'd')
		{
			res1 += '-';
			res2 += s1[m];
			m--;
		}
		if (backtrack[i] == 'z')
		{
			res1 += s[n];
			res2 += s1[m];
			n--; m--;
		}
		if (backtrack[i] == 'e')
		{
			break;
		}
	}
	reverse(res1.begin(), res1.end());
	reverse(res2.begin(), res2.end());
	res.push_back(to_string(maxmax));
	res.push_back(res1);
	res.push_back(res2);
	return res;
}