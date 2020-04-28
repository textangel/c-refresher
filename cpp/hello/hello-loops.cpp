#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::string;
using std::cin;

int main(int argc, char *argv[]){
    cout << "Please enter your first name: ";
    string name; //define name
    cin >> name; //standard input

    const string greeting = "Hello, " + name + "!";
    const int pad = 3;
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    cout << endl;

    //write it all
    for (int r=0; r!= rows; ++r) {
        string::size_type c = 0;
        while (c != cols){
            if (r == 0 || r == rows-1 || c == 0 || c == cols-1){
                cout << "*";
                ++c;
            } else if (r == pad + 1 && c == pad + 1){
                cout << greeting;
                c += greeting.size();
            } else {
                cout << " ";
                ++c;
            }
        }
        cout <<endl;
    }
    return 0;
}
