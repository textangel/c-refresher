#include "couple.h"
#include <string>
#include <iostream>

using std::string;
using std::ostream;

couple::couple() {}
couple::couple(const string& one, const string& two) : first(one), second(two) {}

const string& couple::getFirst() const { return first; }
const string& couple::getSecond() const { return second; }

ostream& operator<<(ostream& os, const couple& c) { // note this is a function!!! i
    os << c.first << " and " << c.second;
return os;
}