#include "kodons.h"
// testing my tasks --------------------------------------


void main() {
	/*  //task1 ---------------------------------
	string rna;
	string res;
	getline(cin, rna);
	res = task1(rna);
	cout << endl << res;
	*/
	// task2 ------------------------------------
	/*
	string amino, dna, res;
	getline(cin, dna);
	getline(cin, amino);
	res = task2(dna, amino);
	for (int i = 0; i < res.length(); i += 3 * amino.length())
	{
		for (int j = 0; j < (3 * amino.length()); j++)
			cout << res[i + j];
		cout << endl;
	}
	*/
	// task3 -------------------------------------
	/*
	long int n;
	cin >> n;
	cout << n * (n - 1);
	*/
	// task4----------------------------------
	//string temp;
	//vector<int> cur;
	//getline(cin, temp);
	//int size = temp.length();
	//int N = size * (size - 1) + 2;
	//cur = task4(temp);
	////cur = task3(temp);
	//for (int i = 0; i < N; i++)
	//	cout << cur[i] << " ";
	// task5 ------------------------------------
	long long int a;
	cin >> a;
	cout << task5(a);
}