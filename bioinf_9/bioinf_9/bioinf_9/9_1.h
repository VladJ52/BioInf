#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;

int findmaxtop(vector<string> links)
{
	int max = 0, cur = 0;
	string temp, temp1;
	for (int i = 0; i < links.size(); i++)
	{
		temp = links[i];
		while (temp[cur] != ' ')
		{
			temp1 += temp[cur];
			cur++;
		}
		cur = 0;
		if (max < atoi(temp1.c_str()))
			max = atoi(temp1.c_str());
		temp1 = "";
	}
	return max;
}

vector<vector<int>> getgraph(vector<string> links) // получение графа смежности
{
	int n = findmaxtop(links);
	n++;
	int ii, jj; // индексы для графа
	string temp;
	string temp1 = "";// для чисел
	vector<vector<int>> res(n, vector<int>(n));
	for (int i = 0; i < links.size(); i++)
	{
		temp = links[i];
		temp1 = "";
		for (int j = 0; j < temp.length(); j++)
		{
			if (j == 0)
			{
				while (temp[j] != ' ')
				{
					temp1 += temp[j];
					j++;
				}
				ii = atoi(temp1.c_str());
				j += 3;
				temp1 = "";
			}
			else
			{
				if (temp[j] != ',')
					temp1 += temp[j];
				if (temp[j] == ',' || j == (temp.length()-1))
				{
					jj = atoi(temp1.c_str());
					res[ii][jj] = 1;
					temp1 = "";
				}
			}
		}
	}
	return res;
}

int degcount(vector<vector<int>> matr, int ind)//кол-во ребер
{
	int res = 0;
	for (int i = 0; i < matr[ind].size(); i++)
	{
		if (matr[ind][i] == 1)
			res++;
	}
	return res;
}

bool isempty(vector<vector<int>> matr)// проверка на пустоту графа
{
	for (int i = 0; i < matr.size(); i++)
	{
		for (int j = 0; j < matr.size(); j++)
		{
			if (matr[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}

string task1(vector<string> links) // Поиск Эйлерова цикла
{
	string res1;
	int n = links.size();
	int countdeg = 0, i;
	vector<vector<int>> graph(n,vector<int>(n)); // граф со связями
	vector<int> cycle, prevcycle, res;
	graph = getgraph(links);
	vector<vector<int>> tempgraph(n, vector<int>(n));
	tempgraph = graph;
	stack<int> st;
	i = 0;
	while (!isempty(tempgraph))
	{
		st.push(i);
		if (!prevcycle.empty())
		{
			int ii = 0;
			for (int j = 0; j < prevcycle.size(); j++)
			{
				if (prevcycle[j] == i)
				{
					ii = j;
					break;
				}
			}
			int jj = ii;
			do
			{
				res.push_back(prevcycle[jj]);
				tempgraph[prevcycle[jj]][prevcycle[jj + 1]] = 0;
				jj++;
				if (jj == prevcycle.size() - 1)
					jj = 0;
			} while (jj != ii);
		}
		while (!st.empty())
		{
			if (degcount(tempgraph, i) == 0)
			{
				cycle.push_back(st.top());
				st.pop();
			}
			else
			{
				for (int j = 0; j < n; j++)
				{
					if (tempgraph[i][j] != 0)
					{
						tempgraph[i][j] = 0;
						st.push(j);
						i = j;
						break;
					}
				}
			}
		}
		reverse(cycle.begin(), cycle.end());
		for (int j = 0; j < cycle.size(); j++)
		{
			res.push_back(cycle[j]);
		}
		for (int j = 0; j < res.size() - 1; j++)
		{
			if (degcount(tempgraph, res[j]) != 0)
			{
				i = res[j];
				tempgraph = graph;
				break;
			}
		}
		prevcycle = res;
		res.clear();
		cycle.clear();
	}
	res = prevcycle;
	for (int i = 0; i < res.size(); i++)
	{
		res1 = res1 + to_string(res[i]);
		if (i != res.size() - 1)
			res1 += "->";
	}
	return res1;
}