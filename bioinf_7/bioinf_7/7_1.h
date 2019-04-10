#pragma once

#include <vector>

using namespace std;

vector<vector<int>> convert(string s) // получаю матрицу выравнивания
{
	vector<int> temp;
	vector<vector<int>> res;
	string tt = "";
	int t = 0, k = 0;
	for (int i = 0; i < 21; i++)
		temp.push_back(0);
	for (int i = 0; i < 21; i++)
		res.push_back(temp);
	for (int i = 0; i < s.length()-1; i++)
	{
		if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0' && t<20)
		{
			tt += s[i];
			if (s[i + 1] == '1' || s[i + 1] == '2' || s[i + 1] == '3' || s[i + 1] == '4' || s[i + 1] == '5' || s[i + 1] == '6' || s[i + 1] == '7' || s[i + 1] == '8' || s[i + 1] == '9' || s[i + 1] == '0')
			{
				tt += s[i + 1];
				i++;
			}
			res[k][t] = atoi(tt.c_str());
			if (s[i - 1] == '-')
				res[k][t] = res[k][t] * (-1);
			tt = "";
			t++;
		}
		if (t == 20)
		{
			res[k][t] = -5;
			k++;
			t = 0;
		}
		
	}
	for (int i = 0; i < 21; i++)
		res[20][i] = -5;
	return res;
}

int ind(char c) // поиск индекса амминокислоты\инделя
{
	int res = 0;
	string help = "ACDEFGHIKLMNPQRSTVWY-";
	for (int i = 0; i < help.length(); i++)
	{
		if (help[i] == c)
		{
			res = i;
			break;
		}
	}
	return res;
}


vector<string> task1(vector<vector<int>> ma, string s, string s1)
{
	vector<string> res;
	int maxscore = -100;
	int heigth = s.length(), width = s1.length();
	vector<int> a(width+1);
	vector<vector<int>> score;
	string res1 = "", res2 = "";
	string backtrack;
	for (int i = 0; i <= heigth; i++)
		score.push_back(a);
	score[0][0] = 0;
	for (int i = 1; i <= heigth; i++)
	{
		score[i][0] = score[i-1][0] - 5;
	}
	for (int i = 1; i <= width; i++)
	{
		score[0][i] = score[0][i-1] - 5;
	}
	for (int i = 1; i <= heigth; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			maxscore = -100;
			if ((score[i - 1][j] - 5) > maxscore)
			{
				maxscore = score[i-1][j] - 5;
			}
			if ((score[i][j - 1] - 5) > maxscore)
			{
				maxscore = score[i][j-1] - 5;
			}
			if ((score[i - 1][j - 1] + ma[ind(s[i - 1])][ind(s1[j - 1])]) > maxscore)
			{
				maxscore = score[i-1][j-1] + ma[ind(s[i - 1])][ind(s1[j-1])];
			}
			score[i][j] += maxscore;
		}
	}
	int n = heigth;
	int m = width;
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
	}
	if (n != 0)
		backtrack += 'r';
	if (m != 0)
		backtrack += 'd';
	n = 0; m = 0;
	for (int i = backtrack.length() - 1; i >= 0; i--)
	{
		if (backtrack[i] == 'r')
		{
			res1 += s[n];
			res2 += '-';
			n++;
		}
		if (backtrack[i] == 'd')
		{
			res1 += '-';
			res2 += s1[m];
			m++;
		}
		if (backtrack[i] == 'z')
		{
			res1 += s[n];
			res2 += s1[m];
			n++; m++;
		}
	}
	res.push_back(to_string(maxscore));
	res.push_back(res1);
	res.push_back(res2);
	return res;
}