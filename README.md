# onlinecoursesc-
A comprehensive Object-Oriented Programming (OOP) demonstration in C++ that models a complete online course platform. This project showcases advanced OOP concepts, design patterns, and clean architecture principles through a practical, real-world application.
Online Course Management System
A C++ project that demonstrates object-oriented programming concepts through a simple online course platform.

About
This project simulates an online course platform where students can:

Browse different types of courses

Enroll in courses

Manage a shopping cart

Rate courses

Project Structure
text
MainProgram01.cpp     - Main program with interactive menu
OnlineCourses.h       - Base class for all courses
LanguageCourses.h     - Language learning courses
SoftwareCourses.h     - Programming courses
ProfessionalDevelopmentCourses.h - Career courses
HealthandFitness.h    - Fitness courses
Student.h            - Student management
Cart.h               - Shopping cart

Features
4 Course Types: Language, Software, Professional Development, and Health & Fitness

Student Management: Add students and track their enrollments

Shopping Cart: Add/remove courses before checkout

Course Ratings: Rate courses from 1 to 5 stars

Capacity Checking: Prevents over-enrollment in courses

Main Menu Options
Add a new student

View all available courses

Add courses to cart

View shopping cart

Remove a course

Checkout and pay

Rate a course

View all students

Exit

OOP Concepts Demonstrated
Inheritance: All course types inherit from base OnlineCourses class

Polymorphism: Different course types implement the same functions differently

Encapsulation: Private data with public getters/setters

Operator Overloading: Custom output for all course types

Example Courses Included
Spanish for Beginners

C++ Programming

Leadership Skills

Weightlifting Basics

Requirements
C++ compiler (g++, clang++, or MSVC)

Basic terminal/command prompt knowledge

Notes
Each student can enroll in up to 3 courses

Courses have limited capacity

Discounts are automatically applied at checkout

Course ratings update in real-time
