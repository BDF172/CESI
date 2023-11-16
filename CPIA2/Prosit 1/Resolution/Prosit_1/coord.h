#pragma once

class coordinates {
public:
    coordinates(void);
    coordinates(long double x, long double y);
    coordinates(const coordinates& toCopy);
    ~coordinates();
    void changeCoordinates(long double x, long double y);
    long double getX() const;
    long double getY() const;

    static long double getDistance(const coordinates& point1, const coordinates& point2);

private:
    void obj_ini(long double x, long double y);
    long double* m_coords;
};