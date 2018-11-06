#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map <string, string> KodonTab = { { "A", "GCUGCCGCAGCG" }, { "V", "GUGGUAGUCGUU" }, { "G", "GGUGGCGGAGGG" },
{ "E", "GAAGAG" }, { "D", "GAUGAC" }, { "L", "CUUCUCCUGCUAUUGUUA" },{ "P", "CCUCCACCGCCC" },{ "R", "CGUCGACGCCGGAGGAGA" },
{ "Q", "CAACAG" },{ "H", "CAUCAC" },{ "M", "AUG" },{ "I", "AUAAUCAUU" },{ "S", "AGCAGUUCGUCAUCCUCU" },{ "T", "ACGACUACAACC" },
{ "K", "AAGAAA" },{ "N", "AACAAU" },{ "F", "UUCUUU" },{ "W", "UGG" },{ "C", "UGCUGU" }, {"Z", "UGAUAGUAA"}, {"Y", "UACUAU"}
};

map <string, string> MassTab = { { "A", "71" },{ "V", "99" },{ "G", "57" },
{ "E", "129" },{ "D", "115"},{ "L", "113" },{ "P", "97" },{ "R", "156" },
{ "Q", "128" },{ "H", "137" },{ "M", "131" },{ "I", "113" },{ "S", "87"},{ "T", "101" },
{ "K", "128" },{ "N", "114" },{ "F", "147" },{ "W", "186" },{ "C", "103" },{ "Y", "163" }
};

map <string,string> ::iterator current;

// Z - остановка разбора...

string findkodon(string amino) // поиск кодона в таблице
{
	current = KodonTab.find("A");
	string res, temp;
	string sup;
	res = "";
	if (amino == "UGA" || amino == "UAG" || amino == "UAA")
		return "Z";
	while (res == "") {
		temp = current->second;
		int size = temp.length();
		for (int i = 0; i < size; i += 3)
		{
			for (int j = 0; j < 3; j++)
				sup += temp[i + j];
			if (sup == amino)
			{
				res += current->first;
				break;
			}
			else
			{
				sup = "";
				continue;
			}
		}
		current++;
	}
	return res;
}

string transcribe(string s) // transcribe dna
{
	int size = s.length();
	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'T')
			s[i] = 'U';
	}
	return s;
}

string reversecompl(string s) // обратное дополнение к днк
{
	int size = s.length();
	string res = "";
	for (int i = (size - 1); i >= 0; i--)
	{
		if (s[i] == 'T')
			res += 'A';
		else if (s[i] == 'A')
			res += 'T';
		else if (s[i] == 'G')
			res += 'C';
		else if (s[i] == 'C')
			res += 'G';
	}
	return res;
}

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


/////////////////////////-////////////////////////////////////////////
string task1(string rna)
{
	string res, temp;
	int size = rna.length();
	int i = 0;
	int j = 3;
	while (j <= size)
	{
		for (i; i < j; i++)
		{
			temp += rna[i];
		}
		if (findkodon(temp) == "Z")
			break;
		res += findkodon(temp);
		j += 3;
		temp = "";
	}
	return res;
}

string task2(string dna, string amino)
{
	int amino_size = amino.length();
	int dna_size = dna.length();
	string temp, temp1, temp2, res;
	for (int i = 0; i <= dna_size - 3 * amino_size; i++)
	{
		temp = ""; temp1 = "";
		temp2 = "";
		for (int j = i; j < i + 3 * amino_size; j++)
		{
			temp += dna[j];
		}
		temp1 = temp;
		temp = transcribe(temp1);
		for (int k = 0; k < temp.length(); k ++)
		{
			temp2 += temp[k];
		}
		if (task1(temp2) == amino)
			res += temp1;
		else
		{
			temp2 = "";
			temp = transcribe(reversecompl(temp1));
			for (int k = 0; k < temp.length(); k++)
			{
				temp2 += temp[k];
			}
			if (task1(temp2) == amino)
				res += temp1;
			else
				continue;
		}
	}
	return res;
}

vector<int> task4(string s) // разбиение на субпептиды
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

long long int task5(int cnt)
{
	map<int, long long int> N;
	int m[18] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };
	N[0] = 1;
	for (int i = 57; i < cnt + 1; i++)
	{
		N[i] = 0;
		for (int j = 0; j < 18; j++)
		{
			if (N[i - m[j]] >= 0)
				N[i] += N[i - m[j]];
		}
	}
		return N[cnt];
}