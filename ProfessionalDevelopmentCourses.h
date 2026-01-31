#pragma once
#include <string>
#include "OnlineCourses.h"
class ProfessionalDevelopmentCourses : public OnlineCourses
{
protected:

	string pcoursename;
	bool certification ;
public:

	ProfessionalDevelopmentCourses(
		bool certification1,string pcoursename1,int id1,string name, string instrc, int numenrolled, int tcapacity, double rate, int duration,
		double cost, string lvl, double discount, string Prereqs) : OnlineCourses(id1,name, instrc, numenrolled, tcapacity, rate, duration,
			cost, lvl, discount, Prereqs)
	{
		certification = certification1;
		pcoursename = pcoursename1;
	}

	

	bool checkcapacity()const override {		// capacity checking function
		if (numEnrolled == totalCapacity) {
			return false;
		}
		else
			return true;
	}


	void addstudent() override {		// student adding function

		if (checkcapacity() == true) {
			++numEnrolled;
			cout << "student succesfully added!" << endl;
		}
		else {
			cout << "capacity is full!" << endl;
		}
	};

	bool hasCertification() const {
		return certification;
	}

	string getCertificationStatus() const {
		return certification ? "Yes" : "No";
	}

	friend ostream& operator << (ostream& output, ProfessionalDevelopmentCourses& obj) {		// operator overloading

		output << " courne name : " << obj.courseName << endl
			<< " goal : " << obj.pcoursename << endl
			<< " certification : " << obj.getCertificationStatus() << endl
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

