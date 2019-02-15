# include<iostream>
using namespace std;

template <class t>
class Collection
{
	// Data Members
	t *data;
	int SIZE;

public:
	// Default Constructor
	Collection()
	{
		this->SIZE = 5;
		data = new t[SIZE];
		for (int i = 0; i < this->SIZE; i++)
			data[i] = 0;
	}

	// Constructor which accepts an integer as argument
	Collection(int size)
	{
		this->setSize(size);
		data = new t[SIZE];
		for (int i = 0; i < this->SIZE; i++)
			data[i] = 0;
	}

	// Copy Constructor
	Collection(const Collection&obj)
	{
		this->SIZE = obj.getSize();
		data = new t[SIZE];
		for (int i = 0; i < this->SIZE; i++)
			data[i] = obj.data[i];;
	}

	// Destructor 
	~Collection()
	{
		this->SIZE == 1 ? delete data : delete[]data;
	}

	// SIZE Getter
	int getSize()const  { return SIZE; }

	// SIZE SETTER
	void setSize(int size) { size < 1 ? this->SIZE = 5 : this->SIZE = size; }

	// insertElement that inserts a new element at index i(both passed as argument)
	void setElement(t key, int index)
	{
		if (index >= 0 && index < this->SIZE)
			data[index] = key;
		else
			cout << "OUT OF BOUND \n";
	}

	// findElement accepts a  key as argument and return true
	bool findElement(t key) const
	{
		for (int i = 0; i < this->SIZE; i++)
		if (this->data[i] == key)
			return true;
		return false;
	}

	// countElement accepts an element key as argument and count and return the total occurrences of it in a collection -1 otherwise
	int countElement(t key) const
	{
		if (findElement(key))
		{
			int count = 0;
			for (int i = 0; i < this->SIZE; i++)
			if (this->data[i] == key)
				count++;
			return count;
		}
		else
			return -1;
	}

	// Assignment (=) which copies the data of one object to another.
	Collection operator = (const Collection & obj)
	{
		if (this != &obj)
		{
			if (this->SIZE == obj.getSize())
			{
				for (int i = 0; i < this->SIZE; i++)
					this->data[i] = obj.data[i];
			}
			else
			{
				delete[]data;
				this->SIZE = new t[obj.getSize()];
				for (int i = 0; i < this->SIZE; i++)
					this->data[i] = obj.data[i];
			}
		}
		return *this;
	}

	// Arithmetic assignment (+) binary which perform the addition of two collections (left hand side and right hand side) if
	//possible and return the result.
	Collection operator + (const Collection &obj) const
	{
		if (this->SIZE == obj.getSize())
		{
			Collection temp(this->SIZE);
			for (int i = 0; i < this->SIZE; i++)
				temp.data[i] = this->data[i] + obj.data[i];
			return temp;
		}
		else
			cout << "ADDation not Possble......\n";
			exit(0);
	}

	// Comparison (==) that determines whether two collections are equal or not.
	bool operator == (const Collection &obj) const
	{
		if (this->SIZE != obj.getSize())
			return false;
		else
		{
			for (int i = 0; i < this->SIZE; i++)
			if (this->data[i] != obj.data[i])
				return false;
			return true;
		}	
	}

	// Subscript ([]) for rvalue & lValue of const objects
	t operator [] (int index) const
	{
		if (index >= 0 && index <= this->SIZE - 1)
			return this->data[index];
		cout << "INDEX OUT OF BOUND...\n";
		exit(0);
	}

	// Subscript ([]) for both lvalue for non const Objects
	t & operator[] (int index)
	{
		if (index >= 0 && index <= this->SIZE - 1)
			return data[index];
		cout << "INDEX OUT OF BOUND...\n";
		exit(0);
	}

	// Unary minus(-) return true if all the elements of a collection are non - zeroes
	bool operator - () const
	{
		for (int i = 0; i < this->SIZE; i++)
		if (this->data[i] == 0)
			return false;
		return true;
	}

	// Unary Not (!) assigns zero to all the elements of the object
	Collection operator !()
	{
		for (int i = 0; i < this->SIZE; i++)
			data[i] = 0;
		return *this;
	}

	// Function (()) receives two parameters as argument start_index and end_index and return the new sub collection
	Collection operator () (int start_index, int end_index)
	{
		if (start_index >= 0 && end_index <= this->SIZE - 1)
		{
			Collection temp(end_index - start_index + 1);
			for (int i = start_index; i <= end_index; i++)
				temp.data[i] = this->data[i];
			return temp;
		}
		else
			cout << "OUT OF BOUND......";
		exit(0);
	}

	template <class t>
	friend ostream & operator<< (ostream &, const Collection <t> &);
	template <class t>
	friend istream & operator>> (istream &, Collection <t> &);
};

// overloaded stream insertion operator
template <class t>
ostream & operator<< (ostream &out, const Collection <t> & obj)
{
	for (int i = 0; i < obj.getSize(); i++)
		out << obj.data[i]<<"  ";
	out << endl;
	return out;
}

// overloaded stream extraction operator
template <class t>
istream & operator>> (istream & in, Collection<t> &obj)
{
	for (int i = 0; i < obj.getSize(); i++)
		in >> obj.data[i];
	return in;
}

int main()
{
	Collection <int> o1(6), o2(6);
	Collection <float> o3, o4;
	Collection <char> o5, o6;

	for (int i = 0; i < 5; i++)
	{
		o1.setElement(i + 1, i);
		o3.setElement(i + 1.1f, i);
		o5.setElement(i + 2, i);
	}

	cout << "Testing for INTEGERS\n";
	cout << "Int Collection 1 : " << o1;
	cout << "Int Collection 2 : " << o2;
	cout << "1 has Occured in Collection: " << o1.countElement(1) << endl;
	cout << "Sum of two Int Collections: " << o1 + o2;
	cout << "Sub Collection of INTEGERS: " << o1(0, 3);
	cout << " \t -------------------------------\n";

	cout << "Testing for FLOATS\n";
	cout << "float Collection 1 : " << o3;
	cout << "float Collection 2 : " << o4;
	cout << "Sum of two float Collections: " << o3 + o4;
	cout << "Sub Collection of FLOATS: " << o3(0, 2);
	cout << " \t -------------------------------\n";

	cout << "Testing for CHAR \n";
	cout << "CHAR Collection 1 : " << o5;
	cout << "CHAR Collection 2 : " << o6;
	cout << "Sum of two char Collections: " << o5 + o6;
	cout << "Sub Collection of char: " << o5(0, 1);
	cout << " \t -------------------------------\n";

	system("pause");
	return 0;
}