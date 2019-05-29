#pragma once
#include <string>
#include <vector>
#include <stack>
#include "9_1.h"
using namespace std;

int outdeg(vector<vector<int>> graph, int ind)
{
	int res = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		res += graph[ind][i];
	}
	return res;
}

int indeg(vector<vector<int>> graph, int ind)
{
	int res = 0;
	for (int i = 0; i < graph.size(); i++)
	{
		res += graph[i][ind];
	}
	return res;
}

vector<int> badtops(vector<vector<int>> graph) // поиск вершин у которых не равно число входных и выходных ребер
{
	vector<int> res;
	for (int i = 0; i < graph.size(); i++)
	{
		if (indeg(graph, i) != outdeg(graph, i))
			res.push_back(i);
	}
	return res;
}

string task2(vector<string> links) // Ёйлеров путь
{
	string res1;
	int countdeg = 0, i, il, ir;
	vector<vector<int>> graph; // граф со св€з€ми
	vector<int> cycle, prevcycle, res;
	graph = getgraph(links);
	int n = graph.size();
	vector<vector<int>> tempgraph;
	vector<int> btops;
	tempgraph = graph;
	stack<int> st;
	for (int j = 0; j < n; j++)
	{
		if (degcount(graph, j) != 0)
		{
			i = j;
			break;
		}
	}
	btops = badtops(graph);
	if (indeg(graph, btops[0]) < outdeg(graph, btops[0]))
	{
		graph[btops[1]][btops[0]] = 1;
		il = btops[1]; ir = btops[0];
	}
	else
	{
		graph[btops[0]][btops[1]] = 1;
		il = btops[0]; ir = btops[1];
	}
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
	int ind1 = 0;
	for (int j = 0; j < res.size() - 1; j++)
	{
		if (res[j] == il && res[j + 1] == ir)
		{
			ind1 = j + 1;
			break;
		}
	}
	vector<int> res2;
	for (int j = ind1; j < res.size(); j++)
	{
		res2.push_back(res[j]);
	}
	for (int j = 1; j < ind1; j++)
	{
		res2.push_back(res[j]);
	}
	for (int i = 0; i < res2.size(); i++)
	{
		res1 = res1 + to_string(res2[i]);
		if (i != res2.size() - 1)
			res1 += "->";
	}
	return res1;
}