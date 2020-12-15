/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 04/8/2020
MS4
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include <cstring>
#include "Vehicle.h"
#include"Utils.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace sdds {
	Vehicle::Vehicle() : ReadWritable(), m_licensePlate{}, m_makeModel(nullptr), m_parkingSpot(0) {
		setEmpty();
	}

	Vehicle::Vehicle(const char* licensePlate, const char* makeModel) : ReadWritable(), m_licensePlate{}, m_makeModel(nullptr), m_parkingSpot(0){

		if (licensePlate != nullptr && licensePlate[0] != '\0' && strlen(licensePlate) <= 8 && makeModel != nullptr && strlen(makeModel) >= 2) {

			strncpy(m_licensePlate, licensePlate, 8);
			Vehicle::setMakeModel(makeModel);
		}
		else {
			setEmpty();
		}
	}
	Vehicle::~Vehicle() {
		delete[] m_makeModel;
	}
	void Vehicle::setEmpty() {
		delete[] m_makeModel;
		m_makeModel = nullptr;
		m_licensePlate[0] = 0;
		m_parkingSpot = -1;
	}
	bool Vehicle::isEmpty()const {
		return m_makeModel == nullptr;
	}
	const char* Vehicle::getLicensePlate()const {
		return m_licensePlate;
	}
	const char* Vehicle::getMakeModel()const {
		return m_makeModel;
	}
	void Vehicle::setMakeModel(const char* value) {
		if (value != nullptr && value[0] != '\0') {

			delete[] m_makeModel;
			m_makeModel = nullptr;
			m_makeModel = new char[strlen(value) + 1];
			strcpy(m_makeModel, value);
		}
		else
			setEmpty();
	}
	int Vehicle::getParkingSpot() const {
		return m_parkingSpot;
	}
	void Vehicle::setParkingSpot(int value) {
		if (value < 0)
			setEmpty();
		else
			m_parkingSpot = value;
	}
	bool Vehicle::operator==(const char* licensePlate) const {
		bool identical = false;
		char temp[9];

		if (!isEmpty() && licensePlate != nullptr) {
			
			strcpy(temp, licensePlate);
			Utils::toUpper(temp);
			if (strcmp(licensePlate, temp) == false)
				identical = false;
			identical = true;

		}
		return identical;
	}
	bool Vehicle::operator==(const Vehicle& v) const {
		return operator==(v.m_licensePlate);
	}
	std::istream& Vehicle::read(std::istream& istr) {
		
		char temp[61];

		if (isCsv()) {
			istr >> m_parkingSpot;
			istr.ignore();
			istr.getline(m_licensePlate, 9, ',');
			Utils::toUpper(m_licensePlate);
			istr.getline(temp, 61, ',');
			setMakeModel(temp);
		}
		else {
			cout << "Enter Licence Plate Number: ";
			Utils::read(m_licensePlate, 1, 8, "Invalid Licence Plate, try again: ");
			Utils::toUpper(m_licensePlate);
			cout << "Enter Make and Model: ";
			Utils::read(temp, 2, 60, "Invalid Make and model, try again: ");
			setMakeModel(temp);
			m_parkingSpot = 0;
		}

		if (istr.fail()) {
			istr.clear();
			istr.ignore(2000, '\n');
			setEmpty();
		}

		return istr;
	}
	std::ostream& Vehicle::write(std::ostream& ostr) const {

		if (isEmpty())
			ostr << "Invalid Vehicle Object" << endl;
		else if (isCsv()) {

			ostr << getParkingSpot() << "," << getLicensePlate() << "," << getMakeModel() << ",";
		}
		else {

			ostr << "Parking Spot Number: ";
			if (getParkingSpot() == 0)
				ostr << "N/A" << endl;
			else
				ostr << getParkingSpot() << endl;

			ostr << "Licence Plate: " << getLicensePlate() << endl;
			ostr << "Make and Model: " << getMakeModel() << endl;
		}

		return ostr;
	}
}