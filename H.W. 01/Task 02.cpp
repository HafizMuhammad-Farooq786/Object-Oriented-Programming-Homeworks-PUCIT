#include<iostream>
using namespace std;
#define basic 200

double salary (double sales)
{
	return basic+(sales*(9/100.0));
}

int main()
{
	double sales;
	cout<<"Enter Sales in Rupees(-1 to end): ";
	cin>>sales;
	while(sales!=-1)
	{
		cout<<"Salary is: "<<salary(sales)<<endl;
	    cout<<"Enter Sales in Rupees(-1 to end): ";
	    cin>>sales;
	}

	system("pause");
	return 0;
}