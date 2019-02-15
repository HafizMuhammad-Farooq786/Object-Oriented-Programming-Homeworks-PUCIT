# include <iostream> 
using namespace std;

class IntegerSet
{
	// Data Members
	const int SIZE;
	int *p;

public:
	// Constructor
	IntegerSet(int SIZE) : SIZE(SIZE)
	{
		p = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
			p[i] = 0;
	}

	// Copy Constructor
	IntegerSet(const IntegerSet &obj) : SIZE(obj.getSIZE())
	{
		this->p = new int[this->SIZE];
		for (int i = 0; i < this->SIZE; i++)
			this->p[i] = obj.p[i];
	}

	// Destructor
	~IntegerSet() { (this->SIZE == 1) ? delete p : delete[]p; }

	// REturns SIze of an Object
	int getSIZE() const { return SIZE; }

	// insertElement that inserts a new integer k (passed as argument) into a set by setting p[ k ] to 1.
	void insertElement(int k) { p[k] = 1; }

	// deleteElement that deletes an integer k (passed as argument) by setting p[ k ] to 0.
	void deleteElement(int k) { p[k] = 0; }

	// findElement that searches an integer key(passed as argument) in a set and return true if the key exists in the set, false otherwise.
	bool findElement(int key) const
	{
		for (int i = 0; i < this->SIZE; i++)
		if (p[key] == 1)
			return true;
		return false;
	}

	// isNullSet returns true if the set is an “empty-set” (a set whose array representation contains all zeroes), false otherwise.
	bool isNullSet() const
	{
		for (int i = 0; i < SIZE;i++)
		if (findElement(i))
			return false;
		return true;
	}

	// unionOfSets that creates a third set that is the set-theoretic union of two existing sets
	IntegerSet unionofSets(const IntegerSet & obj) const
	{
		if (this->SIZE == obj.SIZE)
		{
			IntegerSet temp(this->SIZE);
			for (int i = 0; i < this->SIZE; i++)
			{
				if (this->p[i] == 1 || obj.p[i] == 1)
					temp.p[i] = 1;
				else if (this->p[i] == obj.p[i] == 0)
					temp.p[i] = 0;
			}
			return temp;
		}
		exit(0);
	}

	// intersectionOfSets which creates a third set which is the set-theoretic intersection of two existing sets
	IntegerSet intersectionOfSets(const IntegerSet &obj) const
	{
		if (this->SIZE==obj.SIZE)
		{
			IntegerSet temp(this->SIZE);
			for (int i = 0; i < this->SIZE; i++)
			{
				if (this->p[i] == 1 && obj.p[i] == 1)
					temp.p[i] = 1;
				else if (this->p[i] == 0 || obj.p[i] == 0)
					temp.p[i] = 0;
			}
			return temp;
		}
		exit(0);
	}

	// Equal (==) that determines whether two sets are equal or not.The operator returns true if both the sets are equal, false otherwise.
	bool operator == (const IntegerSet & obj) const
	{
		if (this->SIZE == obj.SIZE)
		{
			for (int i = 0; i < SIZE; i++)
			if (this->p[i] != obj.p[i])
				return false;
		}
		else
			return false;
		return true;
	}

	// Logical NOT (!) create and return a new set which contains the reverse of left hand side object,
	// i.e. all the 1s exist in the set converted to 0s and vice versa.
	IntegerSet operator ! ()  const
	{
		IntegerSet temp(this->SIZE);
		for (int i = 0; i < temp.SIZE;i++)
		if (this->p[i] == 1)
			temp.p[i] = 0;
		else
			temp.p[i] = 1;

		return temp;
	}

	// Assignment (=) which copies the data of one object to another. 
	// The copy is done if both the objects have same sizes.
	IntegerSet operator = (const IntegerSet & obj) 
	{
		if (this == &obj)
			return *this;
		if (this->SIZE == obj.SIZE)
		{
			for (int i = 0; i < this->SIZE; i++)
				this->p[i] = obj.p[i];
			return *this;
		}
		else
			return *this;
	}

	 friend ostream & operator << (ostream & , const IntegerSet & );
};

// Stream insertion (<<) prints a set as a list of numbers separated by spaces. Print only those elements that 
// are present in the set (i.e., their position in the array has a value of 1). Print --- for an empty set.
ostream & operator << (ostream & out, const IntegerSet & obj)
{
	for (int i = 0; i < obj.getSIZE(); i++)
	if (obj.p[i] == 1)
		out << i << " ";
	else
		out << "-- ";
	return out;
}

int main ()
{
	IntegerSet a(5),b(5),c(6);
	for (int i = 0; i < 5; i++)
		a.insertElement(i);
	a.deleteElement(2);
	for (int i = 0; i < 5; i++)
		b.insertElement(i);
	b.deleteElement(4);

	cout << "SET A: " << a << endl;
	cout << "SET B: " << b << endl;
	cout << "SET C: " << c << endl;
	cout << endl;

	if (a == b)
		cout << "SETS ARE EQUAL\n";
	else
		cout << "SETS ARE NOT EQUAL \n";

	if (c.isNullSet())
		cout << "SET C IS NULL SET \n";
	else
		cout << "NOT EMPTY \n";
	cout << endl;

	cout << "REVERSE OF SET A:  " << !a << endl;
	cout << "REVERSE OF SET B:  " << !b << endl;

	cout << endl;

	cout << "UNION OF SETS A & B IS:    " << a.unionofSets(b) << endl;
	cout << "INTERSECTION OF SETS  A & B IS:    " << a.intersectionOfSets(b) << endl << endl;
	system ("pause");
	return 0;
}