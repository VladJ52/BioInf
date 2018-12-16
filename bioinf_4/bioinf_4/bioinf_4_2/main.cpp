#include "task2.h"

int main()
{
	int k;
	cin >> k;
	string temp;
	vector<string> dna;
	string res = "";
	while (!cin.eof())
	{
		cin >> temp;
		dna.push_back(temp);
	}
	dna.pop_back();
	res = task2(dna, k);
	cout << res;
	return 0;
}