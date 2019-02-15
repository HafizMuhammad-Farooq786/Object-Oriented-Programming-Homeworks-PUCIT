#include<iostream>
using namespace std;
//************************************************
//  Function to check Range Of Numbers           *
//************************************************
bool checkRange(int x)
{
	if((x>30)||(x<1))
		return true;
	else
		return false;
}

//************************************************
//  Function to Get Values in Array from User    *
//************************************************
void getValues (int a[],const int SIZE)
{
	for(int i=0;i<SIZE;i++)
	{
		cout<<"Enter number "<<i+1<<": ";
		cin>>a[i];
	}
}

//************************************************
//           Function to Print Stars             *
//************************************************
void showstars (int n)
{
	if(checkRange(n))
		cout<<"INVALID Value";
	else
	{
		for(int i=1; i<=n ;i++)
			cout<<"*";
	}
	cout<<endl;
}

int main()
{
	int numbers[5];

	getValues(numbers,5);
	cout<<endl;

	for(int i=0;i<5;i++)
		showstars(numbers[i]);

	system("pause");
	return 0;
}