//#include <iostream>
//using namespace std;
//#define SIZE 10
//
////************************************************
////  Function to Get Values in Array from User    *
////************************************************
//void getValues (int a[])
//{
//	for (int i=0; i<SIZE ;i++)
//		cin >> a[i];
//}
//
////************************************************
////         Function to assign values of 
////           array 'b' to array 'a' 
////************************************************
//void assignElements (int a[], int b[])
//{
//	for( int i=0; i<SIZE ;i++)
//		a[i] = b[i];
//}
//
////************************************************
////     Function to Swap Values of two Arrays     *
////************************************************
//void swap (int a[], int b[])
//{
//	int c[SIZE];
//	assignElements (c,a);
//	assignElements (a,b);
//	assignElements (b,c);
//}
//
////************************************************
////     Function to Display Array                 *
////************************************************
//void display (int a[])
//{
//	for(int i=0;i<SIZE;i++)
//		cout << a[i] << " ";
//	cout << endl;
//}
//
//int main()
//{
//	int A[10], B[10];
//
//	cout << "Enter Elements of A \n";
//	getValues (A);
//	cout << "Enter Elements of B \n";
//	getValues (B);
//
//	cout << "Contents of A befor Swaping:  ";
//	display (A);
//	cout << "Contents of B befor Swaping:  ";
//	display (B);
//	cout << endl << endl;
//
//	swap (A,B);
//	cout << "Contents of A after Swaping:  ";
//	display (A);
//	cout << "Contents of B after Swaping:  ";
//	display (B);
//
//	return 0;
//}