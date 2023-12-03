#include "mainHeader.h"

using namespace std;

bool verifyInt(const string& toTest) {
	for (char i : toTest) {
		if (!isdigit(i)) return false;
	}
	return true;
}

void sePresenter(Objet2D &toPresent) {
	cout << "Je suis un " << toPresent.afficheInfo() << endl;
}

int mainExo1(void) {
	Objet2D* pointer;
	cout << "Choisissez entre carre et rectangle [c/r] : ";
	string choix;
	while (true) {
		getline(cin, choix);
		if (choix == "c" || choix == "r")break;
		cout << "Veuillez entrer un choix correct [c/r] : ";
	}

	if (choix == "c") {
		cout << "Entrez la valeur pour la longueur du carre : ";
		while (true) {
			getline(cin, choix);
			if (verifyInt(choix))break;
			cout << "Veuillez entrer une valeur entiere correcte : ";
		}
		pointer = new Carre(atoi(choix.c_str()));
	}
	else {
		cout << "Entrez la valeur pour la longueur du rectangle : ";
		while (true) {
			getline(cin, choix);
			if (verifyInt(choix))break;
			cout << "Veuillez entrer une valeur entiere correcte : ";
		}
		int longueur = atoi(choix.c_str());
		cout << "Entrez la valeur pour la largeur du rectangle : ";
		while (true) {
			getline(cin, choix);
			if (verifyInt(choix))break;
			cout << "Veuillez entrer une valeur entiere correcte : ";
		}
		pointer = new Rectangle(longueur, atoi(choix.c_str()));
	}

	//cout << endl << "L'aire du " << pointer->afficheInfo() << " est de : " << pointer->getAire() << endl;;
	//cout << "Le perimetre du " << pointer->afficheInfo() << " est de : " << pointer->getPerimetre() << endl << endl;

	sePresenter(*pointer);

	delete pointer;

	return 0;
}