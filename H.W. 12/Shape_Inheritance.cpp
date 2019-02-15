#include<iostream>
using namespace std;

//*************************************
//       ADT: BASICSHAPE              *
//*************************************
class BasicShape
{
	// Data Members
	double area;
public:
	// Default Constructor
	BasicShape() { }

	// Copy Constructor
	BasicShape(const BasicShape & obj) { this->setArea(obj.getArea()); }

	// Destructor
	virtual~BasicShape() { }

	// Returns Area
	double getArea()const { return area; }

	// Sets Area
	void setArea(double Area) { Area < 0 ? this->area = 0 : this->area = Area; }

	// virtual function that display a message “Basic Shape Calculate Area Function…”.
	virtual void calcArea()const { cout << "Basic Shape Calculate Area Function...\n"; }
};

//*************************************
//          ADT: CIRCLE               *
//*************************************
class Circle :public BasicShape
{
	// Data Members
	long int centerX, centerY;
	double radius;
public:
	// Default Constructor
	Circle()
	{
		this->centerX = this->centerY = 0; this->radius = 0;
		this->calcArea();
	}

	// Parameterized Constructor
	Circle(long int X, long int Y, double radius)
	{
		this->setX_Axis(X);
		this->setY_Axis(Y);
		this->setRadius(radius);
		this->calcArea();
	}

	// Copy Constructor
	Circle(const Circle &obj) :BasicShape(obj)
	{
		this->setX_Axis(obj.getX_Axis());
		this->setY_Axis(obj.getY_Axis());
		this->setRadius(obj.getRadius());
	}

	// Destructor
	virtual ~Circle() {}

	// Sets Value OF X-axis
	void setX_Axis(long int X){ this->centerX = X; }

	// Sets Value of Y-axis
	void setY_Axis(long int Y){ this->centerY = Y; }

	// Sets Radius
	void setRadius(double R){ R < 0 ? this->radius = 0 : this->radius = R; }

	// returns X-Axis
	long int getX_Axis()const { return centerX; }

	// Returns Y-Axis
	long int getY_Axis()const { return centerY; }

	// Returns Radius 
	double getRadius()const { return radius; }

	// Calculates Area And stores
	virtual void calcArea(){ this->setArea(3.14159 * radius * radius); }
};

//*************************************
//          ADT: RECTANGLE            *
//*************************************
class Rectangle:public BasicShape
{
	// Data Members
	long int length, width;
public:
	// Default Constructor
	Rectangle()
	{
		this->length = this->width = 1;
		this->calcArea();
	}

	// Parameterized
	Rectangle(long int length, long int width)
	{
		this->setLength(length);
		this->setWidth(width);
		this->calcArea();
	}

	// Copy Constructor
	Rectangle(const Rectangle &obj) :BasicShape(obj)
	{
		this->setLength(length);
		this->setWidth(width);
	}

	// destructor
	virtual ~Rectangle() {}

	// Sets Length of Rectangle
	void setLength(long int l){ l <= 0 ? this->length = 1 : length = l; }

	// Sets Width of Rectangle
	void setWidth(long int w){ w <= 0 ? this->width = 1 : width= w; }

	// Retuens Length
	long int getLength()const{ return length; }

	// Returns Rectangle Width
	long int getWidth()const { return width; }

	// Function Calculates Area OF Rectangle
	virtual void calcArea() { this->setArea((double)length*width); }
};

int main()
{
	BasicShape *shape;
	shape = new Circle[5];
	for (int i = 0; i < 5; i++)
	{
		shape[i] = Circle(1, 2, i + 2);
		cout << "Area OF CIRCLE " << i + 1 << ": " << shape[i].getArea() << endl;
	}
	delete[]shape;
	cout << "-----------------------------\n";

	BasicShape *rec;
	rec= new Rectangle[5];
	for (int i = 0; i < 5; i++)
	{
		rec[i] = Rectangle(i + 1, i + 2);
		cout << "Area OF Rectangle " << i + 1 << ": " << rec[i].getArea() << endl;
	}
	delete[]rec;


	system("pause");
	return 0;
}