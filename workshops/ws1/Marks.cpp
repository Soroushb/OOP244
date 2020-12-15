#include <iostream>
#include <cstdio>
#include "Marks.h"
#include "Utils.h"

using namespace std;

void markStat() {
	char str[50];
	int marks = getInt(5, 50);
	displayHeader();
	cout << "Please enter the assessment name : " << endl;
	cin >> str;
	cout << "Please enter the number of marks : " << endl;
	cin >> marks
}
void displayHeader()
{
	cout << "\nMark Stats Program." << endl;
}

