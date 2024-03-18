#include <iostream>
#include <string>

// Person class
class Person {
private:
    std::string firstName;
    std::string lastName;
    int birthDay;
    int birthMonth;
    int birthYear;

public:
    Person();
    Person(std::string first, std::string last, int day, int month, int year);
    std::string getName();
    std::string getBirthdate();
};

// Constructor definitions for Person class
Person::Person() {
    firstName = "";
    lastName = "";
    birthDay = 1;
    birthMonth = 1;
    birthYear = 1900; // Default birth year
}

Person::Person(std::string first, std::string last, int day, int month, int year) {
    firstName = first;
    lastName = last;
    birthDay = day;
    birthMonth = month;
    birthYear = year;
}

// Accessor methods for Person class
std::string Person::getName() {
    return firstName + " " + lastName;
}

std::string Person::getBirthdate() {
    return std::to_string(birthDay) + "/" + std::to_string(birthMonth) + "/" + std::to_string(birthYear);
}

// Employee class (Child of Person)
class Employee : public Person {
private:
    std::string company;
    double salary;

public:
    Employee(std::string first, std::string last, int day, int month, int year, std::string comp, double sal);
    void setCompany(std::string comp);
    std::string getCompany();
    void setSalary(double sal);
    double getSalary();
};

// Constructor definition for Employee class
Employee::Employee(std::string first, std::string last, int day, int month, int year, std::string comp, double sal)
    : Person(first, last, day, month, year) {
    company = comp;
    salary = sal;
}

// Mutator methods for Employee class
void Employee::setCompany(std::string comp) {
    company = comp;
}

void Employee::setSalary(double sal) {
    salary = sal;
}

// Accessor methods for Employee class
std::string Employee::getCompany() {
    return company;
}

double Employee::getSalary() {
    return salary;
}

// Student class (Child of Person)
class Student : public Person {
private:
    int studentID;

public:
    Student(std::string first, std::string last, int day, int month, int year, int id);
    void setStudentID(int id);
    int getStudentID();
};

// Constructor definition for Student class
Student::Student(std::string first, std::string last, int day, int month, int year, int id)
    : Person(first, last, day, month, year) {
    studentID = id;
}

// Mutator method for Student class
void Student::setStudentID(int id) {
    studentID = id;
}

// Accessor method for Student class
int Student::getStudentID() {
    return studentID;
}

int main() {
    // Testing the classes and their methods
    Employee emp("John", "Doe", 15, 6, 1990, "XYZ Corp", 50000);
    std::cout << "Employee Name: " << emp.getName() << std::endl;
    std::cout << "Employee Birthdate: " << emp.getBirthdate() << std::endl;
    std::cout << "Company: " << emp.getCompany() << std::endl;
    std::cout << "Salary: $" << emp.getSalary() << std::endl;

    Student stu("Alice", "Smith", 5, 9, 2000, 123456);
    std::cout << "\nStudent Name: " << stu.getName() << std::endl;
    std::cout << "Student Birthdate: " << stu.getBirthdate() << std::endl;
    std::cout << "Student ID: " << stu.getStudentID() << std::endl;

    return 0;
}
