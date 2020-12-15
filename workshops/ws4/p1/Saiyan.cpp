/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 17/06/2020
WS4P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include "Saiyan.h" 
#include <cstring> //for strcpy()
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sdds {

	Saiyan::Saiyan() {

		set("", 0, 0, false);
	}

	Saiyan::Saiyan(const char * name, int birthYear, int power) {

		

		if (name != nullptr && strlen(name) != 0 && birthYear > 0 && birthYear <= 2020 && power > 0) {

			set(name, birthYear, power);

		}
		else
			set("", 0, 0, false);
	}

	void Saiyan::set(const char* name, int dob, int power, bool super) {

		strcpy(this->m_name, name);
		this->m_dob = dob;
		this->m_power = power;
		this->m_super = super;

	}

	bool Saiyan::isValid() const {

		bool valid;
		if (this->m_name != nullptr && strlen(this->m_name) != 0 && this->m_dob > 0 && this->m_dob <= 2020 && this->m_power > 0)
		{
			valid = true;
		}
		else
		{
			valid = false;
		}
		return valid;
	}

	void Saiyan::display() const {

		if (!(this->isValid())) {

			cout << "Invalid Saiyan!" << endl;
		}
		else {

			cout << m_name << endl;
			cout << "DOB: " << m_dob << endl;
			cout << "Power: " << m_power << endl;
			if (this->m_super == true) {

				cout << "Super: yes" << endl;
				
			}
			else {

				cout << "Super: no" << endl;
				
			}
			
			
		}

	}

	bool Saiyan::fight(const Saiyan& other) const {

		bool fight;

		if (this->isValid() && other.isValid() && this->m_power > other.m_power) {

			fight = true;
		}
		else
		{
			fight = false;
		}

		return fight;
	}

}
