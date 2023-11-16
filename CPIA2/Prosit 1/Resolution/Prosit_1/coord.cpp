#include "pch.h"

using namespace std;

void coordinates::obj_ini(long double x, long double y) {
    m_coords = new long double[2];
    m_coords[0] = x;
    m_coords[1] = y;
}

coordinates::coordinates() {
    obj_ini(0, 0);
}

coordinates::coordinates(long double x, long double y) {
    obj_ini(x, y);
}

coordinates::~coordinates() {
    delete[] m_coords;
}

long double coordinates::getX() const {
    return m_coords[0];
}

long double coordinates::getY() const {
    return m_coords[1];
}

void coordinates::changeCoordinates(long double x, long double y) {
    m_coords[0] = x;
    m_coords[1] = y;
}

long double coordinates::getDistance(const coordinates& point1, const coordinates &point2) {
    long double distanceX = point1.getX() - point2.getX();
    long double distanceY = point1.getY() -point2.getY();
    return sqrt(distanceX * distanceX + distanceY * distanceY);
}

coordinates::coordinates(const coordinates& toCopy) {
    obj_ini(toCopy.getX(), toCopy.getY());
}
