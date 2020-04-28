#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    std::cout << "Please enter your first name: ";
    std::string name; //define name
    std::cin >> name; //standard input

    const std::string greeting = "Hello, " + name + "!";
    const std::string spaces(greeting.size(), ' ');
    const std::string second = "* " + spaces + " *";
    const std::string first(second.size(), '*');

    //write it all
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;

    { const std::string s = "a string"; std::cout << s << std::endl; }
    { const std::string s = "another string"; std::cout << s << std::endl; }

    { const std::string s = "a string"; std::cout << s << std::endl;
    { const std::string s = "another string"; std::cout << s << std::endl; };}

    std::cout << "What is your name2? ";
    std::string name2;
    std::cin >> name2;
    std::cout << "Hello, " << name2
                << std::endl << "And what is yours? "; std::cin >> name2;
    std::cout << "Hello, " << name2
                << "; nice to meet you too!" << std::endl;

    return 0;


}
