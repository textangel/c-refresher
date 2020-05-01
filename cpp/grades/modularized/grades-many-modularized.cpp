#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stdexcept>
#include "grading.h"
#include "student-info.h"
using std::accumulate;
using std::cin;  using std::setprecision;
using std::cout; using std::string;
using std::endl;  using std::streamsize;
using std::vector;  using std::sort;
using std::domain_error; using std::istream;

int main(int argc, char* argv[]) {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while(read(cin, record)){
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin()), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size; ++i) {
        cout <<students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');
        try {
            double final_grade = grade(students[i]);
            streamsize perc = cout.precision();
            cout << setprecision(3)
                 << final_grade
                 << setprecision(perc) << endl;

        } catch (domain_error e ){
            cout << e.what() << endl;
        }

    }
    return 0;
}
