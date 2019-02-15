# include<iostream>
using namespace std;

class Circle
{
	// Data Members
	int x;
	int y;
	float radius;
	const double PI;

public:
	// x-coordinate setter
	void setX (int x){
		(x >= -50 && x <= 50) ? this->x = x : this->x = 0;
	}

	// y-coordinate setter
	void setY (int y){
		(y >= -50 && y <= 50) ? this->y = y : this->y = 0;
	}
	
	// Radius setter
	void setRadius (int radius){
		(radius >= 1 &&  radius <= 10) ? this->radius = radius : this->radius = 5;
	}

	// x-coordinate getter
	int getX () const{
		return x;
	}

	// y-coordinate getter
	int getY () const{
		return y;
	}

	// Radius getter
	float getRadius () const{
		return radius;
	}

	// PI getter
	const double getPI () const{
		return PI;
	}

	// Default Constructor
	Circle (): PI(3.14159){
		setX (0);
		setY (0);
		setRadius (5);
	}

	// Parameterised Constructor
	Circle (int x, int y, float radius) : PI(3.14159){
		setX (x);
		setY (y);
		setRadius (radius);
	}

	// Parameterised Constructor
	Circle (int x, int y) : PI(3.14159){
		setX (x);
		setY (y);
		setRadius (5);
	}

	// Parameterised Constructor
	Circle (int x, float radius) : PI(3.14159){
		setX (x);
		setY (0);
		setRadius (radius);
	}

	// Copy Constructor
	Circle (const Circle &obj) : PI (obj.getPI()){
		setX ( obj.getX () );
		setY ( obj.getY () );
		setRadius ( obj.getRadius () );
	}

	// Destructor
	~Circle (){
		cout<<"Destructor Executed..... \n";
	}

	// accepts Circle’s x, y coordinates and radius as arguments and assigns them to the appropriate member
	void setCircle (int x, int y, float radius){
		setX (x);
		setY (y);
		setRadius (radius);
	}

	// to initialize the data of a circle taken from the user
	void getCircle (){
		int x, y; float radius;
		cout << "Enter X- Coordinate: ";
		cin >> x;
		setX (x);

		cout << "Enter Y- Coordinate: ";
		cin >> y;
		setY (y);

		cout << "Enter Radius: ";
		cin >> radius;
		setRadius (radius);

	}

	// to display the information of a particular circle
	void putCircle () const{
		cout << "X-Coordinate: \t" << getX () << endl;
		cout << "Y-Coordinate: \t" << getY () << endl;
		cout << "Radius is: \t" << getRadius () << endl;
	}

	// calculate and return the area of a circle
	float getArea () const{
		return getPI () * getRadius () * getRadius ();
	}

	// calculate and return the diameter of a circle
	float getDiameter () const{
		return 2 * getRadius ();
	}

	// calculate and return the circumference of a circle
	float getCircumference () const{
		return 2 * getPI () * getRadius ();
	}

	// accepts two circle objects and return true if they are having same state, false otherwise
	bool isEqual (const Circle &obj) const{
		return ( this-> getX() == obj.getX() ) && ( this->getY() == obj.getY() ) && ( this->getRadius () == obj.getRadius() ) ? true : false;
	}

	// method accept an array of Circle objects and return the index of the array which
	// is equal to left hand side object, –1 otherwise.
	int findCircle (const Circle *p, int size) const{
		for (int i=0 ; i < size ; i++)
			if (isEqual (p[i])) 
				return i; 
		return -1;
	}

	// method accepts two circle objects and return their sum
	Circle add (const Circle & obj) const{
		return Circle (this->getX() + obj.getX() , this->getY() + obj.getY() , this->getRadius() + obj.getRadius());
	}

	// method accepts an array of Circle objects with its size and update the radius of all those objects to
   // the radius of left hand side object exist in the array having same x, y coordinates as of left hand side object.
	void updateObjects (Circle *p , int size){
		for (int i=0;i<size;i++)
			if (this-> getX() == p[i].getX() && this->getY() == p[i].getY())
				p[i].setRadius(this->getRadius());
	}

};

int main ()
{
	Circle cr (4,5,5);
	Circle  c[3]={Circle(0,0,9),Circle (4,5,15)};
	(c[0].add(c[1])).putCircle();
	c[0].updateObjects(c,3);

	for (int i=0;i<3;i++){
		cout<<"---------------\n";
		c[i].putCircle();
	}
	cout<<endl;
	c[0].isEqual(c[2]) ? c[0].putCircle() :c[2].putCircle();

	cout<<"Index is: "<< cr.findCircle (c,3) <<endl;

	system ("pause");
	return 0;

}