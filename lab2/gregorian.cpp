#include "gregorian.h"

using namespace lab2;

Gregorian::Gregorian() : CaesarDate() {
}

Gregorian::Gregorian(const Date & d) : CaesarDate(d) {
}

Gregorian::Gregorian(int y, int m, int d) : CaesarDate(y, m, d){
}


