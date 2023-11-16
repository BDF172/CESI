#include "Corbeille_1.h"

using namespace std;

int test1(void) {
	listData test;
	test.ajouter(3);
	test.ajouter(9);
	test.ajouter(13);
	test.ajouter(-1);
	cout << "moyenne : " << test.moyenne() << endl;
	test.ajouter(0);
	cout << "minimum : " << test.minValue() << endl;
	return 0;
}

int test2(void) {
	listData* test = new listData;
	test->ajouter(3);
	test->ajouter(9);
	test->ajouter(13);
	test->ajouter(-1);
	cout << "moyenne : " << test->moyenne() << endl;
	test->ajouter(0);
	cout << "minimum : " << test->minValue() << endl;
	return 0;
}

int test3(void) {
	listData* objPtr = new listData[2];
	objPtr->ajouter(3);
	objPtr->ajouter(9);
	objPtr->ajouter(13);
	objPtr->ajouter(-1);

	(objPtr + 1)->ajouter(-5);
	(objPtr + 1)->ajouter(-2);
	(objPtr + 1)->ajouter(-7);

	cout << "Moyenne 1 : " << objPtr->moyenne() << endl;
	cout << "Moyenne 2 : " << (objPtr + 1)->moyenne() << endl;

	cout << (objPtr->moyenne() == (objPtr + 1)->moyenne() ? "Les deux moyennes sont egales" : "Les moyennes ne sont pas egales") << endl;
	return 0;
}

int exercice1(void) {
	CLa o1;
	CLa *o2 = new CLa;
	o1.afficher();
	o2->afficher();
	cout << "Adresse o1 : " << &o1 << endl;
	cout << "Adresse o2 : " << &o2;
	cout << " | Adresse pointee par o2 : " << o2 << endl;
	cout << "Taille de CLa : " << sizeof(CLa) << endl;
	cout << "Taille o1 : " << sizeof(o1) << " | Taille o2 : " << sizeof(o2) << endl;
	delete o2;
	return 0;
}

void comparer(CLobjet obj1, CLobjet obj2) {
	cout << "Le " << (obj1 > obj2 ? "premier " : "deuxieme ") << "est plus grand" << endl;
}

int exercice2() {
	string speed1, mass1, speed2, mass2;
	cout << "Entrez la masse du premier objet : "; cin >> mass1;
	cout << "Entrez la vitesse du premier objet : "; cin >> speed1;
	cout << "Entrez la masse du deuxieme objet : "; cin >> mass2;
	cout << "Entrez la vitesse du deuxieme objet : "; cin >> speed2;

	if (!isdigit(speed1.at(0)) || !isdigit(speed2.at(0)) || !isdigit(mass1.at(0)) || !isdigit(mass2.at(0))) {
		cerr << "Vous ave fourni une chaîne de caracteres au lieu d'un entier" << endl;
		return 1;
	}
	try {
		CLobjet obj1(stoi(mass1), stoi(speed1));
		CLobjet obj2(stoi(mass2), stoi(speed2));
		comparer(obj1, obj2);
	}
	catch (const invalid_argument &e) {
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}

int exercice3() {
	CLobjet o1;
	CLobjet o2(2, 2);
	CLobjet *o3 = new CLobjet(4, 32);
	CLobjet* o4 = new CLobjet(*o3);
	cout << "EC o1 : " << o1.calculer() << endl;
	cout << "EC o2 : " << o2.calculer() << endl;
	cout << (o1 == o2 ? "o1 = o2" : (o1 > o2 ? "o1 > o2" : "o1 < o2")) << endl;
	cout << "EC o3 : " << o3->calculer() << endl;
	cout << "EC o4 : " << o4->calculer() << endl;
	cout << (*o3 == *o4 ? "o3 = o4" : (*o3 > *o4 ? "o3 > o4" : "o3 < o4")) << endl;
	return 0;
}

int exercice4() {
	CLvoiture v1(20, 1);
	CLvoiture v2(300, 10);
	CLvoiture* v3 = new CLvoiture(160, 2);
	while (v1.accelerer() | v2.accelerer() | v3->accelerer())Sleep(100);
	cout << endl << "Affichage des ratios (petit est meilleur que grand) : " << endl;
	cout << "Voiture 1 : " << v1.getVitesseMax() / v1.getAcceleration() << endl;
	cout << "Voiture 2 : " << v2.getVitesseMax() / v2.getAcceleration() << endl;
	cout << "Voiture 3 : " << v3->getVitesseMax() / v3->getAcceleration() << endl;
	return 0;
}

int main() {
	return exercice4();
}