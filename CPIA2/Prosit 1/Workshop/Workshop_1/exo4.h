#pragma once
class fraction {
public:
	fraction(int numerateur, int denominateur);
	fraction();
	fraction operator+(fraction toAdd);
	fraction operator-(fraction toSub);
	fraction operator/(fraction toDiv);
	fraction operator*(fraction toDiv);
	int getNum();
	int getDen();

private:
	int m_num, m_den;
};