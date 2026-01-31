#include <string>
#pragma once
#include "OnlineCourses.h"
class HealthandFitness : public OnlineCourses
{
protected:
	string equipment_needed;
	int calories_burned;
public:
	HealthandFitness(
		string eq, int cb,int id1, string name, string instrc, int numenrolled, int tcapacity, double rate, int duration,
		double cost, string lvl, double discount, string Prereqs) : OnlineCourses(id1,name, instrc, numenrolled, tcapacity, rate, duration,
			cost, lvl, discount, Prereqs)
	{
		equipment_needed = eq;
		calories_burned = cb;
	}

	

	bool checkcapacity()const override {		// capacity checking function
		if (numEnrolled == totalCapacity) {
			return false;
		}
		else
			return true;
	}


	void addstudent() override {	// student adding function

		if (checkcapacity() == true) {
			++numEnrolled;
			cout << "student succesfully added!" << endl;
		}
		else {
			cout << "capacity is full!" << endl;
		}
	};
	friend ostream& operator << (ostream& output, HealthandFitness& obj) {		// operator overloading

		output << " course name : " << obj.courseName << endl
			<< " equipment needed : " << obj.equipment_needed << endl
			<< " calories burned per session : " << obj.calories_burned<< endl
			<< " instructor : " << obj.instructor << endl
			<< " total capacity : " << obj.totalCapacity << endl
			<< " numEnrolled : " << obj.numEnrolled << endl
			<< " courseRate : " << obj.courseRate << endl
			<< " totalDuration : " << obj.totalDuration << endl
			<< " price : " << obj.price << "$" << endl
			<< " level : " << obj.level << endl
			<< " discountRate : " << obj.discountRate <<"%"<< endl
			<< " Prerequisites : " << obj.Prerequisites << endl;
		return output;
	}

};

