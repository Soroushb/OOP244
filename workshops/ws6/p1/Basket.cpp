/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 7/7/2020
WS6P1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Basket.h" //including header-file

using namespace std;

namespace sdds {

	Basket::Basket() { 
		emptybasket(); 
	}

	Basket::~Basket() { //destructor
		if (m_fruits != nullptr) //if not nullptr
			delete[] m_fruits; //deallocate dynamic memory
		emptybasket(); 
	}

	Basket::Basket(Fruit* objects, int size, double price) { //custom constructor
		emptybasket();
		
		if (objects != nullptr && size > 0 && price > 0.00) { //if valid
			m_fruits = new Fruit[size]; //allocate dynamic memory
			for (int i = 0; i < size; i++) 
			{
				m_fruits[i] = objects[i]; 
			}
			m_cnt = size;
			m_price = price;
		}

	}

	Basket::Basket(const Basket& basket) {
		m_fruits = nullptr;
		m_cnt = basket.m_cnt;
		m_price = basket.m_price;
		if (basket.m_fruits != nullptr && m_cnt > 0)
		{
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = basket.m_fruits[i];
			}
		}

	}

	Basket& Basket::operator=(const Basket& basket) {

		m_cnt = basket.m_cnt;
		m_price = basket.m_price;
		if (basket.m_fruits != nullptr && m_cnt > 0)
		{
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++) {
				m_fruits[i] = basket.m_fruits[i];
			}
		}
		return *this;
	}

	void Basket::setPrice(double price) {
		m_price = price;
	}

	Basket::operator bool() const {
		bool check;
		if (m_fruits != nullptr)
			check = true;
		else
			check = false;
		return check;
	}

	Basket& Basket::operator+=(Fruit fruit) {

		Fruit* newFruit = nullptr;
		newFruit = new Fruit[m_cnt + 1];
		for (int i = 0; i < m_cnt; i++)
		{
			newFruit[i] = m_fruits[i];
		}
		newFruit[m_cnt++] = fruit;
		delete[] m_fruits;
		m_fruits = nullptr;
		m_fruits = newFruit;

		return *this;
		delete[] m_fruits;
		m_fruits = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, const Basket& basket) {

		
		if (basket.m_fruits != nullptr && basket.m_cnt > 0) {
			cout << "Basket Content:" << endl;
			for (int i = 0; i < basket.m_cnt; i++)
			{
				cout.width(10);
				cout << basket.m_fruits[i].m_name << ": ";
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << basket.m_fruits[i].m_qty << "kg" << endl;
			}
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Price: " << basket.m_price << endl;

		}
		else
			cout << "The basket is empty!" << endl;
		return cout;

	}

	void Basket::emptybasket() {

		m_fruits = nullptr;
		m_cnt = 0;
		m_price = 0.00;
	}
}