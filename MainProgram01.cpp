#include <string>
#include "OnlineCourses.h"
#include "SoftwareCourses.h"
#include "LanguageCourses.h"
#include "ProfessionalDevelopmentCourses.h"
#include "HealthandFitness.h"
#include "Student.h"
#include "Cart.h"

template <typename T>
double calculateDiscountedPrice(T* course) {  // a template function to calculate the discounted price
	if (!course) {							  // T is a placeholder for any type 
		cout << "invalid course !" << endl;
		return 0.0;
	}

	double originalPrice = course->getprice();
	double discountRate = course->getdiscountr();
	double discountedPrice = originalPrice * (1 - discountRate / 100);

	return discountedPrice;
}

int main() {// the courses
	ProfessionalDevelopmentCourses Leadership(
		true, "Leading with Impact",1, "leadership ", "Layla Ibrahim", 5, 9, 5.0, 6, 200, "intermediate",
		20.0, "none");

	ProfessionalDevelopmentCourses time_management(
		false, "time Management Mastery",2, "time management ", "Sophia Bennett", 0, 10, 4.8, 3, 150, "Beginner",
		10.0, "none");

	ProfessionalDevelopmentCourses comunication_course(
		true, "Effective Communication Skills",3, "comunication skills ", "David Patel", 10, 15, 4.0, 6, 250, "Advanced",
		10.0, "basic comunication skills");

	LanguageCourses spanish(
		false, "Spanish",4, "Spanish for beginners", "Maria lopez", 15, 20, 4.5, 10, 250, "Beginner", 15, "none");

	LanguageCourses french(
		true, "French",5, "b2 french", "Pierre dubois", 12, 20, 3.0, 18, 300, "Advanced", 15, "A and B levels of french");

	LanguageCourses russian(
		true, "Russian",6, "Russian or beginners", "Anastasia Ivanova", 14, 15, 5.0, 15, 180, "Beginner", 20, "none");

	SoftwareCourses oop(
		"c++", "Visual studio",7, "Object oriented programing", "Busra Kocacinar", 179, 180, 5.0, 50, 300, "intermidiate", 5, "Discrete structures");

	SoftwareCourses gamedevelopment(
		"c++", "Visual studio",8, "c++ for game developers", "Sarah Conor", 120, 125, 4.2, 45, 300, "Advanced", 10, "Basic knowledge of C++");

	SoftwareCourses python(
		"python", "PyCharm",9, "Python Programming for Beginners", "John Doe", 2, 15, 1.5, 50, 400, "Beginner", 5, "none");

	HealthandFitness whlifting(
		"Dumbbells, Barbells, Bench Press", 400,10, "Weightlifting Basics", "Liam Carter", 20, 25, 4.7, 30, 200, "Beginner", 5, "Basic knowledge of gym equipment");

	HealthandFitness Marathon(
		"Running Shoes, Fitness Tracker", 700,11, "Marathon Prep Training", "Ethan Lewis", 12, 15, 4.8, 50, 300, "Advanced", 5, "Running baseline at least 5km");

	HealthandFitness HIIT(
		"None (Bodyweight exercises)", 600,12, "High-Intensity Interval Training", "Ava Thompson", 18, 20, 4.5, 10, 100, "Intermediate", 8, "Good physical health");

	

	const int max_students = 10;
	int studentcount = 0;

	Student* students[max_students];			// creating students and carts with pointers
	for (int i = 0; i < max_students; i++) {
		students[i] = nullptr;
	}
	Cart* carts[max_students];
	for (int i = 0; i < max_students; i++) {
		carts[i] = nullptr;
	}

	while (1) {												// while loop for the menu
		cout << endl<<"_____Online Courses Menu_____\n";
		cout << "1. Add student\n";
		cout << "2. display available courses\n";
		cout << "3. Add courses\n";
		cout << "4. View cart\n";
		cout << "5. Remove course\n";
		cout << "6. Confirm cart and pay\n";
		cout << "7. Rate a course\n";
		cout << "8. View available students\n";
		cout << "9. Exit\n";
		

		int choice;
		cout << "enter your choice : ";
		cin >> choice;
		switch (choice) {
		case 1: {
			if (studentcount >= max_students) {
				cout << "maximum number of students reached " << endl;
			}
			else {
				string name, surname, email;
				cout << "Enter student name: ";
				cin >> name;
				cout << "Enter student surname: ";
				cin >> surname;
				cout << "Enter student email: ";
				cin >> email;
				students[studentcount] = new Student(name, surname, email);				// creating a new student and cart pointer
				carts[studentcount] = new Cart();
				cout << "Student added successfully!" << endl;
				studentcount++;
			}
			break;

		}

		case 2: {

			cout << endl << "******* Professional Development Courses *******" << endl << endl;		// displaying courses with operator overloading
			cout << Leadership<<endl  << time_management << endl << comunication_course << endl;
			cout << "Language Courses : " << endl << endl;
			cout << spanish << endl << french << endl << russian << endl;
			cout << "******* Software Courses *******" << endl;
			cout << oop << endl << gamedevelopment << endl << python << endl;
			cout << "******* Health & Fitness Courses *******" << endl << endl;
			cout << whlifting << endl << Marathon << endl << HIIT << endl;
			break;

			  }
		case 3: {
			
			cout << "Enter the name of the student: ";
			string studentName;
			cin >> studentName;

			bool studentFound = false;			/* a way to find the student to add, remove, rate
												   course and view cart */
			Student* selectedStudent = nullptr;
			Cart* selectedcart = nullptr;

			
			for (int i = 0; i < studentcount; i++) {
				if (students[i]->getname() == studentName) {
					selectedStudent = students[i];
					selectedcart = carts[i];
					studentFound = true;
					break;
				}
			}
			if (selectedcart->getconfirmation() == true) {
				cout << "cart is already confirmed" << endl;
				break;
			}

			if (!studentFound) {
				cout << "Student not found!" << endl;
				break;
			}

			
			cout << "Available courses:\n";
			cout << "1. Leading with Impact\n";
			cout << "2. Time Management Mastery\n";
			cout << "3. Effective Communication Skills\n";
			cout << "4. Spanish\n";
			cout << "5. French\n";
			cout << "6. Russian\n";
			cout << "7. Object Oriented Programing\n";
			cout << "8. C++ for Game Developers\n";
			cout << "9. Python Programming for Beginners\n";
			cout << "10. Weightlifting Basics\n";
			cout << "11. Marathon Prep Training\n";
			cout << "12. High-Intensity Interval Training\n";
			cout << "Enter the number corresponding to the course you want to add (0 to stop): "<<endl;

			int courseSelection;
			while (true) {
				cin >> courseSelection;

				if (courseSelection == 0) {
					break; 
				}

				OnlineCourses* selectedCourse = nullptr;	// pointer to point to the selected course to add

				
				switch (courseSelection) {
				case 1: selectedCourse = &Leadership; break;				
				case 2: selectedCourse = &time_management; break;
				case 3: selectedCourse = &comunication_course; break;
				case 4: selectedCourse = &spanish; break;
				case 5: selectedCourse = &french; break;
				case 6: selectedCourse = &russian; break;
				case 7: selectedCourse = &oop; break;
				case 8: selectedCourse = &gamedevelopment; break;
				case 9: selectedCourse = &python; break;
				case 10: selectedCourse = &whlifting; break;
				case 11: selectedCourse = &Marathon; break;
				case 12: selectedCourse = &HIIT; break;					
				default:
					cout << "Invalid selection, please try again!"<<endl;
					continue;
				}

				
				if (selectedCourse != nullptr) {
					if (selectedCourse->checkcapacity() == false) {		// first check course capacity
						cout << "capacity is full" << endl;
					}
					else {
						if (selectedStudent->enrollcourse(selectedCourse) == true) {   // if the student could enroll in the course
							selectedCourse->addstudent();							   // (didnt reach the limit) then we also add the 
							cout << "Course added successfully!" << endl;			   // student to the course

						}
						else {
							cout << "Could not enroll in the course." << endl;
						}
					}
				}
			}

			break;
		}
		case 4: {
			cout << "Enter the name of the student: ";
			string studentName;
			cin >> studentName;

			bool studentFound = false;
			Student* selectedStudent = nullptr;		// same student finding method

			
			for (int i = 0; i < studentcount; i++) {
				if (students[i]->getname() == studentName) {
					selectedStudent = students[i];
					studentFound = true;
					break;
				}
			}

			if (!studentFound) {
				cout << "Student not found!" << endl; 
				break;
			}
			
			
			int numCourses = selectedStudent->getNEC();		// to check the number of courses student enrolled in

			if (numCourses == 0) {
				cout << "This student is not enrolled in any courses.\n";
				break;
			}
			else {
				cout << "Courses in " << studentName << " cart : " << endl<<endl;
				for (int i = 0; i < numCourses; i++) {
					OnlineCourses* course = selectedStudent->getEnrolledCourse(i);	
					if (course != nullptr) {
						cout << *course << endl;	// pointer to print the course with operator overloading
						cout << "Discounted price: " << calculateDiscountedPrice(course) << endl<<endl;
					}
				}
				cout << endl;

				break;
			}
		}
		case 5: {
			cout << "Enter the name of the student: ";
			string studentName;
			cin >> studentName;

			Student* selectedStudent = nullptr;
			Cart* selectedCart = nullptr;

			for (int i = 0; i < studentcount; i++) {
				if (students[i]->getname() == studentName) { // student finding method but this time cart also 
					selectedStudent = students[i];
					selectedCart=carts[i];

					break;
				}
			}

			if (!selectedStudent) {
				cout << "Student not found!" << endl;
				break;
			}

			cout << "Courses enrolled by " << studentName << ":\n";

			int numCourses = selectedStudent->getNEC(); // to check the number of courses student enrolled in

			if (numCourses == 0) {
				cout << "This student is not enrolled in any courses.\n";
				break;
			}

			
			for (int i = 0; i < numCourses; i++) {
				OnlineCourses* course = selectedStudent->getEnrolledCourse(i); //course pointer changes every iteration
				if (course) {
					cout << i + 1 << ". " << course->getCN() << endl;  // i+1 because the array starts at 0 as the first element
				}
			}
			cout << "Do you want to perform an action with these courses? (y/n): ";
			char choice;
			cin >> choice;

			if (choice == 'y' || choice == 'Y') {
				cout << "Enter the number of the course you want to remove: ";
				int courseNumber;
				cin >> courseNumber;

				if (courseNumber > 0 && courseNumber <= numCourses) {
					OnlineCourses* selectedCourse = selectedStudent->getEnrolledCourse(courseNumber - 1);	// minus one now for the array
					if (selectedCourse) {
						
						cout << "Course Name: " << selectedCourse->getCN() << endl;


						cout << "Do you want to remove this course? (y/n): ";
						char removeChoice;
						cin >> removeChoice;

						if (removeChoice == 'y' || removeChoice == 'Y') {
							if (selectedStudent->removecourse(selectedCourse->getid())) { 
								cout << "Course removed successfully!\n";
							}
							else {
								cout << "failed to remove course. it might not exist.\n";
							}
						}
					}
				}
				else {
					cout << "invalid course number.\n";
				}
			}
			else {
				cout << "going back to menu..." << endl;
			}
			break;
		}

		case 6: {
			cout << "Enter the name of the student: ";
			string studentName;
			cin >> studentName;

			bool studentFound = false;
			Student* selectedStudent = nullptr;
			Cart* selectedCart = nullptr;

			
			for (int i = 0; i < studentcount; i++) {
				if (students[i]->getname() == studentName) { // student finding method
					selectedStudent = students[i];
					selectedCart = carts[i];
					studentFound = true;
					break;
				}
			}

			if (!studentFound) {
				cout << "Student not found!" << endl;
				break;
			}

			if (selectedCart->getconfirmation() == true) {
				cout << "Cart is already confirmed." << endl; // checking if confirmed
				break;
			}

			if (selectedStudent->getNEC() == 0) {
				cout << "Cart is empty!" << endl; // checking if cart is empty
				break;
			}
			cout << "Do you want to confirm this cart? (y/n): ";
			char confirmChoice;
			cin >> confirmChoice;
			if (confirmChoice == 'y' || confirmChoice == 'Y') {
				selectedCart->confirmcart();
				double totalPrice = 0;

				for (int i = 0; i < selectedStudent->getNEC(); i++) {
					double discountedPrice = calculateDiscountedPrice(selectedStudent->getEnrolledCourse(i));
					totalPrice += discountedPrice;
				}
				int numCourses = selectedStudent->getNEC();
				cout << "Courses in " << studentName << " cart : " << endl << endl;
				for (int i = 0; i < numCourses; i++) {
					OnlineCourses* course = selectedStudent->getEnrolledCourse(i);
					if (course != nullptr) {
						cout << *course << endl;
					}
				}
				cout << endl;

				cout << "Total Price (after discounts): " << totalPrice << endl;
				cout << "cart cofirmed " << endl;
				break;
			}
			else {
				cout << "going back to menu..." << endl;
				break;
			}
		}

		case 7: { cout << "Enter student name: ";			// rating course
			string studentName;
			cin >> studentName;

			Student* selectedStudent = nullptr;
			for (int i = 0; i < studentcount; i++) {
				if (students[i]->getname() == studentName) {
					selectedStudent = students[i];
					break;
				}
			}

			if (!selectedStudent) {
				cout << "Student not found.\n";
				break;
			}

			if (selectedStudent->getNEC() == 0) {
				cout << "No courses enrolled to rate.\n";
				break;
			}

			cout << "Courses to rate:\n";
			for (int i = 0; i < selectedStudent->getNEC(); i++) {
				cout << i + 1 << ". " << selectedStudent->getEnrolledCourse(i)->getcoursename() << endl;		
			}

			cout << "Select a course to rate (1-" << selectedStudent->getNEC() << "): ";		// the method here is similar to the course removing method
			int courseidx;
			cin >> courseidx;
			if (courseidx < 1 || courseidx > selectedStudent->getNEC()) {				
				cout << "Invalid choice.\n";
				break;
			}

			OnlineCourses* courseToRate = selectedStudent->getEnrolledCourse(courseidx - 1);
			double newRating;
			cout << "Enter your rating (1-5): ";	
			cin >> newRating;
			if (newRating < 1 || newRating > 5) {
				cout << "Invalid rating.\n";
				break;
			}

			courseToRate->addrating(newRating);
			cout << "Thank you for your feedback!\n";
			break;

		}
		case 8: {							// a case to display students available
			if (studentcount == 0) {
				cout << "No students available.";
				break;
			}
			else {
				cout << "Available students: " << endl;
				for (int i = 0; i < studentcount; i++) {
					students[i]->displaystdinfo();
					cout << endl;
				}
				break;
			}
		}
		case 9: {
			return 0;
		}

		}
	}
}