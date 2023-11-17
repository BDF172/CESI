#pragma once

class CLparcours {
public:
	CLparcours(int size);
	long double calculDistance() const;
	virtual void ajouterPoint(CLpoint* point) = 0;
	virtual void afficherMessage() = 0;

protected:
	CLpoint** pointTab;
	int  nbVal;

private:
	int m_size;
};

class CLparcours2D : public CLparcours {
public:
	CLparcours2D(int size) : CLparcours(size) {}
	void ajouterPoint(CLpoint* point) override;
	void afficherMessage() override;
};

class CLparcours3D : public CLparcours {
public:
	CLparcours3D(int size) : CLparcours(size) {}
	void ajouterPoint(CLpoint* point) override;
	void afficherMessage() override;
};