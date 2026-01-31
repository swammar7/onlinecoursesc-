#pragma once
#include <string>
#include "OnlineCourses.h"
#include "SoftwareCourses.h"
#include "LanguageCourses.h"
#include "ProfessionalDevelopmentCourses.h"
#include "Student.h"
class Cart
{
private:

	static const int maxcourses = 3;	// static so same max number for every object
	int currentcourses = 0;
	bool isconfirmed;
	OnlineCourses* selectedcourses[maxcourses]; // pointer to store selected courses

public:
	int getcurrentcourses() { return currentcourses; };	// getters
	bool getconfirmation() { return isconfirmed; };

	Cart() {				// constructor
		isconfirmed = false;
		currentcourses = 0;
		for (int i = 0; i < maxcourses; i++) {
			selectedcourses[i] = nullptr;
		}
	};

	void confirmcart() {
		isconfirmed = true;
	}

	void addcourse(OnlineCourses* x) {		// function to add a course
		if (currentcourses < maxcourses) {
			selectedcourses[currentcourses] = x;
			currentcourses++;
		}

		else {
			cout << "cart is full!!!" << endl;
		}
		
	};

    bool removecourse(int cn) {		// function to remove a course
        if (isconfirmed) {
            cout << "The cart is already confirmed; cannot remove courses!\n";
            return false;
        }

        for (int i = 0; i < currentcourses; i++) {
            if (selectedcourses[i]->getid() == cn) {
                for (int j = i; j < currentcourses - 1; j++) {
                    selectedcourses[j] = selectedcourses[j + 1];
                }
                selectedcourses[--currentcourses] = nullptr;
                cout << "Course with ID " << cn << " removed.\n";
                return true;
            }
        }

        cout << "Course with ID " << cn << " not found.\n";
        return false;
    }


	void const displaycart() {			// function to display cart using operator overloading

		if (currentcourses == 0) {
			cout << "cart is empty" << endl;
		}
		else {
			for (int i = 0; i < currentcourses; i++) {
				cout << selectedcourses[i];    // here i used operator overloading instead of a usual function
											   
			}
		}
	}
};

