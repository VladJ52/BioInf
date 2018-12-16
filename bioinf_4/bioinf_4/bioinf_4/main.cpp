#include "task.h"

int main()
{
	int k, d, n = 0;
	cin >> k >> d;
	string temp;
	vector<string> dna;
	string res = "";
	while (n <= 4)
	{
		getline(cin, temp);
		dna.push_back(temp);
		n++;
		if (temp == "")
			dna.pop_back();
	}
	res = task1(dna, k, d);
	cout << res;
	return 0;
}
