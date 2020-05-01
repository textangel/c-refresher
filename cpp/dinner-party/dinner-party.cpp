#include "couple.h"
#include <iostream>

using std::endl; using std::cout;

int main(int argc, char *argv[]) {
    int kNumCouples = 3;

    couple hosts("Colleen", "Joe");
    assert(hosts.getFirst() == "Colleen");
    assert(hosts.getSecond() == "Joe");
    couple guests[kNumCouples]; // works only because we provide a zero-argument constructor assert(guests[0].getFirst().empty());

    guests[0] = couple("Robin", "Jamie");
    guests[1] = couple("April", "Chris");
    guests[2] = couple("Jennifer", "Andrew");
    cout << "Dinner party guest list: " << endl;
    cout << "Hosts:  " << hosts << endl;
    for (const couple& c: guests) { // C++11 for loop works because context provides array lengthi
        cout << "Guests: " << c << endl;
    }
    cout << endl;
    cout << "We're serving duck!" << endl;
    return 0;
}
