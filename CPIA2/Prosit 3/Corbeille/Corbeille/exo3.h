#pragma once

class Vehicule {
public:
	Vehicule() : isWashed(false) {}
	void laver(void);

protected:
	virtual void afficherMessage(void) = 0;

private:
	bool isWashed;
};

class Voiture3 : public Vehicule {
private:
	void afficherMessage(void) override;
};

class Moto : public Vehicule {
private:
	void afficherMessage(void) override;
};

class Station {
public:
	void addVehicule(Vehicule& toWash) { addVehicule(&toWash); }
	void addVehicule(Vehicule* toWash);
	void washAllVehicules();

private:
	std::vector<Vehicule *> toWash;
};

int mainExo3(void);