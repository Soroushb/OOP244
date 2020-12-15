/*
Name: Soroush Bahrami
Seneca Email: sbahrami7@myseneca.ca
Student ID: 152499182
date: 15/7/2020
MS1
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__
#include <iostream>
namespace sdds {
    const unsigned int ReadBufferSize = 40;
    struct Utils {
        static void read(int& val, int min, int max, const char* errorMessage = "");
        static void read(long long& val, long long min, long long max, const char* errorMessage = "");
        static void read(char* str, int len, const char* errorMessage = "");
        static void read(char* str, int minlen, int maxlen, const char* errorMessage = "");
        static char* read(std::istream& is = std::cin);
        static bool yes();
        static bool confirmed(const char* action);
    };
}
#endif // !
