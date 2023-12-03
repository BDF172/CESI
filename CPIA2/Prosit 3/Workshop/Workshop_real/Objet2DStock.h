#pragma once

class Objet2DStock {
public:
	Objet2DStock(int size);
	~Objet2DStock();
	bool ajouterObjet(Objet2D& toAdd);
	bool ajouterObjet(Objet2D* toAdd) { return ajouterObjet(*toAdd); }
	bool ajouterObjet(Objet2D& toAdd, int index);
	bool ajouterObjet(Objet2D* toAdd, int index) { return ajouterObjet(*toAdd, index); }
	void suppObjet(int index);
	void afficherInfos();
	
private:
	Objet2D** m_Objet2DTab;
	bool* objectAllocTable;
	int m_size;
};