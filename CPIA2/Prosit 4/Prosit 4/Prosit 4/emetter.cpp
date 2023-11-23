#include "linker.h"

using namespace std;

Emetter::Emetter(int ID) : m_ID(ID) {}

void Emetter::diffuserMessage(std::string message, fonctionCallback antenne) {
	antenne(message, m_ID);
	Sleep(100);
}