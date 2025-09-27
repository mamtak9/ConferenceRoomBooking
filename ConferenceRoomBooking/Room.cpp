#include "Room.h"
using namespace std;
bool Room::isAvailable(int startSlot, int duration) const {
    for (int k = 0; k < duration; ++k) {
        if (!slots[startSlot - 1 + k].empty()) return false;
    }
    return true;
}
void Room::bookSlots(const string& bookingId, int startSlot, int duration) {
    for (int k = 0; k < duration; ++k) {
        slots[startSlot - 1 + k] = bookingId;
    }
}