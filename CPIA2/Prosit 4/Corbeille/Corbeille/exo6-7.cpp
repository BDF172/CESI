#include "mainHeader.h"

using namespace std;

typedef struct Personne{
	int age;
	string prenom;
	Personne* objSuivant;
} P;

void fonctionChaine(P* varTest) {
	while (varTest != nullptr) {
		cout << varTest->prenom << endl;
		varTest = varTest->objSuivant;
	}
}

int mainExo6(void) {
	P var1, var2, var3;
	var1.age = 1; var1.prenom = "premier"; var1.objSuivant = &var2;
	var2.age = 2; var2.prenom = "deuxieme"; var2.objSuivant = &var3;
	var3.age = 3; var3.prenom = "troisieme"; var3.objSuivant = (P*)nullptr;
	fonctionChaine(&var1);
	return 0;
}

int mainExo7(void) {
	string userInput;
	int nbPersonnes;
	while (true) {
		cout << "Entrez un nombre de personnes : ";
		getline(cin, userInput);
		if (isInt(userInput) && userInput != "0") break;
		cout << "Impossible de valider votre entree, veuillez reessayer" << endl;
	}
	nbPersonnes = atoi(userInput.c_str());
	P** personnesTab = new P*[nbPersonnes];

	personnesTab[0] = new P;
	personnesTab[0]->prenom = "Personne 1";
	for (int i = 1; i < nbPersonnes; i++) {
		personnesTab[i] = new P;
		personnesTab[i]->prenom = "Personne : " + to_string(i+1);
		personnesTab[i - 1]->objSuivant = personnesTab[i];
	}
	personnesTab[nbPersonnes - 1]->objSuivant = nullptr;
	
	fonctionChaine(personnesTab[0]);
	return 0;
}