#include<iostream>
#include<string>
using namespace std;

//********************************************
//              ADT: Package                 *
//********************************************
class Package
{
	// Data members
	string sender_Name, receiver_Name;
	string sender_Address, receiver_Address;
	string sender_City, receiver_City;
	float weight, costPerOunce;
public:
	// Sets Cost
	void setCostPerOunce(float c) { c < 0 ? this->costPerOunce = 0 : this->costPerOunce = c; }

	// Returns Cost PerOunce
	float getCostPerOunce()const { return costPerOunce; }

	// Sets Weight
	void setWeight(float w) { w < 0 ? this->weight = 0 : this->weight = w; }

	// Returns Weight
	float getWeight()const { return weight; }

	// Sets Sender Name
	void setSenderName(string s) { this->sender_Name = s; }

	// Returns Sender Name
	string getSenderName()const { return sender_Name; }

	// Sets Reciever Name
	void setRecieverName(string s) { this->receiver_Name = s; }

	// Returns Reciever Name
	string getRecieverName()const { return receiver_Name; }

	// Sets Sender Address
	void setSenderAddress(string s) { this->sender_Address = s; }

	// Returns Sender Address
	string getSenderAddress()const { return sender_Address; }

	// Sets Reciever Address
	void setRecieverAddress(string s) { this->receiver_Address = s; }

	// Returns Reciever Address
	string getRecieverAddress()const { return receiver_Address; }

	// Sets Sender City
	void setSenderCity(string s) { this->sender_City = s; }

	// Returns Sender City
	string getSenderCity()const { return sender_City; }

	// Sets Reciever City
	void setRecieverCity(string s) { this->receiver_City = s; }

	// Returns Reciever City
	string getRecieverCity()const { return receiver_City; }

	// returns the cost associated with shipping the package
	float calculateCost()const { return costPerOunce*weight; }

	// Constructor
	Package(string s_name, string s_address, string s_city, string r_name, string r_address, string r_city, float w, float cost)
	{
		setSenderName(s_name);
		setSenderAddress(s_address);
		setSenderCity(s_city);
		setRecieverName(r_name);
		setRecieverAddress(r_address);
		setRecieverCity(r_city);
		setWeight(w);
		setCostPerOunce(cost);
	}

	// Destructor
	~Package(){}

}; // End of Class Package

//*****************************************************
//               ADT: TwoDayPackage                   *
//*****************************************************
class TwoDayPackage :public Package
{
	// Data Member
	float flatFee;
public:
	// Sets Flat fee
	void setFlatFee(float fee) { fee < 0 ? flatFee = 0 : flatFee = fee; }

	// Returns Flat Fee
	float getFlatFee()const { return flatFee; }

	// Constructor
	TwoDayPackage(string s_name, string s_address, string s_city, string r_name, string r_address, string r_city, float w, float cost,float fee) :Package(s_name, s_address, s_city,r_name,r_address, r_city, w, cost)
	{
		this->flatFee = fee;
	}

	// computes and return the shipping cost by adding the flat fee to
	float calculateCost()const{ return Package::calculateCost() + this->flatFee; }

	// Destructor
	~TwoDayPackage() {}
}; // End of Class Two Day Package

//*********************************************
//           ADT: OvernightPackage            *
//*********************************************
class OvernightPackage:public Package
{
	// Data Member
	float feePerOunce;
public:
	// Sets Flat fee
	void setFeePerOunce(float fee) { fee < 0 ? feePerOunce = 0 : feePerOunce = fee; }

	// Returns Flat Fee
	float getFlatFee()const { return feePerOunce; }

	// Constructor
	OvernightPackage(string s_name, string s_address, string s_city, string r_name, string r_address, string r_city, float w, float cost, float fee) :Package(s_name, s_address, s_city, r_name, r_address, r_city, w, cost)
	{
		setFeePerOunce(fee);
	}

	// computes and return the shipping cost by adding the flat fee to
	float calculateCost()const{ return Package::calculateCost() + this->feePerOunce*Package::getWeight(); }

	// Destructor
	~OvernightPackage(){}
};

int main()
{
	cout << "Simple Package\n";
	Package p1("Abeel", " Jallo more Batapur", "Lahore", "Ahmed", "Mansoora", "Lahore", 2, 100);
	cout << p1.calculateCost() << endl;
	cout << "----------------------------------------\n";

	cout << "Two DAy Package\n";
	TwoDayPackage p2("Abeel", " Jallo more Batapur", "Lahore", "Ahmed", "Mansoora", "Lahore", 2, 100,300);
	cout << p2.calculateCost() << endl;
	cout << "----------------------------------------\n";

	cout << "Overnight Package\n";
	OvernightPackage p3("Abeel", " Jallo more Batapur", "Lahore", "Ahmed", "Mansoora", "Lahore", 2, 100, 100);
	cout << p3.calculateCost() << endl;
	cout << "----------------------------------------\n";
	system("pause");
	return 0;
}