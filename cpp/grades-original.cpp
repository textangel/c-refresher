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
using std::domain_error;

double grade(double midterm, double final, double homework){
    return 0.2 * midterm +  0.4 * final + 0.4 * homework;
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

    double x;
    vector<double> homework_scores;
    while (cin >> x)
        homework_scores.push_back(x);
    double med = median(homework_scores);
    double count = homework_scores.size();
    double sum = accumulate(homework_scores.begin(), homework_scores.end(),0);
    streamsize perc = cout.precision();
    cout << "Your final grade is " << setprecision(3)
        << grade(midterm, final, sum/count) << endl
        << "Total Homework Scores: " << sum << " Num Homeworks: " << count << endl
        << "Average Homework Score: " << sum / count << " Median Homework Score: " << med
        << setprecision(perc) << endl;

    return 0;
}
