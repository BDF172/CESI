#pragma once

class Carre : public Rectangle {
public:
	Carre();
	Carre(int longueur);
	virtual std::string afficheInfo() override;
};
