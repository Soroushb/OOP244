/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 04/8/2020
MS4
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include"ReadWritable.h"


namespace sdds {
	ReadWritable::ReadWritable() {
		m_csvIO = false;
	}

	bool ReadWritable::isCsv() const {
		return m_csvIO;
	}

	void ReadWritable::setCsv(bool value) {
		m_csvIO = value;
	}
	ReadWritable::~ReadWritable() {};

	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw) {
		return rw.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, ReadWritable& rw) {
		return rw.read(istr);
	}

}