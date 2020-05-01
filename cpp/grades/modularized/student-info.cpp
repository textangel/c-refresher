#include "student-info.h"
using std::istream; using std::vector;

bool compare(const Student_info &a, const Student_info &b){
    return a.name < b.name;
}
istream& read_hw(istream& in, vector<double>& hw){
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}
istream& read(istream& is,Student_info& s){
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}

