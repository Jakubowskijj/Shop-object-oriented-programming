#include <iostream>
#include<fstream>
#include<Windows.h>
#include<cstdlib>
#include"pieczywo.h"
#include"nabial.h"
#include"alkohole.h"
#include<string>

using namespace std;


void klient();
void pracownik();
void pieczywo1();
void nabial1();
void alkohol1();
void przyjaciel(jajka j);

	bool wyjscie = 1;
char kto;
char kategoria;
char piecz;
char nab;
char alk;
float suma = 0;
int koszyk =0;
short int dodaj;

int main()
{//							  wsk[0]			wsk[1]			  wsk[2]
	pieczywo* wsk[] = { new tostowy(3.20), new bulka(0.70), new paczek(2.70) };
	jajka kurze;
	jogurt tlusty;
	mleko krowie;
	piwo perla(2.99);
	whisky szkocka(55.99);
	wodka czysta(21);


	string linia;
	int nr_linii = 1;

	fstream plik;
	plik.open("magazyn.txt", ios::in);

	if (plik.good() == false) cout << "Nie mozna otworzyc pliku!";

	while (getline(plik, linia))
	{
		switch (nr_linii)
		{
		case 1: wsk[0]->ilosc = std::stoi(linia); break;
		case 2: wsk[1]->ilosc = std::stoi(linia); break;
		case 3: wsk[2]->ilosc = std::stoi(linia); break;
		case 4: kurze.ilosc = std::stoi(linia); break;
		case 5: tlusty.ilosc = std::stoi(linia); break;
		case 6: krowie.ilosc = std::stoi(linia); break;
		case 7: perla.ilosc = std::stoi(linia); break;
		case 8: szkocka.ilosc = std::stoi(linia); break;
		case 9: czysta.ilosc = std::stoi(linia); break;
		}
		nr_linii++;
	}
	plik.close();

	


	cout << "----------Witaj w naszym sklepie----------" << endl;
	cout << "-Jestem klientem (k)" << endl;
	cout << "-Jestem pracownikiem (p)" << endl;
	cout << "------------------------------------------" << endl;
	cout << endl << "kim jestes? Wybierz opcje z nawisu:";
	cin >> kto;

		switch (kto) {
		case 'k':		//#################################################Jesli klient#################################################
			while (kategoria != 'i') {
				klient();
				switch (kategoria) {
				case 'p':
					piecz = 'q';
					while (piecz != 'w') {
						pieczywo1();
						switch (piecz) {
						case 't':
							wsk[0]->ilosc--;
							suma += wsk[0]->cena1();
							koszyk++;
							break;
						case 'b':
							wsk[1]->ilosc--;
							suma += wsk[1]->cena1();
							koszyk++;
							break;
						case 'p':
							wsk[2]->ilosc--;
							suma += wsk[2]->cena1();
							koszyk++;
							break;
						}
					}
					break;

				case 'n':
					nab = 'q';
					while (nab != 'w') {
					nabial1();
					switch (nab) {
					case 'j':
						kurze.ilosc--;
						suma += kurze.cena;
						koszyk++;
						przyjaciel(kurze);
						break;
					case 'n':
						tlusty.ilosc--;
						suma += tlusty.cena;
						koszyk++;
						break;
					case 'm':
						krowie.ilosc--;
						suma += krowie.cena;
						koszyk++;
						break;
					}
					}
					break;
				case 'a':
					alk = 'q';
					while (alk != 'w') {
						alkohol1();
						switch (alk) {
						case 'p':
							perla.ilosc--;
							suma += perla.cena;
							koszyk++;
							break;
						case 'h':
							szkocka.ilosc--;
							suma += szkocka.cena;
							koszyk++;
							break;
						case 'o':
							czysta.ilosc--;
							suma += czysta.cena;
							koszyk++;
							break;
						}
					}
					break;
				}
			}
			break;
		case 'p':		//#################################################Jesli pracownik#################################################
			while (dodaj != 10) {
				pracownik();
				switch (dodaj) {
				case 1:
					wsk[0]->ilosc++;
					system("CLS");
					cout << "dodano jeden chleb tostowy";
					Sleep(500);
					break;
				case 2:
					wsk[1]->ilosc++;
					system("CLS");
					cout << "dodano jedna bulke";
					Sleep(500);
					break;
				case 3:
					wsk[2]->ilosc++;
					system("CLS");
					cout << "dodano jedenego paczka";
					Sleep(500);
					break;
				case 4:
					kurze.ilosc++;
					system("CLS");
					cout << "dodano jedno opakowanie jajek";
					Sleep(500);
					break;
				case 5:
					tlusty.ilosc++;
					system("CLS");
					cout << "dodano jeden jogurt naturalny";
					Sleep(500);
					break;
				case 6:
					krowie.ilosc++;
					system("CLS");
					cout << "dodano jedno mleko";
					Sleep(500);
					break;
				case 7:
					perla.ilosc++;
					system("CLS");
					cout << "dodano jedno piwo";
					Sleep(500);
					break;
				case 8:
					szkocka.ilosc++;
					system("CLS");
					cout << "dodano jedna whisky";
					Sleep(500);
					break;
				case 9:
					czysta.ilosc++;
					system("CLS");
					cout << "dodano jedna wodke";
					Sleep(500);
					break;
				}
			}
			

			break;
		default:
			cout << "Niestety niewimy kim jestes, prosimy ciebie o wyjscie." << endl;
			wyjscie = 0;
			break;
		}
		if (koszyk > 0) {
			system("CLS");
			cout << "Kupiles " << koszyk << " rzeczy" << endl;
			cout << "Laczna suma do zaplaty to " << suma << " zl" << endl;
		}




		plik.open("magazyn.txt", ios::out);

		plik << wsk[0]->ilosc << endl;
		plik << wsk[1]->ilosc << endl;
		plik << wsk[2]->ilosc << endl;
		plik << kurze.ilosc << endl;
		plik << tlusty.ilosc << endl;
		plik << krowie.ilosc << endl;
		plik << perla.ilosc << endl;
		plik << szkocka.ilosc << endl;
		plik << czysta.ilosc << endl;
		plik.close();
		
		delete wsk[0];
		delete wsk[1];
		delete wsk[2];

	return 0;

}


void klient() {
	system("CLS");
	cout << "----------Witaj kliencie, wybierz co chcesz kupic z ponizszych kategorii----------	  Ilosc rzeczy w koszyku:" << koszyk << endl;
	cout << "Pieczywo(p)										  Do zaplat:" << suma << endl;
	cout << "Nabial(n)" << endl;
	cout << "Alkohol(a)" << endl;
	cout << "Ide do kasy(i)" << endl;
	cout << endl << "Wybierz z jakiej kategori chcesz produkt, a nastepnie podaj opcje z nawisu:";
	cin >> kategoria;
}


void pieczywo1() {
	system("CLS");
	cout << "Chleb tostowy (t) 3.20zl								  Ilosc rzeczy w koszyku:" << koszyk<< endl;
	cout << "Bulka (b) 0.70zl									  Do zaplat:" << suma << endl;									
	cout << "Paczek(p) 2.70zl" << endl;
	cout << "Wracam do kategori(w)" << endl;

	cout << endl << "Aby wsadzic przedmiot do swojego koszyka podaj literke z nawiasu:";
	cin >> piecz;

}

void nabial1() {
	system("CLS");
	cout << "Jajka 10szt.(j) 6.50zl									Ilosc rzeczy w koszyku:" << koszyk << endl;
	cout << "Jogurt naturalny(n) 1.90zl								Do zaplat:" << suma << endl;
	cout << "Mleko(m) 3zl"  << endl;
	cout << "Wracam do kategori(w)" << endl;
	cout << endl << "Aby wsadzic przedmiot do swojego koszyka podaj literke z nawiasu:";
	cin >> nab;

}


void alkohol1(){
	system("CLS");
	cout << "Piwo(p) 2.99zl								Ilosc rzeczy w koszyku:" << koszyk << endl;
	cout << "Whisky(h) 55.99zl 							Do zaplat:" << suma << endl;
	cout << "Wodka(o) 21zl" << endl;
	cout << "Wracam do kategori(w)" << endl;
	cout << endl << "Aby wsadzic przedmiot do swojego koszyka podaj literke z nawiasu:";
	cin >> alk;
}


void pracownik() {
	system("CLS");
	cout << "----------Witaj pracowniku, jaki produkt chcesz uzupelnic----------" << endl;
	cout << "Chleb tostowy(1)" << endl;
	cout << "Bulka(2)" << endl;
	cout << "Paczek(3)" << endl;
	cout << "Jajka 10szt.(4)" << endl;
	cout << "Jogurt naturalny(5)" << endl;
	cout << "Mleko(6)" << endl;
	cout << "Piwo(7)" << endl;
	cout << "Whisky(8)" << endl;
	cout << "Wodka(9)" << endl;
	cout << "Koncze na dzisiaj(10)" << endl;
	cout << endl << "Wybierz jaki produkt chcesz dodac, a nastepnie podaj jego kod z nawiasu z nawisu:";
	cin >> dodaj;
}


void przyjaciel(jajka j) {
	system("CLS");
	cout << "Po tym zakupie zostalo tylko " << j.ilosc << " jajek" << endl;
	Sleep(1500);
}