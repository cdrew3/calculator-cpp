
#include <map>
using namespace std;

namespace arithmetic {

    bool equal(int, int);
    bool equal(double, double);

    // Addition
    int add(int x, int y) {
        return x + y;
    }
    double add(double x, double y) {
        return x + y;
    }

    // Subtraction
    int sub(int x, int y) {
        return x - y;
    }
    double sub(double x, double y) {
        return x - y;
    }

    // Multiply
    int mul(int x, int y) {
        return x * y;
    }
    double mul(double x, double y) {
        return x * y;
    }

    // Divide
    int div(int x, int y) {
        return x / y;
    }
    double div(double x, double y) {
        return x / y;
    }
}