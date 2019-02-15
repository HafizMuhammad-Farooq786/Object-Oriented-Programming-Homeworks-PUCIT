#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void greet (string s)
{
	cout << "Hello, ";
	for (int i=0; s[i]!='\0'; i++)
		cout << (char) toupper (s[i]);
	cout << ", Nice to meet you \n";
}

int main()
{
	string name;
	cout << "Enter your Name: ";
	getline (cin,name);
	cout << "Programme Respond: ";
	greet (name);
	return 0;
}