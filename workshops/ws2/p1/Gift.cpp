/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 02/06/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include "Gift.h"

using namespace std;

namespace sdds {

	double max = MAX_PRICE;

	void gifting(char* desc) {


		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}

	void gifting(double& price) {

		cout << "Enter gift price: ";
		cin >> price;
		while (price < 0 || price > MAX_PRICE) {
			cout << "Gift price must be between 0 and " << max << endl;
			cout << "Enter gift price: ";
			cin >> price;
		}
	}

	void gifting(int& units) {

		cout << "Enter gift units: ";
		cin >> units;
		while (units < 1)
		{
			cout << "Gift units must be at least 1" << endl;
			cout << "Enter gift units: ";
			cin >> units;
		}
	}
	void display(const Gift& theGift) {


		cout << "Gift Details:" << endl;
		cout << " Description: " << theGift.m_description << endl;
		cout.width(14);
		cout << "Price: " << theGift.m_price << endl;
		cout.width(14);
		cout << "Units: " << theGift.m_units << endl;
		cout << "\n";
	}
}

