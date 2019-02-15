#include <iostream>
#include <string>
using namespace std;

class Employee
{
	// data members
	int id;
	string name;
	string department;
	string position;

public:

	// default Constructor
	Employee ()
	{
		setID (0);
		setName ("");
		setDepartment ("");
		setPosition ("");
	}

	// parameterised Construcor overloaded(all data members)
	Employee (string NAME, int ID, string DEPT, string POS)
	{
		setID (ID);
		setName (NAME);
		setDepartment (DEPT);
		setPosition (POS);
	}

	// parameterised Construcor overloaded(name, ID)
	Employee (string NAME, int ID)
	{
		setID (ID);
		setName (NAME);
		setDepartment ("");
		setPosition ("");
	}

	// Copy Constructor
	Employee (Employee &obj)
	{
		setID (obj.id);
		setName (obj.name);
		setDepartment (obj.department);
		setPosition (obj.position);
	}

	// Destructor
	~ Employee ()
	{
		cout << "Destructor Executed..." << endl;
	}

	// ID getter
	int getID ()
	{
		return id;
	}

	// ID setter
	void setID (int ID)
	{
		id = ID;
	}

	// Name getter
	string getName ()
	{
		return name;
	}

	// Name setter
	void setName (string Name)
	{
		name = Name;
	}

	// Department getter
	string getDepartment ()
	{
		return department;
	}

	// Department setter
	void setDepartment (string DEPT)
	{
		department = DEPT;
	}

	// Position Getter
	string getPosition ()
	{
		return position;
	}

	// Position Setter
	void setPosition (string POS)
	{
		position = POS;
	}

	// SET INFo Function sets data to data members
	void setInfo (string NAME, int ID,string DEPT, string POS)
	{
		setID (ID);
		setName (NAME);
		setDepartment (DEPT);
		setPosition (POS);
	}

	// GetInfo Function takes input from user
	void getInfo ()
	{
		string NAME;string DEPT;string POS;
		int ID;

		
		cout << "Enter ID: ";
		cin >> ID;
		setID (ID);	
		cin.ignore ();

		cout << "Enter Name: ";
		getline (cin,NAME);
		setName (NAME);
		cin.ignore ();

		cout<<"Enter Department:";
		getline (cin,DEPT);
		setDepartment (DEPT);
		cin.ignore ();

		cout << "Enter position: ";
		getline (cin,POS);
		setPosition (POS);
		cin.ignore ();


	}

	// Prints data for an employee
	void putInfo ()
	{
		cout << "\t" << getName() << "\t" << getID() << "\t" << getDepartment() << "\t" << getPosition() << endl;
	}

};


int main ()
{
	Employee emp [4];

	int id [4] = {1230, 1231, 1241, 1242};
	string name [4] = {"Ejaz Ashraf" , "Muhammad Farooq" , "Madiha Khalid" , "Arifa Mirza"};
	string depertment [4] = {"PUCIT-Old Campuse","PUCIT-Old Campuse","PUCIT-New Campuse","PUCIT-New Campuse"};
	string position [4] = {"Assistant Professor" , "Lecturer" , "Lecturer" , "Lecturer"};

	cout << "\tNAME \t\t ID \tDEPARTMENT \t\tPOSITION "<< endl;
	cout << "\t--------------------------------------------------------\n";

	for (int i=0; i<4 ;i++)
	{
		emp[i].setInfo (name[i], id[i], depertment[i], position[i]);
		emp[i].putInfo ();
	}

	Employee e;
	e.getInfo ();
	e.putInfo ();

	system ("pause");
	return 0;
}