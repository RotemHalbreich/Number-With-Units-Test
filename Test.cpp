#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace ariel;
using namespace std;

ifstream file{"units.txt"};

TEST_CASE("Arithmetic operators test:")
{
    NumberWithUnits::read_units(file);
    NumberWithUnits km{1, "km"};
    NumberWithUnits m{3, "m"};
    NumberWithUnits cm{4, "cm"};
    NumberWithUnits ton{6, "ton"};
    NumberWithUnits kg{8, "kg"};
    NumberWithUnits g{1, "g"};
    NumberWithUnits hour{1, "hour"};
    NumberWithUnits min{15, "min"};
    NumberWithUnits sec{1, "sec"};
    NumberWithUnits USD{100, "USD"};
    NumberWithUnits ILS{9.99, "ILS"};

    //Addition (num1 + num2)
    CHECK((km + m) == NumberWithUnits{1.003, "km"});
    CHECK((m + cm) == NumberWithUnits{3.04, "m"});
    CHECK((hour + min) == NumberWithUnits{1.25, "hour"});
    CHECK((hour) == NumberWithUnits{75, "min"});

    //Subtraction (num1 - num2)
    CHECK((hour - min) == NumberWithUnits{60, "min"});
    CHECK((hour) == NumberWithUnits{1, "hour"});

    //Increment & Decrement (prefix & postfix)
    CHECK(min++ == NumberWithUnits{15, "min"});
    CHECK(min == NumberWithUnits{0.25, "hour"});
    CHECK(min == NumberWithUnits{15, "min"});
    CHECK(++min == NumberWithUnits{16, "km"});
    CHECK(min == NumberWithUnits{16, "km"});
    CHECK(USD-- == NumberWithUnits{100, "USD"});
    CHECK(USD == NumberWithUnits{99, "USD"});
    CHECK((USD + ILS) == NumberWithUnits{102, "USD"});
    CHECK(--USD == NumberWithUnits{98, "km"});
    CHECK(USD == NumberWithUnits{98, "USD"});

    //Multiplication (both directions)
    CHECK((cm * 0.75) == NumberWithUnits{0.03, "m"});
    CHECK((13.6 * cm) == NumberWithUnits{0.408, "m"});
    CHECK(cm == NumberWithUnits{408, "cm"});

    //Addition & Subtraction assignment ( += / -= )
    CHECK((ton += kg) == NumberWithUnits{6.008, "ton"});
    CHECK(ton == NumberWithUnits{6.008, "ton"});
    CHECK((kg += ton) == NumberWithUnits{6016, "kg"});
    CHECK(kg == NumberWithUnits{6016000, "g"});
    CHECK((ton -= kg) == NumberWithUnits{-0.008, "ton"});
    CHECK(ton == NumberWithUnits{-0.008, "ton"});
    CHECK((kg -= ton) == NumberWithUnits{6024, "kg"});
    CHECK(kg == NumberWithUnits{6024000, "g"});
}

TEST_CASE("Logical operators test:")
{
    //Greater than (>)
    NumberWithUnits::read_units(file);
    CHECK_GT(NumberWithUnits{7.001, "ton"}, NumberWithUnits{7000, "kg"});
    CHECK(NumberWithUnits{7.001, "ton"} > NumberWithUnits{7000, "kg"});

    //Greater than or equal (>=)
    CHECK_GE(NumberWithUnits{7.001, "ton"}, NumberWithUnits{7000, "kg"});
    CHECK(NumberWithUnits{7.001, "ton"} >= NumberWithUnits{7000, "kg"});
    CHECK_GE(NumberWithUnits{7, "ton"}, NumberWithUnits{7000000, "g"});
    CHECK(NumberWithUnits{7, "ton"} >= NumberWithUnits{7000000, "g"});

    //Less than (<)
    CHECK_LT(NumberWithUnits{13, "km"}, NumberWithUnits{2000, "m"});
    CHECK(NumberWithUnits{13, "km"} < NumberWithUnits{2000, "m"});

    //Less than or equal (<=)
    CHECK_LE(NumberWithUnits{6.66, "ILS"}, NumberWithUnits{2, "USD"});
    CHECK(NumberWithUnits{6.66, "ILS"} <= NumberWithUnits{2, "USD"});
    CHECK_LE(NumberWithUnits{6.11, "ILS"}, NumberWithUnits{2, "USD"});
    CHECK(NumberWithUnits{6.11, "ILS"} <= NumberWithUnits{2, "USD"});

    //Equal (==)
    CHECK_EQ(NumberWithUnits{6.66, "ILS"}, NumberWithUnits{2, "USD"});
    CHECK(NumberWithUnits{6.66, "ILS"} == NumberWithUnits{2, "USD"});

    //Not equal (!=)
    CHECK_NE(NumberWithUnits{1999, "g"}, NumberWithUnits{2, "kg"});
    CHECK(NumberWithUnits{1999, "g"} != NumberWithUnits{2, "kg"});
}

TEST_CASE("Stream I/O test:")
{
    NumberWithUnits::read_units(file);
}