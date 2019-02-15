#include <iostream>
using namespace std;

//*********************************************************
// Fuction creates a copy of the array, except that the   * 
//      Element values are reversed in the copy.          *
//*********************************************************
int* createArray (int a[], const int SIZE)
{
	int *p;
	p = new int [SIZE];
	for (int i=0 ;i<SIZE; i++)
		p[i] = a[SIZE-1-i];
	return p;
}

//*********************************************************
//  Function accepts a pointer to array with its size     *
//     and displays all the contents of the array.        *
//*********************************************************
void showData (int *p, const int SIZE)
{
	for (int i=0; i<SIZE; i++)
		cout << p[i] <<" ";
	cout << endl;
}

//*********************************************************
//      Function gets values in An ARRAY                  *
//*********************************************************
void getValues (int a[], const int SIZE)
{
	for (int i=0; i<SIZE ;i++)
		cin >> a[i];
}

int main ()
{
	int *p;
	const int size=5;
	int x[size];

	cout << "Enter Values \n";
	getValues (x,size);                 //Get input in array

	p=createArray (x,size);            //reverse copy of array

	cout << "Values in Reverse Order \n";
	showData (p,size);               // shows all values of array

	delete []p;
	return 0;
}