#include "linker.h"

using namespace std;

int connectToRadio(Emetter* emetter, fonctionCallback antenne) {
    // Initialisation de Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Erreur lors de l'initialisation de Winsock." << std::endl;
        return -1;
    }

    // Cr�ation du socket
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Erreur lors de la cr�ation du socket." << std::endl;
        WSACleanup();
        return -1;
    }

    // Configuration de l'adresse du serveur
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);

    // Liaison du socket � l'adresse
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "Erreur lors de la liaison du socket � l'adresse." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    // �coute des connexions entrantes
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Erreur lors de l'ecoute des connexions entrantes." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    std::cout << "Serveur en attente de connexions..." << std::endl;

    // Accepter une connexion entrante
    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Erreur lors de l'acceptation de la connexion entrante." << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    radioHostHandle(emetter, antenne, clientSocket);

    // Fermer les sockets
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}

string receiveMessage(SOCKET clientSocket) {
    char buffer[1024];
    while (true) {
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead > 0 && bytesRead < 1024) {
            buffer[bytesRead] = '\0';
            std::string receivedMessage(buffer);
            return receivedMessage;
        }
        else {
            return "##RST##";
        }
    }
}

int sendMessage(SOCKET clientSocket, string messageToSend) {
    return send(clientSocket, messageToSend.c_str(), messageToSend.size(), 0);
}

void radioHostHandle(Emetter* emetter, fonctionCallback antenne, SOCKET clientSocket) {
    string userEntry;
    while (true) {
        if(sendMessage(clientSocket, "Veuillez selectionner une radio (1/2) : ") == -1) return;
        if((userEntry = receiveMessage(clientSocket)) == "##RST##")return;
        if (userEntry.substr(0, userEntry.size()-1) != "1" && userEntry.substr(0, userEntry.size() - 1) != "2") {
            if (sendMessage(clientSocket, "Vous n'avez pas fait un choix valide\n") == -1) return;
            continue;
        }
        if (sendMessage(clientSocket, "Veuillez ecrire un message a envoyer : ") == -1) return;
        if ((userEntry = receiveMessage(clientSocket)) == "##RST##")return;
        emetter->diffuserMessage(userEntry, antenne);
    }
}