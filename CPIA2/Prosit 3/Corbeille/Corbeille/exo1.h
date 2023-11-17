#pragma once

class Voiture {
public:
	Voiture();
	Voiture(int vitesseMax, int acceleration);
	~Voiture();

	virtual void setVitesseMax(int vitesseMax);
	virtual void setAcceleration(int acceleration);

	bool acceleration();

	int getVitesseMax() const;
	int getVitesse() const;
	int getAcceleration() const;

	static int getNbVoitures();

protected:
	void obj_ini(int vitesseMax, int acceleration);
	int  m_vitesseMax, m_acceleration;

private:
	int m_vitesse;
	static int nbObj;
};

class VoitureSport : public Voiture {
public:
	VoitureSport();
	VoitureSport(int vitesseMax, int acceleration);

	void setVitesseMax(int vitesseMax) override;
	void setAcceleration(int acceleration) override;

private:
	int nbObj;
};