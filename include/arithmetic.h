
#include <map>
using namespace std;

namespace arithmetic {

    template <class T>
    T add(T x, T y) { return x + y; }

    template <class T>
    T sub(T x, T y) { return x - y; }

    template <class T>
    T mul(T x, T y) { return x * y; }

    template <class T>
    T div(T x, T y) { return x / y; }
}