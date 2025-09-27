#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include "Room.h"
#include "Employee.h"
#include "Booking.h"
using namespace std;

class BookingSystem {
private:
    unordered_map<string, Room> rooms;
    unordered_map<string, Employee> employees;
    unordered_map<string, Booking> bookings;
    multimap<int, string> capacityMap;
    long long bookingCounter = 1;

    string generateBookingId();

public:
    void registerRoom(const string& name, int capacity);
    void registerEmployee(const string& name, const string& department);
    string bookRoom(const string& employeeName, int attendees, int duration);

    void viewScheduleRoom(const string& roomName);
    void viewScheduleEmployee(const string& employeeName);
};
