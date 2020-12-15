/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 07/06/2020
WS2P2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include <cstdio> //including C library
#include <cstring> //for strcpy()
#include "Gift.h" //including the header file
#define _CRT_SECURE_NO_WARNINGS

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
		if (theGift.m_wrapLayers <= 0)
		{
			cout << "Unwrapped!" << endl;
		}
		else {

			cout << "Wrap Layers: " << theGift.m_wrapLayers << endl;
			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				cout << "Wrap #" << i + 1 << " -> " << theGift.m_wrap[i].m_pattern << endl;
			}
		}

	}




	bool wrap(Gift& theGift) {

		int value = 0;
		int status = 0;
		if (theGift.m_wrapLayers > 1)
		{
			cout << "Gift is already wrapped!" << endl;
			status = 1;
		}
		else {
			cout << "Wrapping gifts..." << endl;
			cout << "Enter the number of wrapping layers for the Gift: ";
			cin >> theGift.m_wrapLayers;

			while (theGift.m_wrapLayers <= 0)
			{
				cout << "Layers at minimum must be 1, try again." << endl;
				cout << "Enter the number of wrapping layers for the Gift: ";
				cin >> theGift.m_wrapLayers;
			};


			theGift.m_wrap = new Wrapping[theGift.m_wrapLayers]; //allocating dynamic memory 


			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{

				char* tempArr = new char[MAX_WRAP + 1]; //allocating dynamic memory for a temporary array of characters
				cout << "Enter wrapping pattern #" << i + 1 << ": ";
				cin >> tempArr;
				theGift.m_wrap[i].m_pattern = new char[strlen(tempArr) + 1];//allocating dynamic memory with the size of inputted string plus the null byte
				strcpy(theGift.m_wrap[i].m_pattern, tempArr); //moving the data

				delete[] tempArr; //deallocating dynamic memory for all the indexes
				tempArr = nullptr;

			}

			

		}
		if (status == 0) {
			if (theGift.m_wrapLayers < 1)
				value = false;
			else if (theGift.m_wrapLayers > 0)
				value = true;
		}
		else if (status == 1)
		{
			value = false;
		}
		return value;

	}





	bool unwrap(Gift& theGift) {

		int flag = 0;
		if (theGift.m_wrap == 0) {
			cout << "Gift isn't wrapped! Cannot unwrap." << endl;
		}
		else {
			cout << "Gift being unwrapped." << endl;
			
			for (int i = 0; i < theGift.m_wrapLayers; i++)
			{
				delete[] theGift.m_wrap[i].m_pattern; //deallocating dynamic memory
				theGift.m_wrap[i].m_pattern = nullptr;
			}


			delete[] theGift.m_wrap;//deallocating dynamic memory
			theGift.m_wrap = nullptr;


			theGift.m_wrapLayers = 0;


			if (theGift.m_wrap == 0) {
				flag = 1;
			}

		}
		if (flag == 1)
			return true;
		else
			return false;
	}





	void gifting(Gift& theGift) {
		cout << "Preparing a gift..." << endl;
		gifting(theGift.m_description);
		gifting(theGift.m_price);
		gifting(theGift.m_units);
		wrap(theGift);

	}
}

