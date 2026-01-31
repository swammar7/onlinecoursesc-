#include <string>
#pragma once
#include "OnlineCourses.h"
class SoftwareCourses : public OnlineCourses {
protected:

	string programinglanguage;
	string developmentenviorment;

public:

	SoftwareCourses(
		string langname ,string dve,int id1,string name, string instrc, int numenrolled ,int tcapacity, double rate, int duration,
		double cost, string lvl, double discount, string Prereqs) : OnlineCourses(id1,name, instrc, numenrolled ,tcapacity, rate, duration,
			cost, lvl, discount, Prereqs) {

		programinglanguage = langname;
		developmentenviorment = dve;
	};


	void addstudent() override {		// student adding function

		if (checkcapacity() == true) {
			++numEnrolled;
			cout << "student succesfully added!" << endl;
		}
		else {
			cout << "capacity is full!" << endl;
		}
	}

	bool checkcapacity()const override {		// capacity checking function
		if (numEnrolled == totalCapacity) {
			return false;
		}
		else
			return true;
	}

	friend ostream& operator << (ostream& output, SoftwareCourses& obj) {		// operator overloading

		output << " course name : " << obj.courseName << endl
			<< " programing language : " << obj.programinglanguage << endl
			<< " developmentenviorment : " << obj.developmentenviorment << endl
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



};