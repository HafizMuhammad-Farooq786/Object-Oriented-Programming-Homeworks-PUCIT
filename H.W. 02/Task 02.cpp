#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char A[20];
	int count_digits=0, count_space=0, count_upercase=0, count_lowercase=0, count_punct=0 ;

	cin.getline (A,20);

	for(int i=0; A[i]!='\0'; i++)
	{
		if ( isdigit (A[i]) )
			count_digits++;
		if ( isspace (A[i]) )
			count_space++;
		if( ispunct (A[i]) )
			count_punct++;
		if( isupper (A[i]) )
			count_upercase++;
		if( islower (A[i]) )
			count_lowercase++;
	}

	cout << "Total number of digits: " << count_digits << endl;
	cout << "Total number of spaces: " << count_space << endl;
	cout << "Total number of punctuation: " << count_punct << endl;
	cout << "Total number of Upercases Characters: " << count_upercase << endl;
	cout<<"Total number of Lowercases Characters: "<<count_lowercase<<endl;
	return 0;
}