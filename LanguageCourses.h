#include <string>
#pragma once
#include "OnlineCourses.h"
class LanguageCourses : public OnlineCourses
{
protected:

	string language;
	bool nativeinstructor;

public:
		
	LanguageCourses(
		bool nativeinstructor1, string thelang,int id1,string name, string instrc, int numenrolled, int tcapacity, double rate, int duration,
		double cost, string lvl, double discount, string Prereqs) : OnlineCourses(id1,name, instrc, numenrolled, tcapacity, rate, duration,
			cost, lvl, discount, Prereqs) {
		nativeinstructor = nativeinstructor1;
		language = thelang;
	};

	

	
	void addstudent() override {		// student adding function

		if (checkcapacity() == true) {
			++numEnrolled;
			cout << "student succesfully added!" << endl;
		}
		else {
			cout << "capacity is full!" << endl;
		}
	};

	bool checkcapacity()const override {		// capacity checking function
		if (numEnrolled == totalCapacity) {
			return false;
		}
		else
			return true;
	}
 

	 bool getnative() {

		if (nativeinstructor == true) {
			cout << "the instructor is a native speaker" << endl;
			return true;
		}
		else
			cout << "the instructor is not a native speaker" << endl;
		return false;
	}

	 friend ostream& operator << (ostream& output, LanguageCourses& obj) {		// operator overloading

		 output << " course name : " << obj.courseName << endl
			 << " language : " << obj.language << endl
		     << " native instructor : " << obj.getnative() << endl
			 << " instructor : " << obj.instructor << endl
			 << " total capacity : " << obj.totalCapacity << endl
			 << " numEnrolled : " << obj.numEnrolled << endl
			 << " courseRate : " << obj.courseRate << endl
			 << " totalDuration : " << obj.totalDuration << endl
			 << " price : " << obj.price << "$" << endl
			 << " level : " << obj.level << endl
			 << " discountRate : " << obj.discountRate << "%" << endl
			 << " Prerequisites : " << obj.Prerequisites << endl;
		 return output;
	 }

};

