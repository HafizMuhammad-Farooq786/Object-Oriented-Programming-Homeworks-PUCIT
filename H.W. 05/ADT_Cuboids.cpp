# include <iostream>
# include <cmath>
using namespace std;

class Cuboids
{
	// Data Members
	float height;
	float width;
	float depth;

public:
	// Hieght Setter
	void setHeight (float h)
	{
		(h>0.0 && h<35.0) ? height = h : height = 1;
	}
	
	// Height getter
	float getHeight ()
	{
		return height;
	}

	// Width Setter
	void setWidth (float w)
	{
		(w>0.0 && w<35.0) ? width = w : width = 1;
	}

	// Width Getter
	float getWidth ()
	{
		return width;
	}

	// Depth Setter
	void setDepth (float d)
	{
		(d>0.0 && d<35.0) ? depth = d : depth = 1;
	}

	// Depth Getter
	float getDepth ()
	{
		return depth;
	}

	// Perameterised Constructor accepts cuboids, height, width and depth as arguments
	Cuboids (float h, float w, float d)
	{
		setHeight (h);
		setWidth (w);
		setDepth (d);
	}

	// default Constructor 
	Cuboids ()
	{
		setHeight (1);
		setWidth (1);
		setDepth (1);
	}

	// perametrised Constructor accepts cuboids’ height and width as arguments
	Cuboids (float h, float w)
	{
		setHeight (h);
		setWidth (w);
		setDepth (1);
	}

	// Copy Constructor
	Cuboids (const Cuboids &obj)
	{
		setHeight (obj.height);
		setWidth (obj.width);
		setDepth (obj.depth);
	}

	// Destructor
	~Cuboids ()
	{
		cout << "Destructor Executed.... \n";
	}

	// SET INFo Function sets data to data members
	void setCuboids (float h, float w, float d)
	{
		setHeight (h);
		setWidth (w);
		setDepth (d);

	}

	// GetInfo Function takes input from user
	void getCuboids ()
	{
		float h, w ,d;

		cout << "Enter Hieght: ";
		cin >> h;
		setHeight (h);

		cout << "Enter Width: ";
		cin >> w;
		setWidth (w);

		cout << "Enter Depth: ";
		cin >> d;
		setDepth (d);

	}

	// display the information of a particular cuboids
	void putCuboids ()
	{
		cout << "Hieght: " << getHeight () <<endl;
		cout << "Width: " << getWidth () <<endl;
		cout << "Depth: " << getDepth () <<endl;
	}

	// provide the facility to calculate the surface area of a cuboids
	float getSurfaceArea ()
	{
		return 2* ( (getHeight () * getWidth () ) + (getHeight () * getDepth () ) + (getWidth () * getDepth () ) );
	}

	// provide the facility to calculate the volume of a cuboids
	float getVolume ()
	{
		return getHeight () * getWidth () * getDepth ();
	}

	// provide the facility to calculate the space diagonal of a cuboids
	float getSpaceDiagonal ()
	{
		return  sqrt( (pow (getHeight (),2)) + (pow (getWidth (),2)) + (pow (getDepth (),2)) );
	}

	// display all the dimensions, surface area, volume and space diagonal of a cuboids
	void putCuboidsInfo ()
	{
		putCuboids ();
		cout << "Surface Area is:  " << getSurfaceArea () << endl;
		cout << "Volume is:  " << getVolume () << endl;
		cout << "Space Diagnol is:  " << getSpaceDiagonal () <<endl;
	}

};


int main ()
{
	Cuboids c (1.2, 3.4, -7);
	c.putCuboidsInfo ();
	cout << endl;

	Cuboids c2;
	c2.putCuboidsInfo ();
	cout << endl;

	Cuboids c3(c2);
	c3.putCuboidsInfo ();
	cout << endl;

	Cuboids c4;
	c4.getCuboids ();
	c4.putCuboidsInfo ();

	system ("pause");
	return 0;
}