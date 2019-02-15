#include <iostream>
using namespace std;

//********************************************************************
// The function adds the adjacent elements of two array a and b and  *
// places there sum to the newly created array and return it if      *
// possible, return NULL otherwise. The addition is only possible if *
// the sizes of both the  arrays are equal.                          *
//********************************************************************
float * add (const float a[], const float b[], int sizeofa, int sizeofb)
{
	float *p;
	p = new float [sizeofa];
	if(sizeofa == sizeofb)
		for (int i=0; i<sizeofa ;i++)
			p[i] = a[i] + b[i];         
	else 
		p = 0;
	return p;

}

//*********************************************************
//           Function gets input in array                 *
//*********************************************************
void getValues (float a[], int size)
{
	for (int i=0; i<size; i++ )
		cin >> a[i];
	cout << endl;
}

int main ()
{
	float *p; 
	const int sizeX = 5;
	const int sizeY = 4;
	float x[sizeX];
	float y[sizeY];
	

	cout << "Enter Values for X \n";
	getValues (x,sizeX);                  //geting values for 1st array
	cout << "Enter Values for Y \n";
	getValues (y,sizeY);                  //geting values for 2nd array
	 
	p = add (x,y,sizeX,sizeY);           //Calling Function for add

	if (p != 0)                         //if addition is possible
	{
		for (int i=0; i<sizeX ;i++)          
			cout << p[i] <<" ";        //shows added values of array
		delete []p;
	}
	
	else                             // if addition is not possible
	{
		cout << "NULL" << endl;
		delete []p;
	}

	return 0;
}