#pragma once
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int task1(string pat, string gen) //количество паттернов в геноме
{
	int sizep, sizeg, count, res;
	int i = 0;
	count = 0; res = 0;
	sizeg = gen.length();
	sizep = pat.length();
	if ((sizeg != 0) && (sizep != 0))
	{
		for (int j = 0; j <= sizeg-sizep; j++)
		{
			for (int i = 0; i < sizep; i++)
			{
				if (pat[i] == gen[j+i])
					count++;
				else
					break;
			}
			if (count == sizep)
				res++;
			count = 0;
		}
	}
	return res;
}

string task2(string genome, int s) // вывести паттерны заданного размера
{
	string res,temp;
	int size = genome.length();
	int cnt, maxcnt,cnt1;
	maxcnt = 1;
	for (int j = 0; j <= size - s; j++)
	{
		for (int i = 0; i < s; i++)	
			temp += genome[i+j];
		cnt = task1(temp, genome); 
		if (cnt > maxcnt)
		{
			res = "";
			res += temp;
			res += "  ";
			maxcnt = cnt;
		}
		else if (cnt == maxcnt)
		{
			cnt1 = task1(temp, res);
			if (cnt1 == 0)
			{
				res += temp;
				res += "  ";
			}
		}
		temp = "";
	}
	return res;
}

string task3(string pat)
{
	int size = pat.length();
	string res;
	for (int i = size - 1; i >= 0; i--)
		res += pat[i];
	for (int j = 0; j < size; j++)
	{
		if (res[j] == 'A')
			res[j] = 'T';
		else if (res[j] == 'T')
			res[j] = 'A';
		else if (res[j] == 'C')
			res[j] = 'G';
		else if (res[j] == 'G')
			res[j] = 'C';
	}
	return res;
}