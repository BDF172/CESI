#include "mainHeader.h"

using namespace std;

void function1Exo4(void) {
	cout << "Fonction 1" << endl;
}

void function2Exo4(void) {
	cout << "Fonction 2" << endl;
}

void function3Exo4(void) {
	cout << "Fonction 3" << endl;
}

bool isInt(string input) {
	for (char i : input) {
		if (!isdigit(i))return false;
	}
	return true;
}

typedef void (*maFonctionUser)(void);

int mainExo4(void) {
	string userInput;
	int nbFuncs;
	while (true) {
		cout << "Entrez un nombre de fonctions a utiliser : ";
		getline(cin, userInput);
		if (isInt(userInput)) break;
		cout << "Impossible de valider votre entree, veuillez reessayer" << endl;
	}
	nbFuncs = atoi(userInput.c_str());

	maFonctionUser *monTableau = new maFonctionUser[nbFuncs];

	for (int i = 0; i < nbFuncs; i++) {
		while (true) {
			cout << "Entrez le numero de la fonction a utiliser : ";
			getline(cin, userInput);
			if (userInput == "1" || userInput == "2" || userInput == "3") break;
			cout << "Impossible de valider votre entree, veuillez reessayer" << endl;
		}
		if (userInput == "1") monTableau[i] = &function1Exo4;
		if (userInput == "2") monTableau[i] = &function2Exo4;
		if (userInput == "3") monTableau[i] = &function3Exo4;
	}

	for (int i = 0; i < nbFuncs; i++) {
		cout << "Fonction " << i+1 << " : ";
		monTableau[i]();
	}

	return 0;
}