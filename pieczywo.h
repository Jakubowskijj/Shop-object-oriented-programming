#pragma once
#include <iostream>
#include<fstream>
#include<Windows.h>
#include<cstdlib>
using namespace std;
class pieczywo
{
protected:
	float cena;
public:
	pieczywo(float cena);
	int ilosc =0;
	virtual float cena1() = 0;
	virtual ~pieczywo();
};


class tostowy :public pieczywo {
public:
	tostowy(float cena);
	float cena1();
	~tostowy() {};
};

class bulka :public pieczywo {
public:
	bulka(float cena);
	float cena1();
	~bulka() {};
};

class paczek :public pieczywo {
public:
	paczek(float cena);
	float cena1();
	~paczek() {};
};