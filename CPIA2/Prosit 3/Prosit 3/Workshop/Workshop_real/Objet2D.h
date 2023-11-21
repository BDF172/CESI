#pragma once

class Objet2D {
public:
	Objet2D();
	Objet2D(int x, int y);
	virtual int getPerimetre() = 0;
	virtual int getAire() = 0;
	virtual std::string afficheInfo() = 0;

protected:
	int m_x, m_y;
};