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
using namespace std;
#include "Utils.h"

namespace sdds {
    void Utils::read(int& val, int min, int max, const char* ErrorMess) {
        bool ok;
        char newline;
        const char* orgMes = ErrorMess;
        const char invalidInt[] = "Invalid Integer, try again: ";
        do {
            cin >> val;
            newline = cin.get();
            if (cin.fail() || newline != '\n') {
                ok = false;
                cin.clear();
                cin.ignore(1000, '\n');
                ErrorMess = invalidInt;
            }
            else {
                ok = val <= max && val >= min;
                ErrorMess = orgMes;
            }
        } while (!ok && cout << ErrorMess);
    }
    void Utils::read(
        long long& val,
        long long min,
        long long max, const char* ErrorMess) {
        bool ok;
        char newline;
        do {
            cin >> val;
            newline = cin.get();
            if (cin.fail() || newline != '\n') {
                ok = false;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                ok = val <= max && val >= min;
            }
        } while (!ok && cout << ErrorMess);
    }
    void Utils::read(char* str, int len, const char* errorMessage) {
        bool ok;
        do {
            ok = true;
            cin.getline(str, std::streamsize(len) + 1, '\n');
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                ok = false;
            }
        } while (!ok && cout << errorMessage);
    }
    void Utils::read(char* str, int minlen, int maxlen, const char* errorMessage) {
        do {
            read(str, maxlen, errorMessage);
        } while (strlen(str) < size_t(minlen) && cout << errorMessage);
    }
    bool Utils::yes() {
        char res;
        char newline;
        do {
            res = cin.get();
            newline = cin.get();
            if (newline != '\n') {
                cin.ignore(1000, '\n');
                res = 'x';
            }
        } while (res != 'y' && res != 'Y' && res != 'n' && res != 'N'
            && cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ");
        return res == 'y' || res == 'Y';
    }
    bool Utils::confirmed(const char* action) {
        cout << "This will " << action << '!' << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        return yes();
    }
    char* Utils::read(istream& is) {
        char* data = new char[ReadBufferSize];
        char* str = data;
        int noOfBuffers = 1;
        bool done;
        do {
            done = true;
            cin.getline(str, ReadBufferSize, '\n');
            if (cin.fail()) {
                noOfBuffers++;
                char* temp = new char[(ReadBufferSize - 1) * noOfBuffers + 1];
                strcpy(temp, data);
                delete[] data;
                data = temp;
                str = data + (ReadBufferSize - 1) * (noOfBuffers - 1);
                cin.clear();
                done = false;
            }
        } while (!done);
        return data;
    }
}