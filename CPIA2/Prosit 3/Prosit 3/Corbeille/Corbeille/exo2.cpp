#include "pch.h"

using namespace std;

void Piano::playInstrument() {
	cout << "SON PIANO" << endl;
}

void Saxo::playInstrument() {
	cout << "SON SAXOPHONE" << endl;
}

int mainExo2(void)
{
    cout << "Quel instrument voulez jouer [piano/saxo] : ";
    string choix;
    while (true) {
        getline(cin, choix);
        if (choix == "piano" || choix == "saxo") break;
        cout << "Veuillez entrer un choix valide" << endl;
    }

    while (GetAsyncKeyState(13));

    Instrument* instrument;
    if (choix == "piano") instrument = new Piano; else instrument = new Saxo;

    while (true) {
        if (GetAsyncKeyState(13)) break;
        if (GetAsyncKeyState(80) & 0x8000) {
            instrument->playInstrument();
            Sleep(100);
        }
    }

    return 0;
}