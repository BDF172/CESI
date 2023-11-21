#pragma once
class Objet2D {
public:
	Objet2D();
	Objet2D(int x, int y);
	void setObjetSuivant(Objet2D* next);
	Objet2D* getSuivant(void);
	virtual int getPerimetre() = 0;
	virtual int getAire() = 0;
	virtual std::string afficheInfo() = 0;

protected:
	int m_x, m_y;
	Objet2D* Suivant;
};

class Rectangle : public Objet2D {
public:
	Rectangle();
	Rectangle(int x, int y);
	virtual int getPerimetre();
	virtual int getAire();
	virtual std::string afficheInfo();
};

class Carre : public Rectangle {
public:
	Carre();
	Carre(int longueur);
	virtual std::string afficheInfo() override;
};
