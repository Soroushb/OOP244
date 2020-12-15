/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 06/8/2020
MS5
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
namespace sdds {
	class ReadWritable {
	private:
		bool m_csvIO;
	public:
		ReadWritable();
		bool isCsv()const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream& istr = std::cin) = 0;
		virtual std::ostream& write(std::ostream& ostr = std::cout)const = 0;
		virtual ~ReadWritable();
	};
	std::ostream& operator<<(std::ostream& ostr, const ReadWritable& rw);
	std::istream& operator>>(std::istream& istr, ReadWritable& rw);
}	