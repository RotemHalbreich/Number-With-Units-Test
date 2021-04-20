#pragma once
#include <iostream>
#include <string>

namespace ariel
{
    class NumberWithUnits
    {
    private:
        double quantity;
        std::string unit;

    public:
        NumberWithUnits(double quantity, std::string unit)
        {
            this->quantity = quantity;
            this->unit = unit;
        }

        ~NumberWithUnits() {}

        static void read_units(std::ifstream &file);

        //Addition and Subtraction operators:
        friend NumberWithUnits operator+(NumberWithUnits const &num1, NumberWithUnits const &num2);
        friend NumberWithUnits &operator+=(NumberWithUnits &num1, NumberWithUnits const &num2);
        friend NumberWithUnits &operator+(NumberWithUnits &num);
        friend NumberWithUnits operator-(NumberWithUnits const &num1, NumberWithUnits const &num2);
        friend NumberWithUnits &operator-=(NumberWithUnits &num1, NumberWithUnits const &num2);
        friend NumberWithUnits &operator-(NumberWithUnits &num);

        //Comparison operators:
        friend bool operator>(NumberWithUnits const &num1, NumberWithUnits const &num2);
        friend bool operator>=(NumberWithUnits const &num1, NumberWithUnits const &num2);
        friend bool operator<(NumberWithUnits const &num1, NumberWithUnits const &num2);
        friend bool operator<=(NumberWithUnits const &num1, NumberWithUnits const &num2);
        friend bool operator==(NumberWithUnits const &num1, NumberWithUnits const &num2);
        friend bool operator!=(NumberWithUnits const &num1, NumberWithUnits const &num2);

        //Increment and Decrement operators:
        friend NumberWithUnits &operator++(NumberWithUnits &num);
        friend NumberWithUnits operator++(NumberWithUnits &num, int);
        friend NumberWithUnits &operator--(NumberWithUnits &num);
        friend NumberWithUnits operator--(NumberWithUnits &num, int);

        //Multiplication operators:
        friend NumberWithUnits operator*(double const num1, NumberWithUnits const &num2);
        friend NumberWithUnits operator*(NumberWithUnits const &num1, double const num2);

        //Input and Output operators:
        friend std::istream &operator>>(std::istream &is, NumberWithUnits const &num);
        friend std::ostream &operator<<(std::ostream &os, NumberWithUnits const &num);
    };
}