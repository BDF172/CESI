#pragma once

int connectToRadio(Emetter* emetter, int nbRadios, fonctionCallback antenne);
void radioHostHandle(Emetter* emetter, size_t nbEme, fonctionCallback antenne, SOCKET clientSocket);