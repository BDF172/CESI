#include "pch.h"	

CLpoint::CLpoint() : m_x(0), m_y(0) {}

CLpoint::CLpoint(long double x, long double y) : m_x(x), m_y(y) {}

int CLpoint::getDimension(void) const {
	return 2;
}

long double CLpoint::getDistance(const CLpoint& toCompare) const {
	return sqrt(pow(getX() - toCompare.getX(), 2) + pow(getY() - toCompare.getY(), 2));
}

long double CLpoint::getX() const { return m_x; }

long double CLpoint::getY() const { return m_y; }

long double CLpoint::getZ() const { return 0; }

CLpoint3D::CLpoint3D() : CLpoint(), m_z(0) {}
CLpoint3D::CLpoint3D(long double x, long double y, long double z) : CLpoint(x, y), m_z(z) {}

int CLpoint3D::getDimension(void) const {
	return 3;
}

long double CLpoint3D::getZ() const { return m_z; }

long double CLpoint3D::getDistance(const CLpoint& toCompare) const {
	return sqrt(pow(getX() - toCompare.getX(), 2) + pow(getY() - toCompare.getY(), 2) + pow(getZ() - toCompare.getZ(), 2));
}