#pragma once

class composant1 {
public: 
	void msg();
};

class composant2 {
public: 
	void msg();
};
class composant3 {
public:
	void msg();
};

class gp1 {
public: 
	void gpcs1s1();
	void gpcs1s2();

private:
	composant1 c1;
	composant2 c2;
	composant3 c3;
};

class gp2 {
public:
	void gpcs2s1();

private:
	composant1 c1;
	composant3 c3;
};