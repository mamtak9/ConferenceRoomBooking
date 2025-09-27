#include "BookingSystem.h"
#include <iostream>

int main() {
    BookingSystem sys;

    sys.registerRoom("Room A", 10);
    sys.registerRoom("Room B", 30);

    sys.registerEmployee("Alice", "Marketing");
    sys.registerEmployee("Bob", "Sales");

    string b1 = sys.bookRoom("Alice", 7, 2);
    if (!b1.empty()) cout << "Alice booked successfully, ID=" << b1 << "\n";

    string b2 = sys.bookRoom("Bob", 5, 1);
    if (!b2.empty()) cout << "Bob booked successfully, ID=" << b2 << "\n";

    sys.viewScheduleRoom("Room A");
    sys.viewScheduleRoom("Room B");

    sys.viewScheduleEmployee("Alice");
    sys.viewScheduleEmployee("Bob");

    return 0;
}
