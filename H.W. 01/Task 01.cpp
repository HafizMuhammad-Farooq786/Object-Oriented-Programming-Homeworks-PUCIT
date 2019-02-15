#include<iostream>
using namespace std;
//**************************************************
//  Function to check Start limit and End limit    *
//**************************************************
bool checkGreater(int a, int b)
{
	if(a>b)
		return true;
	else
		return false;
}

//**************************************************
//              Table Function                     *
//**************************************************
void table(int table_no, int start, int end)
{
	if(checkGreater(start,end))
		cout<<"Error!end limit must be greater than the start limit."<<endl;
	else
		for(int i=start; i<=end ; i++)
			cout<<table_no<<"*"<<i<<"= "<<table_no*i<<endl;
}

int main()
{
	int tableNO,start_limit,end_limit;

	cout<<"Enter Table Value: ";
	cin>>tableNO;
	cout<<"Enter Start Limit: ";
	cin>>start_limit;
	cout<<"Enter End Limit: ";
	cin>>end_limit;

	table(tableNO,start_limit,end_limit);

	system("pause");
	return 0;
}