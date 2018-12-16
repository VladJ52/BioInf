#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

string removedup(string v, int k)
{
	int size = v.length();
	int pos;
	string temp;
	for (int i = 0; i < v.size(); i++)
	{
		while (v[i] != ' ' && i<v.size())
		{
			temp += v[i];
			i++;
		}
		pos = v.find(temp, i);
		if (pos != -1)
		{
			while (pos != -1)
			{
				v.erase(pos, k);
				v.erase(pos, 1);
				pos = v.find(temp, pos);
			}
			v.erase(i - k, k);
			v.erase(i - k, 1);
			if (v.size() != size)
			{
				i = -1;
				size = v.size();
			}
			if (v[0] == ' ')
				v.erase(0, 1);
			if (v[size-1] == ' ')
				v.erase(size - 1, 1);
		}
		temp = "";
	}
	return v;
}

vector<string> miss(string pep, int d) // razbienie na vse vozm promahi
{
	vector<string> res;
	string m = "CATG";
	string temp;
	int size = pep.length();
	if (d == 1)
	{
		for (int i = 0; i < size; i++)
		{
			temp = pep;
			for (int j = 0; j < 4; j++)
			{
				temp[i] = m[j];
				res.push_back(temp);
			}
		}
	}
	return res;
}

bool findstr(vector<string> dna, string pep, int d)
{
	string temp;
	vector<string> t;
	bool flag = false;
	string prob; // vozmozni motif
	t = miss(pep, d);
	for (int i = 0; i < dna.size(); i++)
	{
		temp = dna[i];
		flag = false;
		for (int j = 0; j < t.size(); j++)
		{
			if (temp.find(t[j]) != -1)
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
			break;
	}
	return flag;
}

string task1(vector<string> dna, int k, int d)
{
	string res = "";
	string temp = "", first = "";
	vector<string> t;
	for (int a = 0; a < dna.size(); a++)
	{
		first = dna[a];
		for (int i = 0; i < first.length() - k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				temp += first[i + j];
			}
			t = miss(temp, d);
			for (int e = 0; e < t.size(); e++)
			{
				if (findstr(dna, t[e], d) && res.find(t[e]) == -1)
				{
					res += t[e] + ' ';
				}
			}
			temp = "";
		}
	}
	res.erase(res.length() - 1);
	return res;
}