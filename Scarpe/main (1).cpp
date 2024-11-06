//Nel seguente file sono presenti 10 errori. Correggili.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct SCARPA {
	string marca;
	string modello;
	string taglia;
	string prezzo;	
};

const char fileArchivio[] = "./dati/scarpe.csv";

void stampaScarpa(SCARPA scarpa) {
	cout << "Scarpa: " << endl;
	cout << "Marca: " << scarpa.marca << endl;
	cout << "Modello: " << scarpa.modello << endl; //1. scarpa.modello
	cout << "Taglia: " << scarpa.taglia << endl;
	cout << "Prezzo: " << scarpa.prezzo << endl;
	cout << endl;
}

string estraiValori(string& riga) {
    string elementoEstratto = "";
    int posizione = 0;

    while (posizione < riga.size() && riga[posizione] != ',') {
        elementoEstratto += riga[posizione]; //2. concatenazione
        posizione++; // 3. ciclo infinito
    }

    if (posizione < riga.size() && riga[posizione] == ',') {
        posizione++;
    }

    string nuovaRiga = "";
    for (int j = posizione; j < riga.size(); j++) { //4. saltiamo l'ultimo carattere
        nuovaRiga += riga[j];
    }
    riga = nuovaRiga;

    return elementoEstratto;

}

void caricaDatiDaFile(SCARPA array[], int& nScarpe) { //10. nScarpe va passato per riferimento
	nScarpe=0;  //5. nScarpe non ha un valore
	string scarpa;
	ifstream file(fileArchivio);
	file >> scarpa;
	
	while(file >> scarpa) {
		array[nScarpe].marca = estraiValori(scarpa);
		array[nScarpe].modello = estraiValori(scarpa);
		array[nScarpe].taglia = estraiValori(scarpa);
		array[nScarpe].prezzo = estraiValori(scarpa);
		nScarpe++; //6. se no sovrascrive sempre la stessa
	}
}


void salvaDatiSuFile(SCARPA array[], int nScarpe) {
	ofstream file(fileArchivio);

	file << "marca,modello,taglia,prezzo \n";

	for(int i=0; i<nScarpe; i++) {
		file << array[i].marca;
		file << ',';
		file << array[i].modello;
		file << ',';
		file << array[i].taglia;
		file << ',';
		file << array[i].prezzo;
		file << '\n';
	}
}

int main() {
	const int maxScarpe = 20;
	int nScarpe;
	SCARPA array[maxScarpe];

	caricaDatiDaFile(array, nScarpe); //7. La funzione chiede un array non una scarpa
	
	for(int i=0; i<nScarpe; i++) { //8. i=0 se no saltiamo la prima scarpa
		stampaScarpa(array[i]); //9. dobbiamo cambiare ogni volta scarpa da stampare
	}
}
