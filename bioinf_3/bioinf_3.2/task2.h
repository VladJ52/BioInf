#pragma once

#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

map <string, string> MassTab = { { "A", "71" },{ "V", "99" },{ "G", "57" },
{ "E", "129" },{ "D", "115" },{ "L", "113" },{ "P", "97" },{ "R", "156" },
{ "Q", "128" },{ "H", "137" },{ "M", "131" },{ "I", "113" },{ "S", "87" },{ "T", "101" },
{ "K", "128" },{ "N", "114" },{ "F", "147" },{ "W", "186" },{ "C", "103" },{ "Y", "163" }
};

map <string, string> ::iterator current;


string shift(string s)  // сдвиг строки вправо
{
	int size = s.length();
	string temp;
	temp += s[size - 1];
	for (int i = 0; i < size - 1; i++)
		temp += s[i];
	return temp;
}

int summa(string s) // масса субпептида
{
	string temp;
	current = MassTab.begin();
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		temp += s[i];
		current = MassTab.find(temp);
		sum += stoi(current->second);
		temp = "";
	}
	return sum;
}

vector<int> Sort(vector<int> data, int lenD)
{
	int j = 0;
	int tmp = 0;
	for (int i = 0; i<lenD; i++) {
		j = i;
		for (int k = i; k<lenD; k++) {
			if (data[j]>data[k]) {
				j = k;
			}
		}
		tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
	return data;
}

vector<int> cyclicdrop(string s) // разбиение на субпептиды
{
	int size = s.length();
	int cnt = 0, N = size * (size - 1) + 2, n = 0;
	vector<int> sum;
	string temp, temp1;
	temp = s;
	temp += "|";
	temp1 = s;
	while (cnt != size - 1)
	{
		temp1 = shift(temp1);
		temp += temp1 + "|";
		cnt++;
	}
	int size1 = temp.length();
	int i = 0;
	temp1 = "";
	for (i; i < size; i++)
	{
		i--;
		while (temp[i + 1] != '|')
		{
			for (int j = 0; j < i + 1; j++)
			{
				temp1 += temp[j];
			}
			if (temp1 != "")
			{
				sum.push_back(summa(temp1));
				n++;
			}
			temp1 = "";
			i++;
		}
		temp.erase(0, size + 1);
		if (temp == "")
			break;
		i = 0;
	}
	sum.push_back(0);
	sum.push_back(summa(s));
	sum = Sort(sum, N);
	return sum;
}

int task2(string pep, string spectrum)
{
	vector<int> spec_pep = cyclicdrop(pep);
	vector<int> b,c;
	string temp;
	/*for (int i = 0; i < spec_pep.size(); i++)
	{
		a.insert(spec_pep[i]);
	}*/
	for (int i = 0; i < spectrum.length(); i++)
	{
		while (spectrum[i] != ' ' && i < spectrum.length())
		{
			temp += spectrum[i];
			i++;
		}
		b.push_back(atoi(temp.c_str()));
		temp = "";
	}
	set_intersection(spec_pep.cbegin(), spec_pep.cend(), b.cbegin(), b.cend(), back_inserter(c));
	return c.size();
}