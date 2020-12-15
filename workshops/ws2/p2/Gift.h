

/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 02/06/2020
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_GIFT_H // replace with relevant names 
#define SDDS_GIFT_H



namespace sdds {

	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.999;
	const int MAX_WRAP = 20;

	struct Wrapping {

		char* m_pattern;
	};

	struct Gift {
		Wrapping* m_wrap;
		char m_description[MAX_DESC + 1];
		double m_price;
		int m_units;
		int m_wrapLayers;
	};

	

	void gifting(char* desc);
	void gifting(double& price);
	void gifting(int& units);
	void display(const Gift& theGift);
	bool wrap(Gift& theGift);
	bool unwrap(Gift& theGift);
	void gifting(Gift& theGift);
	void display(const Gift& theGift);

}

#endif