/**
 * @file main.cpp
 * @brief Main application entry point for schedule management.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Class.hpp"
#include "Class_per_uc.hpp"
#include "Student_class.hpp"
#include "Change.hpp"
#include <queue>
#include <list>
#include "Menu.hpp"

using namespace std;

int main() {
    list<Class> classes;  // Stores information about classes
    set<Class_per_uc> classes_per_uc;  // Stores classes per course unit (UC)
    set<Student_class> students_classes;  // Stores information about students and their classes
    queue<Change> change_log;  // Records changes made to the system

    fstream f;
    string line;



    // Open and populate "classes_per_uc.csv" - O(N)
    f.open("source/classes_per_uc.csv");
    getline(f, line);  // Ignore the first line
    while (getline(f, line)) {
        Class_per_uc c;
        istringstream ss(line);
        string field;

        if (std::getline(ss, field, ',')) {
            c.setUcCode(field);
        }

        if (std::getline(ss, field, '\r')) {
            c.setClassCode(field);
        }
        classes_per_uc.insert(c);
    }
    f.close();

    // Open and populate "classes.csv" - O(M)
    f.open("source/classes.csv");
    getline(f, line);  // Ignore the first line
    while (getline(f, line)) {
        Class c;
        istringstream ss(line);
        string field;
        string b;
        std::getline(ss, field, ',');
        std::getline(ss, b, ',');
        c.setCl(Class_per_uc(b, field));

        if (std::getline(ss, field, ',')) {
            c.setWeekday(field);
        }

        if (std::getline(ss, field, ',')) {
            c.setStartHour(field);
        }

        if (std::getline(ss, field, ',')) {
            c.setDuration(field);
        }

        if (std::getline(ss, field, ',')) {
            c.setType(field);
        }
        classes.push_back(c);
    }
    classes.sort();  // Sort operation: O(M * log(M))
    f.close();


    // Open and populate "students_classes.csv" - O(K)
    f.open("source/students_classes.csv");
    getline(f, line);  // Ignore the first line
    while (getline(f, line)) {
        Student_class c;
        istringstream ss(line);
        string field;
        string b;

        if (std::getline(ss, field, ',')) {
            c.setStudentCode(field);
        }

        if (std::getline(ss, field, ',')) {
            c.setStudentName(field);
        }

        std::getline(ss, b, ',');

        std::getline(ss, field, '\r');
        c.setCl(Class_per_uc(b, field));
        auto it = classes_per_uc.lower_bound(c.getCl());  // Binary search: O(log(N))
        const_cast<Class_per_uc &>(*it).setSize(it->getSize() + 1);

        students_classes.insert(c);
    }
    f.close();
    for(Student_class at: students_classes){
        Student_class* at_p=&at;
        auto it = classes_per_uc.lower_bound(at.getCl());
        at_p->setCl(*it);
    }
    Menu m = Menu(classes, classes_per_uc, students_classes, change_log);
    m.run();

    return 0;
}