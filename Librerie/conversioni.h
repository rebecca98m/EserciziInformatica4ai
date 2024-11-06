#include<string>
#include<cmath>

int stringToInt(string stringa) {
	int numero = 0;
	bool negativo = false;
	int posizioneIniziale = 0;
	
	if(stringa[0] == '-') {
		negativo = true;
		posizioneIniziale=1;
	}
	
	for(int i=stringa.size()-1; i>=posizioneIniziale; i--) {
		numero += stringa[i]*pow(10,i);
	}
	
	if(negativo) {
		numero = numero*(-1);
	}
	
	return numero;
	
}



double stringToDouble(string stringa) {
	double numero = 0;
	bool negativo = false;
	int posizionePunto = 0;
	int posizioneIniziale = 0;
	
	while(posizionePunto < stringa.size() && stringa[posizionePunto] != '.') {
		posizionePunto++;
	}
	
	if(stringa[0] == '-') {
		negativo = true;
		posizioneIniziale = 1;
	}
	int posizioneInteri=0;
	for(int i=posizionePunto-1; i>=posizioneIniziale; i--) {
		numero += stringa[i]*pow(10,posizioneInteri);
		posizioneInteri++;
	}
	int posizioneDecimali=-1;
	for(int i= posizionePunto+1; i<stringa.size(); i++) {
		numero += stringa[i]*pow(10,posizioneDecimali);
		posizioneDecimali--;
	}
	
	if(negativo) {
		numero = numero*(-1);
	}
	
	return numero;
	
}
