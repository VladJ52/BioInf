#pragma once

#include <string>
#include <vector>
#include <iterator>

using namespace std;

int mass[18] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };

bool ismass(int a)
{
	bool flag = false;
	for (int i = 0; i < 18; i++)
		if (a == mass[i])
		{
			flag = true;
			break;
		}
	return flag;
}

string sum(string s) // масса пептида
{
	string temp, res = "";
	int a, sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		while (s[i] != '-' && i < s.length())
		{
			temp += s[i];
			i++;
		}
		a = atoi(temp.c_str());
		sum += a;
		temp = "";
	}
	res += to_string(sum);
	return res;
}

bool isin(vector<string> v, string s) // proverka na odinakovie
{
	bool flag = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (s == v[i])
			flag = true;
	}
	return flag;
}

string drop(string pep) // разбиение строки в спектр
{
	int size = pep.length();
	string temp, res = "";
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < size; i++)
	{
		while ((pep[i] != '-') && (i < size))
		{
			temp += pep[i];
			i++;
		}
		v.push_back(atoi(temp.c_str()));
		temp = "";
	}
	int j = 2, s1 = v.size(); int i; int cnt;
	int sum = 0; int n = 1;
	while (j < s1)
	{
		i = n;
		cnt = 0;
		while (cnt != j)
		{
			sum += v[i];
			i++;
			cnt++;
		}
		v.push_back(sum);
		sum = 0;
		if (n < s1-j)
			n++;
		else
		{
			n = 1;
			j++;
		}
	}
	for (int k = 0; k < v.size(); k++)
		res += to_string(v[k]) + "-";
	res.pop_back();
	return res;
}

bool iscons(string spectrum, string s) //consistent?
{
	bool flag = false;
	string temp;
	int count_a = 0, count_a1 = 0;
	vector<int> a, a1;
	string ss="";
	ss = drop(s);
	for (int i = 0; i < spectrum.length(); i++) // спектр
	{
		while ((spectrum[i] != ' ') && (i < spectrum.length()))
		{
			temp += spectrum[i];
			i++;
		}
		a.push_back(atoi(temp.c_str()));
		temp = "";
	}
	for (int i = 0; i < ss.length(); i++)
	{
		while ((ss[i] != '-') && (i < ss.length()))
		{
			temp += ss[i];
			i++;
		}
		a1.push_back(atoi(temp.c_str()));
		temp = "";
	}
	for (int i = 0; i < a1.size(); i++)
	{
		flag = false;
		vector<int> ::iterator iter = a.begin();
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] == a1[i])
			{
				flag = true;
				a.erase(iter += j);
				//i = -1;
				break;
			}
		}
		if (!flag)
			break;
		if (i == a1.size())
			return true;
	}
	return flag;
}

vector<string> expand(vector<string> v, vector<string> v1, string s) // расширение
{
	vector<string> res;
	int size = v.size(); // размер текущего вектора
	int max = size * size;
	int t = size;
	for (int i = 0; t < max; i++) // расширили
	{
		if (i == size)
		{
			i = 0;
		}
		v.push_back(v[i]);
		t++;
	}
	int k = 0;
	int gran = v1.size();
	for (int i = 0; k < v.size(); i++)
	{
		if (i == v1.size())
			i = 0;
		while ((k < gran)&&(k < v.size())) 
		{
			v[k] += "-" + v1[i];
			if ((s.find(sum(v[k])) != -1) && (iscons(s,v[k])) && (!isin(res, v[k])) && (s.find(sum(v[k])) != -1))
			{
				res.push_back(v[k]);
			}
			k++;
		}
		gran += size; ///////////
	}
	return res;
}

// ------------------------------------------------------
vector<string> task1(string spectrum)
{
	int size = spectrum.length();
	string temp;
	int a = 0, t;
	vector <string> v;
	for (int i = 0; i < size; i++)
	{
		t = i;
		while (spectrum[i] != ' ' && i < size)
		{
			temp += spectrum[i];
			i++;
		}
		a = atoi(temp.c_str());
		if (ismass(a))
		{
			v.push_back(temp);
			t = i;
		}
		else
			t = i;
		temp = "";
		i = t;
	}
	vector<string> v1;
	for (int l = 0; l < v.size(); l++)
		v1.push_back(v[l]);
	while (sum(v[0]) != to_string(a) && v.size() != 0)
	{
		v = expand(v, v1, spectrum);
		if (v.size() == 0)
			break;
	}
	return v;
}


//0 97 97 99 101 103 196 198 198 200 202 295 297 299 299 301 394 396 398 400 400 497
//0 99 101 103 113 113 114 128 163 204 212 216 227 227 227 264 291 317 326 330 340 340 367 390 392 431 439 443 454 480 491 495 503 542 544 567 594 594 604 608 617 643 670 707 707 707 718 722 730 771 806 820 821 821 831 833 835 934