#pragma once

class Etudiant {
public:
	Etudiant();
	Etudiant(std::string nom, int moyenne);
	Etudiant(const Etudiant& toCopy);
	std::string getNom() const;
	int getMoyenne() const;
	void setNom(std::string nom);
	void setMoyenne(int moyenne);

private:
	void obj_ini(std::string nom, int moyenne);
	std::string m_nom;
	int m_moyenne;
};

class Promo {
public: 
	Promo();
	int getNbEtudiants() const;
	void inputNotesUtilisateur();
	void ajouterEtudiant(const Etudiant& toAdd);
	void afficherEtudiants();
	void inputNotesDUFichier(std::string fileName);
	void outputNotesDUFichier(std::string fileName);

private:
	Etudiant* listEtudiants;
	int nb_etudiants;
};