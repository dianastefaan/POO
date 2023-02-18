#include <iostream>
#include <string.h>
using namespace std;


enum Tip {primar,gimnaziu,liceu};

class Scoala {

public:
	Tip tip;
	char* denumire;
	string judet;
	double nrElevi;
	bool invatamantPrivat;



	Scoala() { //constr fara param

		this->tip = liceu;
		this->denumire = new char[strlen("C-tin Brancoveanu") + 1];
		strcpy_s(this->denumire , strlen("C-tin Brancoveanu") + 1, "C-tin Brancoveanu");
		this->judet = "Valcea";
		this->nrElevi = 1200;
		this->invatamantPrivat = false;

	 }

	

	Scoala(const char* denumire, double nrElevi) { //constr cu 2 param
		
		this->tip = primar;
		this->judet = "Valcea";
		this->invatamantPrivat = true;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->nrElevi = nrElevi;

	}



	Scoala(Tip tip,const char* denumire,string judet,double nrElevi, bool invatamantPrivat ) { //constr cu TOTI param

		this->tip = tip;
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->judet = judet;
		this->nrElevi = nrElevi;
		this->invatamantPrivat = invatamantPrivat;

	}



	void Afisare() { //functia de afisare pt clasa scoala

		if (tip == primar) {
			cout << "Scoala primara ";
		}
		if (tip == gimnaziu) {
			cout << "Scoala gimnaziala ";
		}
		if (tip == liceu) {
			cout << "Liceul ";
		}

		cout << this->denumire << " din judetul " << this->judet << " are un numar de " << this->nrElevi << " elevi si ";

		if (invatamantPrivat == false) {
			cout << "nu este invatamant privat.";
		}
		if (invatamantPrivat == true) {
			cout << "este invatamant privat.";
		}
		cout << endl;
	}


};




class Director {
public:

	string nume;
	char* oras;
	bool directorInPrezent;
	double salariu;
	int perioadaConducere;
    Scoala tipScoala;
	


	Director() {//constr fara param

		this->nume = "Vladu Aron";
		this->oras = new char[strlen("Horezu") + 1];
		strcpy_s(oras, strlen("Horezu") + 1, "Horezu");
		this->directorInPrezent = false;
		this->salariu = 5000;
		this->perioadaConducere = 2017;
		Director::tipScoala.tip = liceu;
		
	}



	Director(string nume, double salariu) { //constr cu 2 param

		this->nume = nume;
		this->salariu = salariu;
		this->oras = new char[strlen("Bucuresti") + 1];
		strcpy_s(oras, strlen("Bucuresti") + 1, "Bucuresti");
		this->directorInPrezent = true;
		this->perioadaConducere = 2020;
		Director::tipScoala.tip = gimnaziu;

	}



	Director(bool directorInPrezent, const char* oras, int perioadaConducere) { //3 param
		this->nume = "Nicoleta Berca";
		this->salariu = 30000;
		this->oras = new char[strlen(oras) + 1];
		strcpy_s(this->oras, strlen(oras) + 1, oras);
		this->perioadaConducere = perioadaConducere;
		this->directorInPrezent = directorInPrezent;
		Director::tipScoala.tip = primar;

	}



	Director(string nume,const char* oras,bool directorInPrezent,double salariu,int perioadaConducere) { //5 param
	
		this->nume = nume;
		this->oras = new char[strlen(oras) + 1];
		strcpy_s(this->oras, strlen(oras) + 1, oras);
		this->directorInPrezent = directorInPrezent;
		this->salariu = salariu;
		this->perioadaConducere = perioadaConducere;
		Director::tipScoala.tip = liceu;

	}
	


	void afiseaza() {  

		cout << "Director " << this->nume << " din orasul " << this->oras;

		if (directorInPrezent == false) {
			cout << " nu este director in prezent, dar a fost in anul ";
		}
		if (directorInPrezent == true) {
			cout << " este director in prezent din anul ";
		}


		cout << this->perioadaConducere << " la";

		if (tipScoala.tip == primar) {
			cout << " scoala primara ";
		}
		if (tipScoala.tip == gimnaziu) {
			cout << " scoala gimnaziala ";
		}
		if (tipScoala.tip == liceu) {
			cout << " liceu ";
		}


		cout << ", cu un salariu de " << this->salariu<< " euro."<< endl;
		
	}



};







void main() {



	Scoala scoala1;//primul constructor
	scoala1.Afisare();


	Scoala scoala2("Discovery kids", 100);//al doilea constructor
	scoala2.Afisare();


	Scoala scoala3(gimnaziu, "C-tin Brancusi", "Gorj", 350, false);//al treilea constructor
	scoala3.Afisare();





	Director director1;//primul constructor
	director1.afiseaza();

	Director director2("Laura Ionita", 40000);//al doilea constructor
	director2.afiseaza();

	Director director3(true, "Bucuresti", 2021);//al treilea constructor
	director3.afiseaza();

	Director director4("Radu Chivarean", "Brasov", true, 10000, 2019);//al patrulea constructor
	director4.afiseaza();
	


	
}

