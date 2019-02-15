# include <iostream>
using namespace std;

//********************************************************************
// function rotates the elements of the array a, number of positions 
// to the right (or number of positions to the left if k is negative).
//********************************************************************
void rotate (int a[], int size, int position)
{
	int *p = new int [size];
	for (int i=0; i<size; i++)
		p[i] = a[i];
	
	for (int i=0; i<size; i++)
		(position < 0) ? a[ (size+position)-i ] = p[i] : a[ (i+position) % size ] = p[i];

	delete []p;
}

int main ()
{
	const int size=8;
	int x[size] = {22,33,44,55,66,77,88,99};

	rotate (x,size,4);                  // rotating values of array

	cout << "Values after Rotating \n";
	for (int i=0; i<size; i++)
		cout << x[i] << " ";       // displaying all values of array after rotating

	return 0;
}