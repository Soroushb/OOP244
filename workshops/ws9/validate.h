/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 27/7/2020
WS9P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef VALIDATE_H
#define VALIDATE_H


template<typename T>
bool validate(const T& minimum, const T testValue[], const int& count, bool booleans[] = true) {
	bool check = true;
	for (int i = 0; i < count; i++) {
		if (minimum <= testValue[i]) {
			booleans[i] = true;
		}
		else {

			booleans[i] = false;
			check = false;
		}
	}
	return check;
	
}
#endif // !SDDS_VALIDATE_H