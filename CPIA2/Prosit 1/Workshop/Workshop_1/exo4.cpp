#include "pch.h"

using namespace std;

fraction::fraction(int numerateur, int denominateur) {
	m_num = numerateur;
	if (denominateur == 0) {
		throw invalid_argument("Un dénominateur nul a ete entre");
	}
	else {
		m_den = denominateur;
	}
}

fraction::fraction() {
	m_num = m_den = 1;
}

fraction fraction::operator+(fraction toAdd) {
	int newNum, newDen;
	newNum = m_den * toAdd.getNum() + m_num * toAdd.getDen();
	newDen = m_den * toAdd.getDen();
	return fraction(newNum, newDen);
}

fraction fraction::operator-(fraction toSub) {
	int newNum, newDen;
	newNum = m_num * toSub.getDen() - m_den * toSub.getNum();
	newDen = m_den * toSub.getDen();
	return fraction(newNum, newDen);
}

fraction fraction::operator/(fraction toSub) {
	if (toSub.getNum() == 0) {
		throw invalid_argument("Un denominateur nul a ete fourni");
	}
	else {
		int newNum, newDen;
		newNum = m_num * toSub.getDen();
		newDen = m_den * toSub.getNum();
		return fraction(newNum, newDen);
	}
}

fraction fraction::operator*(fraction toSub) {
	int newNum, newDen;
	newNum = m_num * toSub.getNum();
	newDen = m_den * toSub.getDen();
	return fraction(newNum, newDen);
}

int fraction::getNum() {
	return m_num;
}

int fraction::getDen() {
	return m_den;
}