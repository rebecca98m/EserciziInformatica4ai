#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct SCARPA {
	string marca;
	string modello;
	int taglia;
	double prezzo;	
};

const char fileArchivio[] = "./dati/scarpe.csv";

void stampaScarpa(SCARPA scarpa) {
	cout << "Scarpa: " << endl;
	cout << "Marca: " << scarpa.marca << endl;
	cout << "Modello: " << scarpa.modello << endl;
	cout << "Taglia: " << scarpa.taglia << endl;
	cout << "Prezzo: " << scarpa.prezzo << endl;
	cout << endl;
}

string estraiValori(string riga) {
	int posizione = 0;
	while(riga[posizione] != ',' && posizione < riga.size()) {
		posizione++;
	}
	if(posizione > riga.size()) {
		string elementoEstratto = riga;
		riga = "";
		return elementoEstratto;
	}
	
	posizione = 0;
	while(riga[posizione] != ',') {
		posizione++;
	}
	string elementoEstratto="";
	for(int i=0; i<posizione; i++) {
		elementoEstratto += riga[i];
	}
	
	posizione++;
	string newRiga = "";
	
	for(int i=0; i<riga.size()-posizione; i++) {
		newRiga += riga[posizione + i];
	}
	riga = newRiga;
	return elementoEstratto;
}

void caricaDatiDaFile(SCARPA array[], int& nScarpe) {
	nScarpe=0;
	string scarpa;
	
	ifstream file(fileArchivio);
	while(file >> scarpa) {
		cout << scarpa;
		cout << endl;
	}
	
}

int main() {
	const int maxScarpe = 20;
	int nScarpe;
	SCARPA array[maxScarpe];

	caricaDatiDaFile(array, nScarpe);
	
	for(int i=0; i<nScarpe; i++) {
		stampaScarpa(array[i]);
	}
}
