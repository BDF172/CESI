#include "mainHeader.h"

using namespace std;

void function1Exo2(void) {
	cout << "Fonction 1" << endl;
}

void function2Exo2(void) {
	cout << "Fonction 2" << endl;
}

void function3Exo2(void) {
	cout << "Fonction 3" << endl;
}

typedef void (*fonctionPtr)(void);

int mainExo2(void) {
	fonctionPtr maFonction[3];
	maFonction[0] = &function1Exo2;
	maFonction[1] = &function2Exo2;
	maFonction[2] = &function3Exo2;
	for (fonctionPtr i : maFonction) {
		i();
	}
	return 0;
}

int mainExo3(void) {
	fonctionPtr *maFonction = new fonctionPtr[3];
	maFonction[0] = &function1Exo2;
	maFonction[1] = &function2Exo2;
	maFonction[2] = &function3Exo2;
	for (int i = 0; i < 3; i++) {
		maFonction[i]();
	}
	delete[] maFonction;
	return 0;
}