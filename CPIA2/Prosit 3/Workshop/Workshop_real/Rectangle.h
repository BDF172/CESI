#pragma once

class Rectangle : public Objet2D {
public:
	Rectangle();
	Rectangle(int x, int y);
	virtual int getPerimetre();
	virtual int getAire();
	virtual std::string afficheInfo();
};