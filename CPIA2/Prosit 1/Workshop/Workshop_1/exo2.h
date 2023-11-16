#pragma once
class CLcalcul {
private:
	int n;
	void ini(int val);
	static int cpteObj;
public:
	CLcalcul(void);
	CLcalcul(int val);
	static int cbnObj();
	void carre(void);
	void setN(int val);
	int getN(void);
};