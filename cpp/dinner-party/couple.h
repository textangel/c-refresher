#ifndef GUARD_couple_h
#define GUARD_couple_h

#include <iostream>
#include <string>

using std::string;
using std::ostream;

class couple {
    friend std::ostream& operator<<(std::ostream& os, const couple& c);

    public:
        couple();
        couple(const std::string& one, const std::string& two);
        const std::string& getFirst() const;
        const std::string& getSecond() const;
    private:
        std::string first;
        std::string second;


};

#endif
