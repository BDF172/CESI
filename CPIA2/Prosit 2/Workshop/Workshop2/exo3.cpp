#include "pch.h"

using namespace std;

void Etudiant::obj_ini(string nom, int moyenne) {
	if (moyenne < 0) {
		throw invalid_argument("Moyenne negative fournie");
	}
	m_nom = nom;
	m_moyenne = moyenne;
}

Etudiant::Etudiant() {
	obj_ini("", 0);
}

Etudiant::Etudiant(string nom, int moyenne) {
	obj_ini(nom, moyenne);
}

Etudiant::Etudiant(const Etudiant& toCopy) {
	obj_ini(toCopy.getNom(), toCopy.getMoyenne());
}

string Etudiant::getNom() const {
	return m_nom;
}

int Etudiant::getMoyenne() const {
	return m_moyenne;
}

void Etudiant::setNom(string nom) {
	m_nom = nom;
}

void Etudiant::setMoyenne(int moyenne) {
	m_moyenne = moyenne;
}



Promo::Promo() {
	nb_etudiants = 0;
}

int Promo::getNbEtudiants() const {
	return nb_etudiants;
}

void Promo::afficherEtudiants() {
	Etudiant* etud;
	for (int i = 0; i < nb_etudiants; i++) {
		etud = listEtudiants + i;
		cout << "Etudiant " << i
			<< " : " << etud->getNom()
			<< " | Moyenne : "
			<< etud->getMoyenne()
			<< endl;
	}
}

void Promo::inputNotesUtilisateur() {
	Etudiant* etud;
	int noteBuffer;
	for (int i = 0; i < nb_etudiants; i++) {
		etud = listEtudiants + i;
		cout << "Entrez la moyenne de "
			<< etud->getNom() << " : ";
		cin >> noteBuffer;
		etud->setMoyenne(noteBuffer);
	}
}

void Promo::ajouterEtudiant(const Etudiant& toAdd) {
	if (nb_etudiants == 0) {
		listEtudiants = new Etudiant[nb_etudiants + 1];
		listEtudiants[nb_etudiants++] = toAdd;
		return;
	}
	else {
		Etudiant* tempListEtud = new Etudiant[nb_etudiants + 1];
		for (int i = 0; i < nb_etudiants; i++) {
			tempListEtud[i] = listEtudiants[i];
		}
		tempListEtud[nb_etudiants++] = toAdd;
		delete[] listEtudiants;
		listEtudiants = tempListEtud;
	}
}

void Promo::inputNotesDUFichier(string nomFichier) {
	ifstream noteFile(nomFichier);
	string line;
	string nomEtudiant;
	int separationIndex, noteEtudiant;
	while (getline(noteFile, line)) {
		separationIndex = line.find_first_of(':');
		nomEtudiant = line.substr(0, separationIndex);
		noteEtudiant = atoi(line.substr(separationIndex + 1, line.size()).c_str());
		ajouterEtudiant(Etudiant(nomEtudiant, noteEtudiant));
	}
}

void Promo::outputNotesDUFichier(string fileName) {
	Etudiant* etud;
	ofstream fileToExport(fileName, ios::app);
	if (!fileToExport) {
		cerr << "Impossible d'ouvrir le fichier" << endl;
		return;
	}
	string line;
	for (int i = 0; i < nb_etudiants; i++) {
		etud = listEtudiants + i;
		line = etud->getNom() + ":" + to_string(etud->getMoyenne());
		fileToExport << line << endl;
	}
}