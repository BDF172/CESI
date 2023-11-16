#include "pch.h"

using namespace std;

int main(void) {
    coordinates point1;
    coordinates *point2 = new coordinates(qddqd);
    cout << "Distance : " << coordinates::getDistance(point1, *point2) << endl;
    delete point2;
    return 0;
}