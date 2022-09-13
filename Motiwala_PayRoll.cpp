// Name: Muhammed Motiwala
// Assignment: lab 7
// calculating payroll


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class payRoll
{
	private:
		double numHours;
		double payRate;
	public:
		payRoll();
		payRoll(double, double);
		void setHours(double);
		void setPayRate(double);
		double getHours();
		double getPayRate();
		double getGross();
		
};

payRoll::payRoll()
{
	numHours = 0.0;
	payRate = 0.0;
	
}
payRoll::payRoll(double hours, double rate)
{
	payRate = rate;
	numHours = hours;
}
//set hours
void payRoll::setHours(double hours)
{
	numHours = hours;
}
//set rate
void payRoll::setPayRate(double rate)
{
	payRate = rate;
}
//get hours to test
double payRoll::getHours()
{
	return numHours;
}
//get rate to test
double payRoll::getPayRate()
{ 
	return payRate;
}
//get gross
double payRoll::getGross()
{
	return ( numHours * payRate);
}


int main()
{
	
	const int NUMEMPLOYEE = 7;
	payRoll employee[NUMEMPLOYEE];
	double empHours;
	double empRate;
	
	double grossPay;
	
	//double newHours; used to test getHours(), 
	
	ifstream dataFile;
	
	
	 
	dataFile.open("payroll.txt");
	if(!dataFile)
		cout <<"ERROR";
	
	else
	{
		for (int i = 0; i < NUMEMPLOYEE; i++)
		{

			dataFile >> empHours;
			dataFile >> empRate;
			employee[i].setHours(empHours);
			employee[i].setPayRate(empRate);
		}
		dataFile.close();
	}
		
		
	
	

	cout << "Employee\t Gross Pay\n";
	cout << "--------\t ---------\n";
	
	for (int i = 0; i < NUMEMPLOYEE; i++)
	{
		grossPay = employee[i].getGross();

		cout << i+1 << ":\t\t$ " << setprecision(2) << fixed << grossPay << "\n"; 
		
	}
	
	
}
