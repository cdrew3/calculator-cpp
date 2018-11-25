#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include "arithmetic.h"

using namespace std;
using namespace arithmetic;
using std::to_string;

#define TOLERANCE (1.0E-6)

void printPassPass(string, string, string, string); // Should pass, passes
void printPassFail(string, string, string, string, string); // Should pass, fails
void printFailPass(string, string, string, string); // Should fail, passes
void printFailFail(string, string, string, string, string); // Should fail, fails
void testAdd();
void testSub();
bool equal (int, int, double);
bool equal (float, float, double);
bool assertEqual(int, int, int, int (*f)(int, int));
bool assertEqual(float, float, float, int (*f)(float, float));

int main() {

    if (assertEqual(3, 4, 9, add)) {
        cout << "SUCCESS!!!" << endl;
    } else {
        cout << "FAILURE!!!" << endl;
    }
}

bool assertEqual(int a, int b, int c, int (*f)(int, int)) {

    string test = "Testing " + to_string(a) + " + " + to_string(b) + " = "  + to_string(c);
    cout << test << endl;
    return equal((*f)(a, b), c, TOLERANCE);
}

int main_not() {
    testAdd();
    testSub();
}

bool equal (int x, int y, double tolerance) {

    double avg = (x + y) / 2;
    double epsilon = avg * tolerance;
    double absDiff = fabs(x - y);

    if (absDiff < epsilon) {
        return true;
    } else {
        return false;
    }
}

bool equal (float x, float y, double tolerance) {

    double avg = (x + y) / 2;
    double epsilon = avg * tolerance;
    double absDiff = fabs(x - y);

    if (absDiff < epsilon) {
        return true;
    } else {
        return false;
    }
}

void printPassPass(string op, string x, string y, string val_act) {
    cout << "PASSED: " << x <<  " " << op << " " << y << " = " << val_act << endl;
}
void printPassFail(string op, string x, string y, string val_exp, string val_act) {
    cout << "FAILED: " << x <<  " " << op << " " << y << " = " << val_act << " (Should be " << val_exp << ")" << endl;
}
void printFailPass(string op, string x, string y, string val_act) {
    cout << "PASSED: " << x <<  " " << op << " " << y << " != " << val_act << endl;
}
void printFailFail(string op, string x, string y, string val_exp, string val_act) {
    cout << "FAILED: " << x <<  " " << op << " " << y << " != " << val_act << " (Should not be " << val_exp << ")" << endl;
}

void testAdd() {

    string op = "+";

    // Should pass, integer
    int x = 2;
    int y = 3;
    int z_act = arithmetic::add(x, y);
    int z_exp = x + y;

    if (equal(z_act, z_exp, TOLERANCE)) {
        printPassPass(op, to_string(x), to_string(y), to_string(z_act));
    } else {
        printPassFail(op, to_string(x), to_string(y), to_string(z_act), to_string(z_exp));
    }

    // Shoulld fail, integer
    x = 7;
    y = 14;
    z_act = arithmetic::add(x, y);
    z_exp = x + y + 2;

    if (!equal(z_act, z_exp, TOLERANCE)) {
        printFailPass(op, to_string(x), to_string(y), to_string(z_exp));
    } else {
        printFailFail(op, to_string(x), to_string(y), to_string(z_exp), to_string(z_exp));
    }

    // Should pass, float
    float a = 2.3;
    float b = 8.1;
    float c_act = arithmetic::add(a, b);
    float c_exp = a + b;

    if (equal(c_act, c_exp, TOLERANCE)) {
        printPassPass(op, to_string(a), to_string(b), to_string(c_exp));
    } else {
        printPassFail(op, to_string(a), to_string(b), to_string(c_exp), to_string(c_act));
    }

    // Should fail, float
    a = 12.3;
    b = 18.1;
    c_act = arithmetic::add(a, b);
    c_exp = a + b + 2;

    if (!equal(c_act, c_exp, TOLERANCE)) {
        printFailPass(op, to_string(a), to_string(b), to_string(c_exp));
    } else {
        printFailFail(op, to_string(a), to_string(b), to_string(c_exp), to_string(c_act));
    }
}

void testSub() {

    string op = "-";

    int x = 33;
    int y = 20;
    int z_act = arithmetic::sub(x, y);
    int z_exp = x - y;

    if (equal(z_act, z_exp, TOLERANCE)) {
        printPassPass(op, to_string(x), to_string(y), to_string(z_act));
    } else {
        printPassFail(op, to_string(x), to_string(y), to_string(z_act), to_string(z_exp));
    }

    float a = 15.9;
    float b = 12.2;
    float c_act = arithmetic::sub(a, b);
    float c_exp = a - b;

    if (equal(c_act, c_exp, TOLERANCE)) {
        printPassPass(op, to_string(a), to_string(b), to_string(c_exp));
    } else {
        printPassFail(op, to_string(a), to_string(b), to_string(c_exp), to_string(c_act));
    }
}