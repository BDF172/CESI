#include "linker.h"

using namespace std;

mutex Emetter::objLock;
size_t Emetter::nbObj = 0;

Emetter::Emetter() {
	lock_guard<mutex> lock(objLock);
	m_ID = ++nbObj;
}

void Emetter::diffuserMessage(std::string message, fonctionCallback antenne) {
	antenne(message, m_ID);
	Sleep(100);
}