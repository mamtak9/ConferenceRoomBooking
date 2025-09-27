#include "Booking.h"
using namespace std;

Booking::Booking(const string& i, const string& r, const string& e,int s, int d, int a)
    : id(i), roomName(r), employeeName(e), startSlot(s), duration(d), attendees(a) {}