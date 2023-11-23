#pragma once

int connectToRadio(Emetter* emetter, fonctionCallback antenne);
void radioHostHandle(Emetter* emetter, fonctionCallback antenne, SOCKET clientSocket);