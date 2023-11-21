#pragma once

class CLpoint {
public:
	CLpoint();
	CLpoint(long double x, long double y);

	virtual int getDimension(void) const;
	virtual long double getDistance(const CLpoint& toCompare) const;

	long double getX() const;
	long double getY() const;
	void setX(long double x);
	void setY(long double y);
	virtual long double getZ() const;

private:
	long double m_x, m_y;
};

class CLpoint3D : public CLpoint {
public:
	CLpoint3D();
	CLpoint3D(long double x, long double y, long double z);
	virtual int getDimension(void) const override;
	long double getZ() const;
	long double getDistance(const CLpoint& toCompare) const override;

private:
	long double m_z;
};