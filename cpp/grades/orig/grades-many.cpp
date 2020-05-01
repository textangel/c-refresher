#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <stdexcept>
using std::accumulate;
using std::cin;  using std::setprecision;
using std::cout; using std::string;
using std::endl;  using std::streamsize;
using std::vector;  using std::sort;
using std::domain_error; using std::istream;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};


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

double median(vector<double> vec){
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 :  vec[mid];
}

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

bool compare(const Student_info &a, const Student_info &b){
    return a.name < b.name;
}

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
