#pragma once
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    string name;
    string department;
    vector<string> bookingIds;
    Employee() = default;
    Employee(const string& n, const string& d);
};
