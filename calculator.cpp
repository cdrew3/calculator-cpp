#include <iostream>
#include "arithmetic.h"

using arithmetic::add;
using namespace std;

int main() {
    float x = 5.5;
    float y = 6.7;
    cout << add(5, 6) << endl;
    cout << add(x, y) << endl;
    return 0;
}