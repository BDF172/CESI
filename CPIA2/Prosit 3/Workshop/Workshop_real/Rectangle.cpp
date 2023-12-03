#include "mainHeader.h"

using namespace std;

Rectangle::Rectangle() : Objet2D() {}
Rectangle::Rectangle(int x, int y) : Objet2D(x, y) {}

int Rectangle::getPerimetre() {
	return 2 * m_x + 2 * m_y;
}

int Rectangle::getAire() {
	return m_x * m_y;
}

string Rectangle::afficheInfo() {
	return "rectangle";
}