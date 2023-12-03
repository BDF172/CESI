#include "mainHeader.h"

int mainExo2(void) {
	Carre carre1(3);
	Carre carre2(5);
	Objet2D* carre3 = new Rectangle(4, 3);

	Objet2DStock stockage(3);
	stockage.ajouterObjet(carre1);
	stockage.ajouterObjet(carre2);
	stockage.ajouterObjet(carre3);

	stockage.afficherInfos();

	return 0;
}