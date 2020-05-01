using namespace std;

template <typename Iterator, typename T>
Iterator find_(Iterator begin, Iterator end, const T& elem) {
    Iterator curr = begin;
    while (curr != end && *curr != elem) {
        ++curr;
    }
    return curr;
}