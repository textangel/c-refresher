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

int main(int argc, char* argv[]) {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    //ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    cout << "Enter all your homework grades, "
            "followed bu EOF: ";

    vector<double> homework_scores;
    read_hw(cin, homework_scores);
    try {
        double final_grade = grade(midterm, final, homework_scores);
        streamsize perc = cout.precision();
        cout << "Your final grade is " << setprecision(3)
            << final_grade << endl
            << setprecision(perc) << endl;

    } catch (domain_error){
        cout <<endl<< "You must enter your grades.   "
                        "Please try again." << endl;
        return 1;
    }
//     The problem with this rewrite is that although the implementation is required to execute the << operators
//     from left to right, it is not required to evaluate the operands in any specific order. In particular, it might
//     call grade after it writes Your final grade is . If grade throws an exception, then the output might contain that
//     spurious phrase. Moreover, the first call to setprecision might set the output stream's precision to 3 without
//     giving the second call the opportunity to reset the precision to its previous value. Alternatively, the
//     implementation might call grade before writing any output; whether it does so depends entirely on the implementation.
//     This analysis explains why we separated the output block into two statements: The first statement ensures
//     that the call to grade happens before any output is generated.

    return 0;
}
