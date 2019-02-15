#include<iostream>
#include<ctime>
using namespace std;

//************************************************
//       Function to Get Input from User         *
//************************************************
void takeInput (int &a)
{
	cout << "Please enter required total for DICE: ";
	cin >> a;
}

//************************************************
//             Function of rollDice              *
//************************************************
int rollDice (int total)
{
	srand (time(0));
	int sum=0;
	int count=0;
	while ( sum != total )
	{
		sum= ( rand() % 6+1 ) + ( rand() % 6+1 );
		count++;
	}
	return count;
}

int main ()
{
	int number;
	takeInput (number);
	cout << "Total no of ROOLS Taken: " << rollDice (number) << endl;
	return 0;
}