#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include "arithmetic.h"

using namespace std;
using namespace arithmetic;
using std::to_string;

#define TOLERANCE (1.0E-6) // Error tolerance for floating point comparisons

template <class t>
bool equal (t, t, double);

template <class t1>
pair<bool, string> assertEqual(t1 (*f)(t1, t1), t1, string, t1, t1);

template <class t2>
pair<bool, string> assertNotEqual(t2 (*f)(t2, t2), t2, string, t2, t2);

template <class t3>
vector<pair<bool, string>> performTests(vector<vector<t3>>);

int main() {

    int err = 0, suc = 0;
    vector<string> errors = {};

    vector<vector<int>> testsInt = {
        {10, 5, 15, 5, 50, 2, 10},
        {30, -2, 28, 32, -60, -15, 22},
    };

    vector<vector<double>> testsDbl = {
        {11.3, 8.3, 19.6, 3.0, 93.79, 1.3614457831325302, .0876},
        {30.567, -2.32, 28.247, 32.887, -70.91543999999999, -13.17543103448276, 98.76},
    };

    // Create vectors and run tests
    vector<pair<bool, string>> results;
    vector<pair<bool, string>> resultsInt = performTests(testsInt);
    vector<pair<bool, string>> resultsDbl = performTests(testsDbl);
    
    // Combine vector results
    results.reserve(resultsInt.size() + resultsDbl.size());
    results.insert(results.end(), resultsInt.begin(), resultsInt.end());
    results.insert(results.end(), resultsDbl.begin(), resultsDbl.end());

    // Parse results
    for (pair<bool, string> result : results) {
        if (result.first) { suc++; }
        else { err++; errors.push_back(result.second); }
    }

    // Print results
    cout << "Tests Passed: " << suc << endl;
    cout << "Tests Failed: " << err << endl;
    for (string msg : errors) {
        cout << "\t" << msg << endl;
    }
}

template <class t0>
bool equal (t0 x, t0 y, double tolerance) {

    // Try system comparison in case it works
    if (x == y) { return true; }

    // If it doesn't, do epsilon comparison
    double avg = (x + y) / 2;
    double epsilon = fabs(avg * tolerance);
    double absDiff = fabs(x - y);

    if (absDiff <= epsilon) {
        return true;
    } else {
        return false;
    }
}

template <class t1>
pair<bool, string> assertEqual(t1 (*f)(t1, t1), t1 a, string op, t1 b, t1 c) {

    bool result = equal((*f)(a, b), c, TOLERANCE);
    string msg = to_string(a) + " " + op + " " + to_string(b) + " = "  + to_string(c);

    pair<bool, string> ret = make_pair(result, msg);

    return ret;
}

template <class t2>
pair<bool, string> assertNotEqual(t2 (*f)(t2, t2), t2 a, string op, t2 b, t2 c) {

    bool result = !equal((*f)(a, b), c, TOLERANCE);
    string msg = to_string(a) + " " + op + " " + to_string(b) + " != "  + to_string(c);

    pair<bool, string> ret = make_pair(result, msg);

    return ret;
}

template <class t3>
vector<pair<bool, string>> performTests(vector<vector<t3>> testVals) {

    vector<pair<bool, string>> results;

    for (vector<t3> vals : testVals) {

        results.push_back(assertEqual(add, vals[0], "+", vals[1], vals[2]));
        results.push_back(assertNotEqual(add, vals[0], "+", vals[1], vals[6]));

        results.push_back(assertEqual(sub, vals[0], "-", vals[1], vals[3]));
        results.push_back(assertNotEqual(sub, vals[0], "-", vals[1], vals[6]));

        results.push_back(assertEqual(mul, vals[0], "*", vals[1], vals[4]));
        results.push_back(assertNotEqual(mul, vals[0], "*", vals[1], vals[6]));

        results.push_back(assertEqual(div, vals[0], "/", vals[1], vals[5]));
        results.push_back(assertNotEqual(div, vals[0], "/", vals[1], vals[6]));
    }

    return results;
}