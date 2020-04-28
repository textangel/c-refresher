#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"
#include "student-info.h"

using std::domain_error; using std::vector;

double grade(double midterm, double final, double homework){
    return 0.2 * midterm +  0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& homework){
    if (homework.size() == 0)
        throw domain_error("Student has done no homework");
    return grade(midterm, final, median(homework));
}

double grade(const Student_info& s){
    return grade(s.midterm, s.final, s.homework);
}


