#pragma once
#include <iostream>
#include <string>

namespace ariel
{
    class NumberWithUnits
    {
    private:
        double quantity;
        string unit;

    public:
        NumberWithUnits(double quantity, std::string unit)
        {
            this->quantity = quantity;
            this->unit = unit;
        }

        ~NumberWithUnits() {}

        static void read_units(std::ifstream &file);

        //Addition and Subtraction operators:
        friend NumberWithUnits operator+(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend NumberWithUnits operator+=(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend NumberWithUnits operator+(const NumberWithUnits &num);
        friend NumberWithUnits operator-(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend NumberWithUnits operator-=(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend NumberWithUnits operator-(const NumberWithUnits &num);

        //Comparison operators:
        friend bool operator>(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend bool operator>=(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend bool operator<(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend bool operator<=(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend bool operator==(const NumberWithUnits &num1, const NumberWithUnits &num2);
        friend bool operator!=(const NumberWithUnits &num1, const NumberWithUnits &num2);

        //Increment and Reduction operators:
        friend NumberWithUnits operator++(const NumberWithUnits &num);
        friend NumberWithUnits operator--(const NumberWithUnits &num);

        //Multiplication operators:
        friend NumberWithUnits operator*(double num1, const NumberWithUnits &num2);
        friend NumberWithUnits operator*(const NumberWithUnits &num1, double num2);

        //Input and Output operators:
        friend istream &operator>>(istream &is, const NumberWithUnits &num);
        friend ostream &operator<<(ostream &os, const NumberWithUnits &num);
    };
}