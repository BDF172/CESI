#include "pch.h"

using namespace std;

void userDecryption::obj_ini(string path) {
	if (path == "")return;
	if (doesPathExist(path))
        if (!obj.readFromFile(path)) throw runtime_error("Impossible d'ouvrir le fichier demande");

	else throw runtime_error("Chemin fourni invalide");
}

userDecryption::userDecryption() {
	obj_ini("");
}

userDecryption::userDecryption(string pathToFile) {
	obj_ini(pathToFile);
}

userDecryption::userDecryption(const userDecryption& toCopy) {
	obj.setMsg(getMessage());
	obj.setEncryptionLevel(toCopy.getEncryptionLevel());
}

string userDecryption::getMessage() {
	return obj.getMsg();
}

int userDecryption::getEncryptionLevel() const {
	return obj.getEncryptionLevel();
}

void userDecryption::askWhereFile() {
    string path = "C:\\Users\\ilias\\Downloads\\";
    string buffer;
    while (true) {
        cout << "Entrez le nom du fichier message (C:\\Users\\ilias\\Downloads\\) : ";
        getline(cin, buffer);
        if (buffer.size() < 4) {
            cerr << "Nom de fichier invalide" << endl;
            continue;
        }
        if (buffer.substr(buffer.size() - 4, buffer.size() - 1) != ".txt") buffer += ".txt";
        buffer = path + buffer;
        if (!doesPathExist(buffer)) {
            cerr << "Le fichier n'existe pas" << endl;
            continue;
        }
        break;
    }

    if (!obj.readFromFile(buffer)) throw runtime_error("Impossible d'ouvrir le fichier demande");
}

bool userDecryption::askDecryptMessage() {
    string distCesar, xorKey;

    Encrypt temp(obj);

    if (getEncryptionLevel() == 2 || getEncryptionLevel() == 3) userEncryption::getXORKey(xorKey);
    if (getEncryptionLevel() == 1 || getEncryptionLevel() == 3) userEncryption::getUserCesarNumber(distCesar);
    if (getEncryptionLevel() == 3)temp.level3Decrypt(atoi(distCesar.c_str()), xorKey);
    else if (getEncryptionLevel() == 2)temp.level2Decrypt(xorKey);
    else if (getEncryptionLevel() == 1)temp.level1Decrypt(atoi(distCesar.c_str()));

    if (temp.getMsg()[0] == '#' && temp.getMsg()[temp.getMsg().size() - 1] == '#') {
        obj = temp;
        return true;
    }
    return false;
}

bool userDecryption::doesPathExist(const string& fileName) {
    if (fileName.size() <= 6) {
        return false;
    }
    if (fileName.substr(0, fileName.find_last_of('\\')).size() == 0)return false;
    DWORD fileAttributes = GetFileAttributesA(fileName.substr(0, fileName.find_last_of('\\')).c_str());
    return (fileAttributes != INVALID_FILE_ATTRIBUTES && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}