/*Scrivi una funzione ricorsiva int mcd(int a, int b) che calcoli
il massimo comune divisore di due numeri interi
a e b utilizzando l'algoritmo di Euclide,
basato sulla relazione mcd(a, b) = mcd(b, a % b)
finché b non diventa zero*/
#include <iostream>
using namespace std;

int mcd(int a, int b){
	if(b==0) return a;
	return mcd(b, a % b);
}

int main(){
	int n1,n2,MCD;
	cout<<"\nInserisci il primo numero: ";
	cin>>n1;
	cout<<"\nInserisci il secondo numero: ";
	cin>>n2;
	
	if(n1>=n2) MCD = mcd(n1,n2);
	else MCD = mcd(n2,n1);
	
	cout<<"\n L'mcd dei due numeri e' "<<MCD<<endl;
	return 0;
}
