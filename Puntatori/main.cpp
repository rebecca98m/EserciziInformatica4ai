#include <iostream>
using namespace std;
int main() {
	int a = 5;
	int b = 5;
	
	int *p1 = &a;
	int *p2 = &b;
	
	cout << a << endl;
	cout << b << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	
	cout << endl;
	
	a++;

	
	cout << a << endl;
	cout << b << endl;
	cout << *p1 << endl;
	cout << *p2 << endl;
	
	
	
	system("pause");
	return 0;
}
