# include<iostream>
#include<string>
using namespace std;
class NumDays
{
	// Data Members
	double workhours;
	double days;
public:
	// SET HOURS
	void setWorkHours(double workhours) 
	{ 
		this->workhours = workhours;
		if (this->workhours >= 8)
			this->days = this->workhours / 8.0;
	}

	// SET DAYS
	void setDays(double days){ this->setWorkHours(days * 8); }

	// Get Hours
	double getHours() const { return workhours; }

	// GEt Num of Days
	double getNumofDays() const { return days; }


	// Constructor that accepts a number of hours
	NumDays(int workhours){ setWorkHours(workhours); }
	NumDays(){ setWorkHours(0); }

	// Copy Constructor
	NumDays(const NumDays &obj)
	{
		setWorkHours(obj.getHours());
		setDays(obj.getHours());
	}

	// Destructor
	~NumDays() {}

	// Addition operator (+)
	double operator + (const NumDays & obj) const
	{
		return this->getHours() + (this->getNumofDays() * 8) + (obj.getNumofDays() * 8) + obj.getHours();
	}

	// Subtraction operator (–)
	double operator - (const NumDays & obj) const
	{
		double hours;
		hours = this->getHours() + (this->getNumofDays() * 8) - (obj.getNumofDays() * 8) + obj.getHours();
		return hours < 0 ? hours*-1 : hours;
	}

	// Prefix increment operators (++)increment the number of hours stored in the object
	NumDays operator ++ ()
	{
		this->setWorkHours(this->getHours() + 1);
		return *this;
	}

	// PostFix increment operators (++)increment the number of hours stored in the object
	NumDays operator ++ (int )
	{
		NumDays temp(*this);
		this->setWorkHours(this->getHours() + 1);
		return temp;
	}

	// Prefix Decrement operator (--) decrement the number of hours
	NumDays operator -- ()
	{
		this->setWorkHours(this->getHours() - 1);
		return *this;
	}

	// Postfix Decrement operator (--) decrement the number of hours
	NumDays operator -- (int)
	{
		NumDays temp(*this);
		this->setWorkHours(this->getHours() - 1);
		return temp;
	}
};


// Class Timeoff
class TimeOff
{
	// Data Members
	string name;
	int id;
	NumDays maxSickDays;
	NumDays sickTaken;
	NumDays maxVacation;
	NumDays	vacTaken;
	NumDays maxUnpaid;
	NumDays	unpaidTaken;

public:

	// Default Constructor
	TimeOff()
	{
		this->name = "\0";
		this->id = 0;
	}

	// Parameterized Constructor
	TimeOff(double months,string name,int id, double sickTaken1, double vacTaken1, double maxUnpaid1, double unpaidTaken1)
	{
		this->name = name;
		this->id = id;
		maxSickDays.setWorkHours(months * 8);
		maxVacation.setWorkHours(months * 12);
		setSickTaken(sickTaken1);
		setVacTaken(vacTaken1);
		setMaxUnpaid(maxUnpaid1);
		setUnpaidTaken(unpaidTaken1);

	}


	// Parametrized Constructor
	TimeOff(string empName, int id, double maxSickDays1, double sickTaken1, double maxVacation1, double vacTaken1, double maxUnpaid1, double unpaidTaken1)
	{
		this->name = empName;
		this->id = id;
		this->maxSickDays.setDays(maxSickDays1);
		this->sickTaken.setDays(sickTaken1);
		setMaxVacation(maxVacation1);
		vacTaken.setDays(vacTaken1);
		maxUnpaid.setDays(maxUnpaid1);
		unpaidTaken.setDays(unpaidTaken1);
	}

	// Sets Name of Employee
	void setName(string name) { this->name = name; }

	// Name Getter
	string getName()const { return name; }

	// Set ID of Employee
	void setID(int id) { this->id = id; }

	// Id Getter
	int getID()const { return id; }

	// Sets MaxSickDays Employee may take
	void setMaxSickDays(double maxSickDays){ this->maxSickDays.setDays(maxSickDays); }

	// Sets SickDays taken by Employee
	void setSickTaken(double sickTaken){ this->sickTaken.setDays(sickTaken); }

	// Sets Max Vacation Employee may take
	void setMaxVacation(double maxVacation)
	{
		(maxVacation > 30) ? this->maxVacation.setDays(30) : this->maxVacation.setDays(maxVacation);
	}

	// Sets Vacation Taken By Employee
	void setVacTaken(double vacTaken){ this->vacTaken.setDays(vacTaken); }

	// Sets  Max unpaid vacation That Employee may take
	void setMaxUnpaid(double maxUnpaid){ this->maxUnpaid.setDays(maxUnpaid); }

	// sets max Unpaid Taken by Employee
	void setUnpaidTaken(double unpaidTaken){ this->unpaidTaken.setDays(unpaidTaken); }

	// Returns Numof MaxSick Leaves employee may take
	NumDays getMaxSickDays()const  { return maxSickDays; }

	// Returns Numof Sick Leaves employee have taken
	NumDays getSickTaken()const { return sickTaken; }

	// Returns Num of Max Vacation may take
	NumDays getMaxVacation()const { return maxVacation; }

	// Returns Num of Max Vacation employee have taken
	NumDays getVacTaken()const { return vacTaken; }

	// Returns Num of Max unpaid Vacation employee may take
	NumDays getMaxUnpaid()const { return maxUnpaid; }

	// Returns Num of unpaid Vacation employee may Take
	NumDays getUnpaidTaken()const { return unpaidTaken; }

	// Displys Information of an Employee
	void display()
	{
		cout << "Enployee Name: " << name;
		cout << " \t Employee ID: " << id << endl;
		cout << "Maximum number of days of sick leave the employee may take: " << maxSickDays.getNumofDays() << endl;
		cout << "Number of days of sick leave the employee has already taken: " << sickTaken.getNumofDays() << endl;
		cout << "Maximum number of days of paid vacation the employee may take: " << maxVacation.getNumofDays() << endl;
		cout << "Number of days of paid vacation the employee has already taken: " << vacTaken.getNumofDays() << endl;
		cout << "Maximum number of days of unpaid vacation the employee may taken: " << maxUnpaid.getNumofDays() << endl;
		cout << "The number of days of unpaid leave the employee has taken: " << unpaidTaken.getNumofDays() << endl;

	}
};


int main()
{
	TimeOff a("Abeel", 1208, 20, 8, 18, 25, 18, 5);
	a.display();
	cout << endl;
	cout << "----------------------------------"<<endl<<endl;
	TimeOff b;
	b.setName("Ahmed");
	b.setID(1209);
	b.setMaxSickDays(3);
	b.setSickTaken(2);
	b.setMaxUnpaid(2);
	b.setUnpaidTaken(2);
	b.setMaxVacation(32);
	b.setVacTaken(10);
	b.display();
	cout << endl;
	cout << "----------------------------------" << endl << endl;


	TimeOff emp(12,"XYZ",1280, 2, 15, 10, 7);
	emp.display();
	cout << endl;

	return 0;
}