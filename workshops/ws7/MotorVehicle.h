/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 14/7/2020
WS7P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MotorVehicle_H
#define SDDS_MotorVehicle_H

namespace sdds {

	class MotorVehicle {
	private:
		char m_plate[32];
		char m_address[64];
		int m_year;
	public:
		MotorVehicle(const char* plate, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& out) const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& motor);
	std::istream& operator>>(std::istream& in, MotorVehicle& motor);

}

#endif

