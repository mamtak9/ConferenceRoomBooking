#include "BookingSystem.h"
#include "BookingSystem.h"
#include <iostream>
#include <stdexcept>
using namespace std;

string BookingSystem::generateBookingId() {
    return "FLIPROOM" + to_string(bookingCounter++);
}

void BookingSystem::registerRoom(const string& name, int capacity) {

    if (rooms.count(name)) {
        throw runtime_error("Room already exists: " + name);
    }

    rooms.emplace(name, Room(name, capacity));
    capacityMap.emplace(capacity, name);
}

void BookingSystem::registerEmployee(const string& name, const string& department) {
    if (employees.count(name)) {
        throw runtime_error("Employee already exists: " + name);
    }

    employees.emplace(name, Employee(name, department));
}

string BookingSystem::bookRoom(const string& employeeName, int attendees, int duration) {
    if (!employees.count(employeeName)) {
        throw runtime_error("Employee not found: " + employeeName);
    }

    if (duration <= 0 || duration > 10) {
        throw runtime_error("Invalid duration");
    }

    auto it = capacityMap.lower_bound(attendees);
    for (; it != capacityMap.end(); ++it) {
        Room& room = rooms.at(it->second);
        
        for (int start = 1; start <= 10 - duration + 1; ++start) {
            if (room.isAvailable(start, duration)) {
                string id = generateBookingId();
                room.bookSlots(id, start, duration);
                bookings.emplace(id, Booking(id, room.name, employeeName, start, duration, attendees));
                employees.at(employeeName).bookingIds.push_back(id);
                return id;
            }
        }
    }
    return "";
}

void BookingSystem::viewScheduleRoom(const string& roomName) {
    if (!rooms.count(roomName)) {
        throw runtime_error("Room deost not exist! " + roomName);
    }
    Room& r = rooms.at(roomName);
    cout << "Schedule for Room " << roomName << ":\n";
    for (int i = 0; i < 10; i++) {
        cout << "  Slot " << (i + 1) << ": ";
        if (r.slots[i].empty()) cout << "is Available\n";
        else {
            Booking& b = bookings.at(r.slots[i]);
            cout << "Booked by " << b.employeeName << " (ID=" << b.id << ")\n";
        }
    }
}

void BookingSystem::viewScheduleEmployee(const string& employeeName) {
    
    if (!employees.count(employeeName)) {
        throw runtime_error("Employee not found: " + employeeName);
    }
    Employee& e = employees.at(employeeName);
    
    cout << "Bookings for " << employeeName << ":\n";
    
    if (e.bookingIds.empty()) {
        cout << "  (none)\n"; return;
    }
    for (auto& id : e.bookingIds) {
        Booking& b = bookings.at(id);
        cout << "  " << b.id << " Room=" << b.roomName
            << " Slots=" << b.startSlot << "-" << (b.startSlot + b.duration - 1)
            << " Attendees=" << b.attendees << "\n";
    }
}
