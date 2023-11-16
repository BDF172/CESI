#include "Corbeille_1.h"

using namespace std;

void CLobjet::obj_ini(double mass, double speed) {
	changeMass(mass);
	changeSpeed(speed);
}

CLobjet::CLobjet() {
	obj_ini(1, 1);
}

CLobjet::CLobjet(const CLobjet &toCopy) {
	obj_ini(toCopy.getMass(), toCopy.getSpeed());
}

CLobjet::CLobjet(double mass, double speed) {
	obj_ini(mass, speed);
}

double CLobjet::calculer() {
	m_ke = 0.5 * m_mass * m_speed * m_speed;
	return m_ke;
}

double CLobjet::getMass() const {
	return m_mass;
}

double CLobjet::getSpeed() const {
	return m_speed;
}

void CLobjet::changeMass(double mass) {
	if (mass <= 0) {
		throw invalid_argument("La masse fournie est invalide");
	}
	m_mass = mass;
}

void CLobjet::changeSpeed(double speed) {
	if (speed <= 0) {
		throw invalid_argument("La vitesse fournie est invalide");
	}
	m_speed = speed;
}