#pragma once
#include<string>
#include<vector>
using namespace std;

struct Room {
    string name;
    int capacity;
    vector<string> slots; // size = 10 indices 0..9 represent slots 1..10
    Room() = default;
    Room(const string& n, int c) : name(n), capacity(c), slots(10, "") {}
    bool isAvailable(int startSlot, int duration) const;
    void bookSlots(const std::string& bookingId, int startSlot, int duration);
};
