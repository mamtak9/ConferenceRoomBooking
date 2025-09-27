#pragma once
#include <string>
using namespace std;

class Booking {
public:
    string id;
    string roomName;
    string employeeName;
    int startSlot;
    int duration;
    int attendees;

    Booking() = default;
    Booking(const string& i, const string& r, const string& e,
        int s, int d, int a);
};
