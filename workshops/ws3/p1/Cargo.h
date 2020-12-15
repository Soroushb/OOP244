/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 09/06/2020 / after a little change -> 10/06/2020
WS3P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CARGO_H 
#define SDDS_CARGO_H


namespace sdds {


	const int MAX_DESC = 20;


	struct Cargo {
     
		char name[MAX_DESC + 1];
		double weight;

	};


}



#endif