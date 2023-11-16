#ifndef CORBEILLE_H
#define CORBEILLE_H

#include <iostream>
#include <Windows.h>
#include <string>
#include <random>

class listData {
public:
	listData();
	listData(int premier);
	~listData();
	void ajouter(int valeur);
	int somme();
	double moyenne();
	int minValue();
	int maxValue();
	int variationMax();

private:
	int* tab;
	int tabSize;
};

class CLa {
public:
	void afficher(void) {
		std::cout << "Bonjour" << std::endl;
	}

private:
	int tabExemplePourTaille[20];
};

class CLobjet {
public:
	CLobjet();
	CLobjet(const CLobjet &toCopy);
	CLobjet(double mass, double speed);
	double getMass() const;
	double getSpeed() const;
	void changeMass(double mass);
	void changeSpeed(double masss);

	double calculer();

	bool operator>(CLobjet obj2) {
		return calculer() > obj2.calculer();
	}

	bool operator<(CLobjet obj2) {
		return calculer() < obj2.calculer();
	}

	bool operator==(CLobjet obj2) {
		return calculer() == obj2.calculer();
	}

private:
	double m_mass, m_speed, m_ke;
	void obj_ini(double mass, double speed);
};

class CLvoiture {
public:
	static int generateID();
	int getID() const;
	CLvoiture();
	CLvoiture(int vitesseMax, int acceleration);
	CLvoiture(const CLvoiture& toCopy);
	int getAcceleration() const;
	int getVitesseMax() const;
	void setAcceleration(int acceleration);
	void setVitesseMax(int vitesseMax);
	bool accelerer();

private:
	int m_vitesseMax, m_vitesse, m_acceleration, m_idV, m_idVoiture;
	void ini_obj(int vitesseMax, int acceleration);
};

#endif
