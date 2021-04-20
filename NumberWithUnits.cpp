#include <iostream>
#include <fstream>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel
{
    void NumberWithUnits::read_units(ifstream &units_file) {}

    //Addition and Subtraction operators:
    NumberWithUnits operator+(NumberWithUnits const &num1, NumberWithUnits const &num2) { return num1; }
    NumberWithUnits &operator+=(NumberWithUnits &num1, NumberWithUnits const &num2) { return num1; }
    NumberWithUnits &operator+(NumberWithUnits &num) {return num;}
    NumberWithUnits operator-(NumberWithUnits const &num1, NumberWithUnits const &num2) { return num1; }
    NumberWithUnits &operator-=(NumberWithUnits &num1, NumberWithUnits const &num2) {return num1;}
    NumberWithUnits &operator-(NumberWithUnits &num) {return num;}

    //Comparison operators:
    bool operator>(NumberWithUnits const &num1, NumberWithUnits const &num2) { return true; }
    bool operator>=(NumberWithUnits const &num1, NumberWithUnits const &num2) { return true; }
    bool operator<(NumberWithUnits const &num1, NumberWithUnits const &num2) { return true; }
    bool operator<=(NumberWithUnits const &num1, NumberWithUnits const &num2) { return true; }
    bool operator==(NumberWithUnits const &num1, NumberWithUnits const &num2) { return true; }
    bool operator!=(NumberWithUnits const &num1, NumberWithUnits const &num2) { return true; }

    //Increment and Reduction operators:
    NumberWithUnits &operator++(NumberWithUnits &num) {return num;}
    NumberWithUnits operator++(NumberWithUnits &num, int) {return num;}
    NumberWithUnits &operator--(NumberWithUnits &num) {return num;}
    NumberWithUnits operator--(NumberWithUnits &num, int) {return num;}

    //Multiplication operators:
    NumberWithUnits operator*(double const num1, NumberWithUnits const &num2) { return num2; }
    NumberWithUnits operator*(NumberWithUnits const &num1, double const num2) { return num1; }

    //Input and Output operators:
    istream &operator>>(istream &is, NumberWithUnits const &num) { return is; }
    ostream &operator<<(ostream &os, NumberWithUnits const &num) { return os; }
}