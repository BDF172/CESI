#include "mainHeader.h"

using namespace std;

Carre::Carre() : Rectangle() {}
Carre::Carre(int longueur) : Rectangle(longueur, longueur) {}

string Carre::afficheInfo() {
	return "carre";
}