#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> expand(vector<string> v)
{
	vector<string> alph = { "A", "C", "T", "G" };
	int cnt = 0, size = v.size(), j = 0;
	while (cnt < 3)
	{
		for (int i = 0; i < size; i++)
		{
			v.push_back(v[i]);
		}
		cnt++;
	}
	cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		for (j; j < v.size() && cnt < size; j++)
		{
			v[j] += alph[i];
			cnt++;
		}
		cnt = 0;
	}
	return v;
}

unsigned int d(vector<string> dna, string motifs)
{
	int size = dna.size();
	string temp;
	int sum = 0, cursum = 0, minsum;
	int ep;
	int tt = 0, n = 0;
	for (int i = 0; i < size; i++)
	{
		temp = dna[i];
		//minsum = motifs.length();
		if (motifs.length() == temp.length())
			tt = 1;
		for (int j = 0; j < temp.length() || tt == 1; j++)
		{
			cursum = 0;
			ep = j;
			for (n; n < motifs.length() && j < temp.length(); n++)
			{
				if (motifs[n] != temp[j])
					cursum = cursum + 1;
				j++;
			}
			j = ep;
			tt -= 1;
			if (n != motifs.length())
			{
				n = 0;
				break;
			}
			n = 0;
			if (j == 0)
				minsum = cursum;
			else
			{
				if (cursum < minsum)
					minsum = cursum;
			}
		}
		sum += minsum;
	}
	return sum;
}

string task2(vector<string> dna, int k)
{
	string res = "";
	if (k == 0)
		return res;
	vector<string> motifs = { "A", "C", "G", "T" };
	unsigned int cnt = 0;
	unsigned int temp = 0;
	while (cnt < k - 1)
	{
		motifs = expand(motifs);
		cnt++;
	}
	int size = motifs.size();
	int distance = dna[0].length();
	for (long int i = 0; i < size; i++)
	{
		temp = d(dna, motifs[i]);
		if (distance > temp)
		{
			res = motifs[i];
			distance = temp;
		}
		temp = 0;
	}
	return res;
}