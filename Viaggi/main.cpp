/*Crea un programma che permetta all'utente di gestire un'agenzia di viaggi. 
Di ogni viaggio si vogliono memorizzare NOME DESTINAZIONE NUMERO DI GIORNI PREZZO BASE GIORNALIERO
 ELENCO di massimo 10 persone che possono partecipare al viaggio.
 Di ogni persona vanno memorizzati NOME COGNOME DATA DI NASCITA SESSO e se si tratta di un'utente con convenzione.
Il programma deve permettere di
 aggiungere un viaggio
Aggiungere un utente al viaggio
Calcolare il costo di uno specifico utente tenendo conto che se l'utente è minorenne ha un 30% di sconto,
se ha la convenzione ha 10% di sconto gli sconti sono comulabile  
CARICARE E SALVARE SU UN FILE CSV*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int maxViaggi=20;
const int maxPersone=10;
const char viaggio[]="...csv";
const char persone[]="...csv"

struct DATA{
	
	int giorno;
	int mese;
	int anno;
	
};

struct PERSONA{
	
	string nome;
	string cognome;
	DATA data;
	bool sesso;
	bool convenzione;
	
};

struct VIAGGIO{
	
	string nome;
	string destinazione;
	int nGiorni;
	double prezzoBaseGiornaliero;
	PERSONA elenco[maxPersone];
	int nPersone;
	
};

void caricaDati(VIAGGIO viaggi[], int nViaggi){
	
	ifstream iViaggi(viaggi);
	
	string elemento,riga;
	int posizione;
	
	while(getline(iViaggi,riga)){
		
		sstream streamRiga(riga);
		posizione=0;
		
		while(getline(streamRiga,elemento,',')){
			
				
				
				
			}
			
		}
		
	}
	
}

void salvaDati(VIAGGIO viaggi[], int nViaggi){
	
	ofstream outViaggi(viaggio);
	
	outViaggi<<"nome,destinazione,numeroGiorni,prezzoBase,nPersone \n";
	
	for(int i=0 ; i<nViaggi ; i++){
		
		outViaggi<<viaggi[i].nome<<",";
		outViaggi<<viaggi[i].destinazione<<",";
		outViaggi<<viaggi[i].nGiorni<<",";
		outViaggi<<viaggi[i].prezzoBaseGiornaliero<<",";
		outViaggi<<viaggi[i].nPersone<<"\n";
		
	}
	
	outFile.close();
	
	ofstream outPersone(persone);
	
	outPersone<<"nome,cognome,giorno,mese,anno,sesso,convenzione \n";
	
	for(int i=0 ; i<nViaggi ; i++){
		
		for(int j=0 ; j<viaggi[i].nPersone ; j++){
			
			outPersone<<"Viaggio numero "<<i<<"\n";
			outPersone<<viaggi[i].elenco[j].nome<<",";
			outPersone<<viaggi[i].elenco[j].cognome<<",";
			outPersone<<viaggi[i].elenco[j].data.giorno<<",";
			outPersone<<viaggi[i].elenco[j].data.mese<<",";
			outPersone<<viaggi[i].elenco[j].data.anno<<",";
			
			if(viaggi[i].elenco[j].sesso) outPersone<<"Maschio"<<",";
			else outPersone<<"Femmina"<<","
			
			if(viaggi[i].elenco[j].convenzione) outPersone<<"Si"<<"\n";
			else outPersone<<"No"<<"\n";
			
		}
		
	}
	
}

void aggiungiViaggio(VIAGGIO viaggi[], int& nViaggi){
	
	if(nViaggi>=maxViaggi) cout<<"Numero massimo di viaggi raggiunto"<<endl;
	
	else{
		
		cout<<"Inserire il nome del viaggio ";
		cin>>viaggi[nViaggi].nome;
		
		cout<<"Inserire la destinazione del viaggio: ";
		cin>>viaggi[nViaggi].destinazione;
		
		cout<<"Inserire il numero di giorni ";
		cin>>viaggi[nViaggi].nGiorni;
		
		cout<<"Inserire il prezzo base giornaliero: ";
		cin>>viaggi[nViaggi].prezzoBaseGiornaliero;
		
		nPersone=0;
		
		nViaggi++;
		
	}
	
}

int trovaViaggio(VIAGGIO viaggi[], int nViaggi){
	
	string scelta;
	
	cout<<"Inserire il nome del viaggio: ";
	cin>>scelta;
	
	for(int i=0 ; i<nViaggio ; i++){
		
		if(scelta==viaggi[i].nome) return i;
		
	}
	
	return -1;
	
}

void aggiungiUtente(VIAGGIO viaggi[], int nViaggi){
	
	int posizioneViaggio=trovaViaggio(viaggi,nViaggi);
	
	if(posizioneViaggio==-1) cout<<"Il viaggio non esiste"<<endl;
	
	else if(maxPersone==nPersone) cout<<"Il limite delle persone e' stato raggiunto :("<<endl;
	
	else{
		
		cout<<"Inserisci il nome: ";
		cin>>viaggi[posizioneViaggio].elenco[nPersone].nome;
		
		cout<<"Inserisci il cognome: ";
		cin>>viaggi[posizioneViaggio].elenco[nPersone].cognome;
		
		cout<<"Inserire il data di nascita"<<endl;
		cout<<"Giorno: ";
		cin>>viaggi[posizioneViaggio].elenco[nPersone].data.giorno;
		cout<<"Mese: ";
		cin>>viaggi[posizioneViaggio].elenco[nPersone].data.mese;
		cout<<"Anno: ";
		cin>>viaggi[posizioneViaggio].elenco[nPersone].data.anno;
		
		cout<<"Inserire il sesso: (1 maschio 0 femmina) ";
		cin>>viaggi[posizioneViaggio].elenco[nPersone].sesso;
		
		cout<<"Ha la convenzione? (1 Si 0 No)";
		cin>>viaggi[posizioneViaggio].elenco[nPersone].convenzione;
		
		viaggi[posizioneViaggio].nPersone++;
		
	}
			
}

int trovaPersona(VIAGGIO viaggi[], int nViaggi){
	
	string nome,cognome;
	
	cout<<"Inserire il nome della persona: ";
	cin>>nome;
	cout<<"Inserire il cognome: ";
	cin>>cognome;
	
	for(int i=0 ; i<nViaggi ; i++){
		
		for(int j=0 ; j<viaggi[i].nPersone ; j++){
		
			if(nome==viaggi[i].elenco[j].nome && cognome==viaggi[i].elenco[j].cognome) return i;
			
		}
		
	}
	
	return -1;
	
}

bool isMinorenne(PERSONA persona){
	
	int giorno,mese,anno;
	
	cout<<"Che giorno e' oggi? ";
	cin>>giorno;
	cout<<"Di che mese? ";
	cin>>mese;
	cout<<"Di che anno? ";
	cin>>anno;
	
	if(anno-persona.data.anno>18) return false; 
	
	if(anno-persona.data.anno<18) return true;
	
	if(mese>persona.data.mese) return false;
	
	if(mese<persona.data.mese) return true;
	
	if(giorno>persona.data.giorno) return false;
	
	if(giorno<persona.data.giorno) return true;
	
	return false;
	
}

double calcolaCosto(VIAGGIO viaggi[], int nViaggi){
	
	int posizioneViaggio=trovaViaggio(viaggi, nViaggi);
	
	int posizionePersona=trovaPersona(viaggi, nViaggi);
	
	double totale=viaggi[posizioneViaggio].nGiorni*viaggi[posizioneViaggio].prezzoBaseGiornaliero;
	
	if(isMinorenne(viaggi[posizioneViaggio].elenco[posizionePersona])) totale-=(totale/100)*30;
	
	if(viaggi[posizioneViaggio].elenco[posizionePersona].convenzione) totale-=(totale/100)*10;
	
	return totale;
	
}

int main(){
	
	int scelta;
	
	VIAGGIO viaggi[maxViaggi];
	int nViaggi;
	
	do{
		
		cout<<"MENU"<<endl;
		cout<<"1) Aggiungere un viaggio"<<endl;
		cout<<"2) Aggiungere una persona al viaggio"<<endl;
		cout<<"3) Calcolare il costo di uno specifico utente"<<endl;
		cout<<"0) ESCI"<<endl;
		cin>>scelta;
		
		switch(scelta){
			
			case 1:
			case 2:
			case 3:
			default: cout<<"Scelta non disponibile"<<endl;
			
		}
		
	}while();
	
	
	
	system("pause");
	return 0;
}
