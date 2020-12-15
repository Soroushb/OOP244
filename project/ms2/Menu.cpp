/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 28/7/2020
MS2
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {

	MenuItem::MenuItem() {
		m_value = nullptr;
	}

	MenuItem::MenuItem(const char* value) : m_value(nullptr) {
		if (value != nullptr) {
			m_value = new char[strlen(value) + 1];
			strcpy(m_value, value);
		}
	}
	MenuItem::~MenuItem() {
		delete[] m_value;
		m_value = nullptr;
	}
	void MenuItem::display() const {
		if (m_value != nullptr)
		{
			cout << m_value << endl;
		}
	}
	void Menu::indent() const {
		for (int i = 0; i < m_indentation; i++)
		{
			cout << "    ";
		}
	}
	void Menu::clear() {
		for (int i = 0; i < m_noOfItems; i++)
		{
			delete m_items[i];
			m_items[i] = nullptr;
		}
		delete[] m_title;
		m_title = nullptr;
		m_noOfItems = 0;
		m_indentation = 0;
	}

	Menu::Menu(const char* title, int indentation) :
		m_title(nullptr),
		m_items{ nullptr },
		m_noOfItems(0),
		m_indentation(indentation) {
		*this = title;
	}



	Menu::Menu(const Menu& M) :
		m_title(nullptr),
		m_items{ nullptr },
		m_noOfItems(0),
		m_indentation(M.m_indentation) {
		*this = M;
	}


	Menu& Menu::operator=(const Menu& M) {
		if (this != &M) {
			clear();
			if (!M.isEmpty()) {
				*this = M.m_title;
				for (int i = 0; i < M.m_noOfItems; i++)
				{
					add(M.m_items[i]->m_value);
				}
				m_indentation = M.m_indentation;
			}
		}
		return *this;
	}

	Menu& Menu::operator=(const char* title) {
		if (title == nullptr) {
			clear();
		}
		else {
			delete[] m_title;
			m_title = nullptr;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
		return *this;
	}
	Menu::~Menu() {
		clear();
	}
	void Menu::add(const char* item) {
		if (!isEmpty() && m_noOfItems < MAX_NO_OF_ITEMS) {
			if (item != nullptr) {
				m_items[m_noOfItems] = new MenuItem(item);
				m_noOfItems += 1;
			}
			else {

				clear();
			}
		}
	}

	Menu& Menu::operator<<(const char* item) {
		add(item);
		return *this;
	}
	void Menu::display() const {
		if (isEmpty()) {
			cout << "Invalid Menu!" << endl;
		}
		else {
			indent();
			cout << m_title << endl;
			if (m_noOfItems == 0) {
				cout << "No Items to display!" << endl;
			}
			else {
				for (int i = 0; i < m_noOfItems; i++)
				{
					indent();
					cout << i + 1 << "- ";
					m_items[i]->display();

				}
				indent();
				cout << "> ";
			}
		}
	}
	Menu::operator int() const {
		return run();
	}
	Menu::operator bool() const {
		return !isEmpty();
	}
	bool Menu::isEmpty() const {
		return (m_title == nullptr);
	}
	int Menu::run() const {
		int selection = 0;
		this->display();
		if (!isEmpty() && m_noOfItems > 0)
			Utils::read(selection, 1, m_noOfItems, "Invalid selection, try again: ");
		return selection;
	}
}