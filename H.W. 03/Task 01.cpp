#include <iostream>
using namespace std;

//***************************************************************
//  Function returs TRUE if Elemnt is present False otherwise   *
//***************************************************************
bool isFound (float x[], const int size, float k)
{
	return (size>0) ? (x[size-1] == k) ? true : (isFound (x,size-1,k) ) : false;
}

//******************************************************
//   Function returs INDEX of specific Element         *
//******************************************************
int Findindex (float x[], const int size, float k)
{
	for (int i=0; i<size && x[i] == k; i++)
		return i;
	return 0;
}

//******************************************************
//    Function returs TRUE if Elemnt is found and      *
//  removes first occurence of Element false othewis   *
//******************************************************
bool removeFirst (float a[], int &size, float key)
{
	int index = 0;
	if (isFound (a,size,key) )
	{
		index = Findindex (a,size,key);
		for (int i=index; i<size-1; i++)
			a[i] = a[i+1];

		size--;
		return true;
	}
	else 
		return false;
}

int main ()
{
	float KEY;
	const int size = 5; int s = size;
	float x[size];

	cout << "Enter Values\n";
	for (int i=0; i<size; i++)
		cin >> x[i];                //geting values in array

	cout << "Enter number you want to remove: ";
	cin >> KEY;                   // input key

	if (removeFirst (x,s,KEY))   // remove function call
	{
		cout << "Contents after removing \n";
		for (int i=0; i<s; i++)
			cout << x[i] << " ";   // displaying all contents after removing key
	}

	else 
		cout << "Not found" << endl;        // if element is not founded 

	return 0;
}