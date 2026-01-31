#include <string>
#include "OnlineCourses.h"
#include "SoftwareCourses.h"
#include "LanguageCourses.h"
#include "ProfessionalDevelopmentCourses.h"
#pragma once
class Student
{
private:
	static const int max_enrolled_courses = 3;		// static so same max number for every object
	string name;
	string surname;
	string email;
	OnlineCourses* enrolledCourses[max_enrolled_courses];	// pointer to store enrolled courses
	int numEnrolledCourses;
public:

	OnlineCourses* getEnrolledCourse(int x) const {
		if (x < 0 || x >= numEnrolledCourses) {
			return nullptr;
		}
		return enrolledCourses[x];
	}

	string getname() { return name; };			// getters
	string getsurname() { return surname; };
	string getemail() { return email; };
	int getNEC() { return numEnrolledCourses; };

	Student() {
		name = "undefined";
		surname = "undefined";
		email = "undefined";
		numEnrolledCourses = 0;
	}
	Student(string x, string y, string z) {
		name = x;
		surname = y;
		email = z;
		numEnrolledCourses = 0;
	}
	~Student() {}

	bool enrollcourse(OnlineCourses* course) {

		if(numEnrolledCourses==max_enrolled_courses){
			cout << "you have reached your limit" << endl;
			return false;
		}
		else {
			for (int i = 0; i < numEnrolledCourses; i++) {
				if (enrolledCourses[i] == course) {
					cout << "you already have it" << endl;
					return false;
				}
			}
		}
			enrolledCourses[numEnrolledCourses++] = course;
			return true;
	}
	bool removecourse(int cid) {
		for (int i = 0; i < numEnrolledCourses; i++) {
			if (enrolledCourses[i]->getid() == cid) {
				for (int j = i; j < numEnrolledCourses - 1; j++) {
					enrolledCourses[j] = enrolledCourses[j + 1];
				}
				enrolledCourses[--numEnrolledCourses] = nullptr;
				return true;
			}
		}
		return false;
	}
	void displaystdinfo() {
		cout << getname()<<endl;
		cout << getsurname()<<endl;
		cout << getemail()<<endl;
	}
};

