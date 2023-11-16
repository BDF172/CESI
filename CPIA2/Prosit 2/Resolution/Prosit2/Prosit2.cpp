#include "pch.h"

using namespace std;

int service(void) {
    string userRequest;
    while (true) {
        cout << "Voulez vous encrypter ou decrypter un message ? [e/d] : ";
        getline(cin, userRequest);
        if (userRequest == "e" || userRequest == "d") break;
        cout << "Veuillez entrer un choix correct." << endl;
    }

    if (userRequest == "e") {
        userEncryption toEncrypt;
        toEncrypt.askToInputMessage();
        toEncrypt.askEncryptionChoice();
        toEncrypt.askWhereToSave();
    }
    
    if (userRequest == "d") {
        userDecryption toDecrypt;
        toDecrypt.askWhereFile();
        while (!toDecrypt.askDecryptMessage())cout << "Vous n'avez pas entre les bonnes cles" << endl;
        cout << "Message decrypte : " << toDecrypt.getMessage().substr(1, toDecrypt.getMessage().size() - 2) << endl;
    }
   
    return 0;
}

int main(void) {
    return service();
}