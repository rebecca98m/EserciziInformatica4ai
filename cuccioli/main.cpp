#include <iostream>
using namespace std;

typedef struct{
	string nome;
	string razza;
	int mesi;
	double peso;
} cucciolo;

void salvaDati(cucciolo *allevamento, int dimensione) {
	
	for(int i=0; i<dimensione; i++) {
		
		
	}
}




int main() {
	const int dimensione = 10;
	cucciolo allevamento[dimensione];
	
	//cucciolo *puntatore = &allevamento[0];
	cucciolo *puntatore = allevamento;
	
	for(int i=0; i<dimensione; i++) {
		cout << "Inserisci il nome: ";
		cin >> puntatore->nome;
		cout << "Inserisci la razza: ";
		cin >> puntatore->razza;
		cout << "Inserisci il peso: ";
		cin >> puntatore->peso;
		cout << "Inserisci i mesi: ";
		cin >> puntatore->mesi;
		
		puntatore++;
	}
	
	puntatore = allevamento;
	salvaDati(puntatore, dimensione);
	
}







