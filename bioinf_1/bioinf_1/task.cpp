#include "task.h"





void main()
{
	//---------------------------------first_task--------------------------------------------//
	string pattern, genome;
	cout << "Enter the pattern" << endl;
	getline(cin, pattern);
	cout << endl << "Enter the genome" << endl;
	getline(cin, genome);
	cout << endl << "Answer of the first task is: " << task1(pattern, genome) << endl;
	//--------------------------------second_task-----------------------------------------//
	string genome1;
	int si;
	cout << endl << "Enter the genome" << endl;
	getline(cin, genome1);
	cout << endl << "Enter the size of pattern" << endl;
	cin >> si;
	cout << endl << "Answer of the second task is: " << task2(genome1,si) << endl;
	//---------------------------------third_task--------------------------------------------//
	string genome2,res;
	getline(cin, genome2);
	cout << endl << task3(genome2);
}