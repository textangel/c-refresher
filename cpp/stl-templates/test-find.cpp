#include "find.cpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int numbers[] = {3, 1, 5, 8, 9, 5};
  assert(find_(numbers, numbers + 6, 3) == numbers);
  assert(find_(numbers, numbers + 6, 9) == numbers + 4);
  assert(find_(numbers, numbers + 6, 5) == numbers + 2);
  assert(find_(numbers, numbers + 6, 7) == numbers + 6);
  assert(find_(numbers + 1, numbers + 3, 3) == numbers + 3);
  double gpas[] = {3.5, 3.1, 3.6, 3.2, 1.7, 3.0, 2.8, 3.1, 3.22};
  assert(find_(gpas, gpas + 9, 3.6) == gpas + 2);
  assert(find_(gpas, gpas + 9, 3.22) == gpas + 8);
  assert(find_(gpas, gpas + 9, 1.1) == gpas + 9);
  assert(find_(gpas + 4, gpas + 5, 1.7) == gpas + 4);
  string friends[] = {"Scott", "Jon", "Arlene", "David", "Tim", "Shana", "James", "Lisa"};
  assert(find_(friends, friends + 8, "Shana") == friends + 5);
  cout << "Made it to the end without asserting." << endl;
return 0; }