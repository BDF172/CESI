#pragma once

typedef struct objetChaine {
	Objet2D* maillon;
	objetChaine* maillonSuivant;
} objetChaine;

class Objet2DChaine {
public:
	Objet2DChaine(void);
	Objet2DChaine(Objet2D* premierMaillon);

	void addMaillon(Objet2D* toAdd);
	void afficherInfos(void);

private:
	Objet2D* head;
};

int mainExo2(void);