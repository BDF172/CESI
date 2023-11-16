#include "pch.h"

using namespace std;

int mainExo1()
{
    CLa oa;
    CLb ob;
    CLb* pb;
    pb = &ob; 
    oa.ma1(); 
    oa.ma2(); 
    oa.ma3(ob); 
    oa.ma4(*pb); 
    oa.ma5(pb);
    return 0;
}

int mainExo2() {
    gp1 groupe1;
    gp2 groupe2;
    cout << "Groupe 1 service 1 : " << endl;
    groupe1.gpcs1s1();
    cout << endl << "Groupe 1 service 2 : " << endl;;
    groupe1.gpcs1s2();
    cout << endl << "Groupe 2 service 1 : " << endl;
    groupe2.gpcs2s1();
    return 0;
}

int mainExo3() {
    Promo promo;
    promo.ajouterEtudiant(Etudiant("Samuel", 20));
    promo.ajouterEtudiant(Etudiant("Raphael", 20));
    promo.ajouterEtudiant(Etudiant("Paul", 20));
    promo.inputNotesDUFichier("C:\\Users\\ilias\\notes.txt");
    // Chaque entree du fichier doit être au format :
    // nom1 nom2 ... prenom:note/20
    // Aucune vérification n'est faite, le programme ne
    // fonctionnera que si la syntaxe est respectée.
    // (C'est possible avec un peu de temps mais flemme
    //  workshop est fini)
    promo.afficherEtudiants();
    promo.outputNotesDUFichier("C:\\Users\\ilias\\exportFile.txt");
    return 0;
}

int main(void) {
    return mainExo3();
}