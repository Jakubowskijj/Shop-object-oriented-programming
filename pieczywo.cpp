#include "pieczywo.h"
using namespace std;

pieczywo::pieczywo(float cena) {
	cena = cena;
}

pieczywo::~pieczywo() {

}

tostowy::tostowy(float cena) :pieczywo(cena) {
	pieczywo::cena = cena;
}

float tostowy::cena1() {
	return pieczywo::cena;
}


bulka::bulka(float cena) :pieczywo(cena) {
	pieczywo::cena = cena;
}

float bulka::cena1() {
	return pieczywo::cena;
}

paczek::paczek(float cena) :pieczywo(cena) {
	pieczywo::cena = cena;
}

float paczek::cena1() {
	return pieczywo::cena;
}