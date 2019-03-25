#pragma once

#include <string>
#include <vector>

using namespace std;

vector<vector<double>> getprofile1(vector<vector<double>> old, string add) // laplace rule
{
	for (int i = 0; i < add.length(); i++)
	{
		if (add[i] == 'A')
		{
			old[i][0] += 1.0;
		}
		else if (add[i] == 'C')
		{
			old[i][1] += 1.0;
		}
		else if (add[i] == 'G')
		{
			old[i][2] += 1.0;
		}
		else if (add[i] == 'T')
		{
			old[i][3] += 1.0;
		}
	}
	return old;
}

vector<vector<double>> proflap(vector<vector<double>> old, string add)
{
	int dsecond = 0;
	for (int i = 0; i < add.length(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			old[i][j] += 1;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		dsecond += old[0][i];
	}
	for (int i = 0; i < add.length(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			old[i][j] = old[i][j] / dsecond;
		}
	}

	return old;
}

string findbestmotif(vector<vector<double>> matd, string dna, int k)
{
	string res = "", temp = "";
	double max = -1.0, curmax = 1.0;
	int n = 0;
	for (n; n <= (dna.length() - k); n++)
	{
		for (int i = n; i < (n + k); i++)
		{
			temp += dna[i];
		}
		for (int i = 0; i < k; i++)
		{
			if (temp[i] == 'A')
			{
				curmax = curmax * matd[i][0];
			}
			else if (temp[i] == 'C')
			{
				curmax = curmax * matd[i][1];
			}
			else if (temp[i] == 'G')
			{
				curmax = curmax * matd[i][2];
			}
			else if (temp[i] == 'T')
			{
				curmax = curmax * matd[i][3];
			}
		}
		if (curmax > max)
		{
			max = curmax;
			res = temp;
		}
		temp = "";
		curmax = 1.0;
	}
	return res;
}

int score1(vector<string> motifs, int k)
{
	int res = 0, min;
	int resA = 0, resT = 0, resC = 0, resG = 0;
	string temp;
	for (int j = 0; j < k; j++)
	{
		for (int i = 0; i < motifs.size(); i++)
		{
			temp = motifs[i];
			if (temp[j] != 'A')
				resA++;
			if (temp[j] != 'T')
				resT++;
			if (temp[j] != 'C')
				resC++;
			if (temp[j] != 'G')
				resG++;
		}
		min = resA;
		if (resT < min)
			min = resT;
		if (resC < min)
			min = resC;
		if (resG < min)
			min = resG;
		res += min;
		resT = resG = resA = resC = 0;
	}


	return res;
}

vector<string> task3(vector<string> dna, int k, int t) //жадный поиск мотивов (модифицированный)
{
	vector<string> res;
	vector<string> curmotifs;
	string motif, temp, temp1;
	vector<vector<double>> profile;
	int length = dna[0].length();
	int n = 0;
	int bestscore = 10000000;
	vector<double> tvec;
	for (int i = 0; i < 4; i++)
	{
		tvec.push_back(0.0);
	}

	for (n; n <= length - k; n++)
	{
		temp = dna[0];
		for (int i = 0; i < k; i++)
			profile.push_back(tvec);
		for (int j = n; j < k + n; j++)
		{
			motif += temp[j];
		}
		//motif = "AGGCG";
		curmotifs.push_back(motif);
		for (int i = 0; i < t - 1; i++)
		{
			profile = getprofile1(profile, motif);
			motif = findbestmotif(proflap(profile,motif), dna[i + 1], k);
			curmotifs.push_back(motif);
		}
		if (score1(curmotifs, k) < bestscore)
		{
			bestscore = score1(curmotifs, k);
			res = curmotifs;
		}
		motif = "";
		curmotifs.clear();
		profile.clear();
	}
	return res;
}