/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 20/06/2020
WS4P2
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

		empty();
	}

	Saiyan::Saiyan(const char* name, int birthYear, int power) {



		if (name != nullptr && strlen(name) != 0 && birthYear > 0 && birthYear <= 2020 && power > 0) {


			empty();
			set(name, birthYear, power);

		}
		else

			empty();
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {


		delete[] m_name;
		m_name = nullptr;


		m_name = new char[strlen(name) + 1];
		strcpy(this->m_name, name);
		this->m_dob = dob;
		this->m_power = power;
		this->m_super = super;
		this->m_level = level;



	}

	void Saiyan::empty() {
		
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_level = 0;
		m_super = false;
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
			cout.width(10);
			cout << "DOB: " << m_dob << endl;
			cout.width(10);
			cout << "Power: " << m_power << endl;
			if (this->m_super == true) {

				cout.width(10);
				cout << "Super: " << "yes" << endl;

			}
			else {

				cout.width(10);
				cout << "Super: " << "no" << endl;

			}
			if (this->m_level != 0) {

				cout.width(10);
				cout << "Level: " << this->m_level << endl;

			}


		}

	}

	bool Saiyan::fight(Saiyan& other) {

		bool fight;

		if (this->m_level > 0) {

			this->m_power = this->m_level * 0.1 * this->m_power + this->m_power;
		}
		if (other.m_level > 0) {

			other.m_power = other.m_level * 0.1 * other.m_power + other.m_power;
		}

		if (this->isValid() && other.isValid() && this->m_power > other.m_power) {



			fight = true;


		}
		else
		{
			fight = false;

		}


		return fight;
	}

	Saiyan::~Saiyan() {


		delete[] m_name;
		m_name = nullptr;

		m_power = 0;
		m_dob = 0;
		m_level = 0;
		m_super = false;
	}
}


