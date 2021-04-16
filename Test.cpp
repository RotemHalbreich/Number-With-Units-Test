#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace ariel;
using namespace std;

ifstream units_file{"units.txt"};