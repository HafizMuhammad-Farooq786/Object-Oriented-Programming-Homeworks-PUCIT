# include<iostream>
using namespace std;

class RationalNumber
{
	// Data Members
	int numerator;
	int denominator;

public:

	// Numerator Setter
	void setNumerator (int numerator)
	{
		this->numerator = numerator;
	}

	// Numerator Getter
	int getNumerator () const
	{
		return numerator;
	}

	// Denominator Setter
	void setDenominator (int denominator)
	{
		denominator != 0 ? this->denominator = denominator : this->denominator = 1;
	}

	// Denominator Getter
	int getDenominator () const
	{
		return denominator;
	}

	// Parameterised Constructor
	RationalNumber (int numerator, int denominator)
	{
		setNumerator (numerator);
		setDenominator (denominator);
	}

	// Parametrised Constructor wirh single parameter
	RationalNumber (int numerator)
	{
		setNumerator (numerator);
		setDenominator (1);
	}

	// Copy Constructor
	RationalNumber (const RationalNumber &obj)
	{
		this->setNumerator(obj.getNumerator());
		this->setDenominator(obj.getDenominator());
	}

	// Destructor
	~ RationalNumber () { }

	// method to write rational numbers in the form 2/3 or 37/51 on the screen
	void write () const
	{
		cout<<getNumerator ()<<"/"<<getDenominator ()<<" ";
	}

	// method to input rational numbers in the form 2/3 or 37/51 from the keyboard
	void read ()
	{
		int numerator, denominator;
		cout<<"Enter rational number: ";
		cin>>numerator;
		cout<<" / ";
		cin>>denominator;
		setNumerator (numerator);
		setDenominator (denominator);
	}

	// Overload plus (+) binary operator to perform the addition of two rational numbers
	RationalNumber operator + (const RationalNumber &obj) const
	{
		return RationalNumber (this-> getNumerator() * obj.getDenominator() + this-> getDenominator() * obj.getNumerator() , this-> getDenominator () * obj.getDenominator () );
	}

	// Overload minus (–) binary operator to perform the subtraction of two rational numbers
	RationalNumber operator - (const RationalNumber &obj) const
	{
		return RationalNumber (this-> getNumerator() * obj.getDenominator() - this-> getDenominator() * obj.getNumerator() , this-> getDenominator () * obj.getDenominator () );
	}

	// Overload multiply (*) binary operator to perform the multiplication of two rational numbers
	RationalNumber operator * (const RationalNumber &obj) const
	{
		return RationalNumber (this-> getNumerator() * obj.getNumerator () , this-> getDenominator () * obj.getDenominator () );
	}

	// Overload divide (/) binary operator to perform the division of two rational numbers
	RationalNumber operator / (const RationalNumber &obj) const
	{
		return RationalNumber (this-> getNumerator() * obj.getDenominator () , obj.getNumerator () * this-> getDenominator () );
	}

	// Overload less than (<) binary operator to perform the comparison of two rational numbers
	bool operator < (const RationalNumber &obj) const
	{
		return (this-> getNumerator() * obj.getDenominator () ) < ( obj.getNumerator () * this-> getDenominator ());
	}

	// Overload equal (==) binary operator to perform the comparison of two rational numbers
	bool operator == (const RationalNumber &obj) const
	{
		return (this-> getNumerator() * obj.getDenominator () ) == ( obj.getNumerator () * this-> getDenominator ());
	}

	// Overload minus (–) unary operator to convert a rational number into its negative form
	RationalNumber operator - ( )
	{
		if (!(*this))
			return *this;
		else
			return  RationalNumber (this-> numerator=-numerator, this->denominator);
			
	}

	// Overload logical not (!) unary operator to return true if the rational number is negative, false otherwise.
	bool operator ! () const
	{
		return (this->numerator == - this->numerator);
	}

	// simplify
	void simplify ()
	{
		int max;
		this->numerator > this->denominator ? max = this->numerator : max=this-> denominator;
		for (int i=max-1;i>=2;i--)
			if(this->numerator%i==0 && this->denominator%i==0)
			{
				setNumerator (this->numerator/i);
				setDenominator (this->denominator/i);
			}
	}

};

int main ()
{
	RationalNumber a(9,6),b(1,2);
	a.simplify ();
	cout<<"Addation is:  ";
	(a+b).write (); cout <<endl;
	cout<<"Subtraction is:  ";
	(a-b).write (); cout <<endl;
	cout<<"Multiplication is:  ";
	(a*b).write (); cout <<endl;
	cout<<"Division is:  ";
	(a/b).write (); cout <<endl;
					
	if(!a)  
		cout<<"number is negative \n";
	else
		cout<<"number is positive\n";
	// testing unuary - operator
	RationalNumber obj=-b;
	obj.write();
	b.write();
	
	system ("pause");
	return 0;
}