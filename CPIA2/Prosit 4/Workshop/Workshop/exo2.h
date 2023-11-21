#pragma once

class Objet2DChaine {
public:
	Objet2DChaine(void);
	Objet2DChaine(Objet2D* premierMaillon);

	int getNbObjets();

	void addMaillonAtTail(Objet2D* toAdd);
	void addMaillonAtHead(Objet2D* toAdd);
	void addMaillonAtIndex(Objet2D* toAdd, int index);
	void afficherInfos(void);

private:
	Objet2D* head;
};

int mainExo2(void);
