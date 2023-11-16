#include "pch.h"

using namespace std;

void userEncryption::setMessage(string messageToSet) {
    obj.setMsg(messageToSet);
}

int userEncryption::getEncryptionLevel() const {
    return obj.getEncryptionLevel();
}

void userEncryption::obj_ini(string messageToSet, int level) {
    setMessage(messageToSet);
    obj.setEncryptionLevel(level);
}

userEncryption::userEncryption() {
    obj_ini("", 0);
}

userEncryption::userEncryption(string messageToSet) {
    obj_ini(messageToSet, 0);
}

userEncryption::userEncryption(const userEncryption& toCopy) {
    obj_ini(toCopy.getMessage(), toCopy.getEncryptionLevel());
}

void userEncryption::askToInputMessage() {
    string userInputMsg;
    cout << "Quel message souhaitez vous encrypter ?" << endl << "Message : ";
    getline(cin, userInputMsg);
    obj.setMsg(userInputMsg);
}

string userEncryption::getMessage() const {
    return obj.getMsg();
}

void userEncryption::askEncryptionChoice() {
    string choix;
    while (true) {
        cout << endl << "Quel type d'encryption souhaitez vous utiliser ?" << endl
            << "1 : Encryption cesar" << endl
            << "2 : Encryption XOR" << endl
            << "3 : Les deux" << endl << endl;

        cout << "Choix (1/2/3) : ";
        getline(cin, choix);
        if (choix == "1" || choix == "2" || choix == "3")break;
        cout << "Vous n'avez pas choisi une bonne valeur..." << endl;
        choix = "";
    }

    string xorKey, distCesar;

    if (choix == "1" || choix == "3") getUserCesarNumber(distCesar);
    if (choix == "2" || choix == "3") getXORKey(xorKey);

    encryptMessage(atoi(choix.c_str()), xorKey, atoi(distCesar.c_str()));
}

void userEncryption::encryptMessage(int mode, string xorKey, int distCesar) {
    if (mode == 1)obj.level1(distCesar);
    if (mode == 2)obj.level2(xorKey);
    if (mode == 3)obj.level3(distCesar, xorKey);
}

void userEncryption::askWhereToSave() {
    if (obj.getEncryptionLevel() == 0) {
        cout << "Le message n'est pas encore encrypte" << endl;
        return;
    }
    string path = "C:\\Users\\ilias\\Downloads\\";
    string buffer;
    ofstream file;

    cout << "Le message est bien encrypte, ou voulez-vous l'enregistrer (format C:\\Users\\ilias\\Downloads\\nom.txt) : ";
    getline(cin, buffer);
    if (buffer.substr(buffer.size() - 4, buffer.size() - 1) != ".txt") buffer += ".txt";
    buffer = path + buffer;

    if (!obj.writeToFile(buffer)) {
        cerr << "Erreur lors de l'ecriture du fichier" << endl;
        while (true);
    }
    cout << "Envoi termine" << endl;
}

void userEncryption::getUserChoice(string& choix) {
    while (true) {
        cout << endl << "Quel type d'encryption souhaitez vous utiliser ?" << endl
            << "1 : Encryption cesar" << endl
            << "2 : Encryption XOR" << endl
            << "3 : Les deux" << endl << endl;

        cout << "Choix (1/2/3) : ";
        getline(cin, choix);
        if (choix == "1" || choix == "2" || choix == "3")break;
        cout << "Vous n'avez pas choisi une bonne valeur..." << endl;
        choix = "";
    }
}

void userEncryption::getXORKey(string& xorKey) {
    cout << endl << "Entrez la cle XOR : ";
    while (true) {
        getline(cin, xorKey);
        if (xorKey.size() != 0) break;
        cout << "Veuillez entrer au moins un caractere : ";
    }
}

void userEncryption::getUserCesarNumber(string& distCesar) {
    bool digitValid = true;
    while (digitValid) {
        cout << "\nVeuillez entrer une valeur pour le décalage cesar : ";
        getline(cin, distCesar);
        if (distCesar.size() == 0)continue;
        digitValid = false;
        for (char i : distCesar)
            if (!isdigit(i)) {
                cout << "Veuillez entrer une valeur entiere positive" << endl;
                digitValid = true;
                break;
            }
    }
}