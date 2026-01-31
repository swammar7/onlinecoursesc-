#include <string>
#include <iostream>
using namespace std;
#pragma once
class OnlineCourses
{

protected:
	int id;
	string courseName;
	string instructor;
	int totalCapacity = 0;
	int numEnrolled = 0;
	double courseRate;
	int totalDuration;     
	double price;
	string level;          
	double discountRate;   
	string Prerequisites;  
	int ratingCount = 0;

public:

	OnlineCourses(int id1, string name, string instrc, int numenrolled, int tcapacity, double rate, int duration,
		double cost, string lvl, double discount, string Prereqs)
	{
		id = id1;
		courseName = name;
		instructor = instrc;
		numEnrolled = numenrolled;
		totalCapacity = tcapacity;
		courseRate = rate;
		totalDuration = duration;
		price = cost;
		level = lvl;
		discountRate = discount;
		Prerequisites = Prereqs;
		
	}
	string getcoursename() { return courseName; }		// accessor functions
	double getdiscountr() { return discountRate; }
	double getprice() { return price; }
	string getCN() { return courseName; }
	int getid() { return id; }


	friend ostream& operator<< (ostream& output, OnlineCourses& obj) {		// operator overloading

		output << " course name : " << obj.courseName << endl
			<< " instructor : " << obj.instructor << endl
			<< " total capacity : " << obj.totalCapacity << endl
			<< " numEnrolled : " << obj.numEnrolled << endl
			<< " courseRate : " << obj.courseRate << endl
			<< " totalDuration : " << obj.totalDuration << endl
			<< " price : " << obj.price <<"$"<< endl
			<< " level : " << obj.level << endl
			<< " discountRate : " << obj.discountRate << "%" << endl
			<< " Prerequisites : " << obj.Prerequisites << endl;
		return output; 
	}
	

	virtual void addstudent() = 0;			// virtual functions

	virtual bool checkcapacity() const = 0;

	void addrating(double newrating) { // rating adding function	//mutator function

		if (newrating < 1 || newrating>5) {
			cout << "rating should be between 1 and 5 " << endl;
			return;
		}
		else {
			courseRate = (((courseRate * ratingCount) + newrating) / (ratingCount + 1));
			ratingCount++;
		}
	}


};

