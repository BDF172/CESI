#include "linker.h"

Objet2D::Objet2D() : m_x(0), m_y(0), Suivant(nullptr) {}
Objet2D::Objet2D(int x, int y) : m_x(x), m_y(y), Suivant(nullptr) {}
void Objet2D::setObjetSuivant(Objet2D* next) { Suivant = next; }
Objet2D* Objet2D::getSuivant(void) { return Suivant; }

Rectangle::Rectangle() : Objet2D() {}
Rectangle::Rectangle(int x, int y) : Objet2D(x, y) {}

int Rectangle::getPerimetre() {
	return 2 * m_x + 2 * m_y;
}

int Rectangle::getAire() {
	return m_x * m_y;
}

std::string Rectangle::afficheInfo() {
	return "rectangle";
}

Carre::Carre() : Rectangle() {}
Carre::Carre(int longueur) : Rectangle(longueur, longueur) {}

std::string Carre::afficheInfo() {
	return "carre";
}