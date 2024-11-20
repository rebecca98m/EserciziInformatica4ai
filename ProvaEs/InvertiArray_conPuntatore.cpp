/*Scrivi una funzione invertiArray che inverta l’ordine
degli elementi di un array utilizzando puntatori*/
#include <iostream>
using namespace std;

void InvertiArray(int Array[],int Inizio, int Fine){
	if(Fine <= Inizio ) return;
	int *p1 = &Array[Inizio];
	int *p2 = &Array[Fine];
	
	int temp = *p2;
	*p2 = *p1;
	*p1 = temp;
	
	return InvertiArray(Array,Inizio+1,Fine-1);
}

int main(){
	const int dimensione = 4;
	int array[dimensione];
	
	for(int i=0; i<dimensione; i++){
		cin>>array[i];
	}
	
	InvertiArray(array,0,dimensione-1);
	cout<<endl;
	for(int i=0; i<dimensione; i++) cout<<array[i]<<",";
	return 0;
}
