#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> convsto(string s)
{
	string temp;
	vector<int> res;
	for (int i = 0; i < s.length(); i++)
	{
		while (s[i] != ',' && i < s.length())
		{
			temp += s[i];
			i++;
		}
		res.push_back(atoi(temp.c_str()));
		temp = "";
	}
	return res;
}

int task1(int money, string s)
{
	vector<int> coins, cnt;
	coins = convsto(s);
	sort(coins.begin(), coins.end());
	int mincnt = 0;
	for (int i = 0; i <= money; i++)
	{
		cnt.push_back(0);
	}
	for (int i = coins[0]; i <= money; i++)
	{
		int min = 100000;
		for (int j = 0; j < coins.size(); j++)
		{
			if (i == coins[j])
			{
				cnt[i] = 1;
				break;
			}
			else if (i - coins[j] >= 0 && cnt[i - coins[j]] < min)
			{
				cnt[i] = cnt[i - coins[j]] + 1;
				min = cnt[i - coins[j]];
			}
		}
	}
	mincnt = cnt[money];
	return mincnt;
}