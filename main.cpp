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
#import <queue>
#include <list>
#include "Menu.hpp"


using namespace std;



int main() {



    list<Class> classes;  // Stores information about classes
    set<Class_per_uc> classes_per_uc;  // Stores classes per course unit (UC)
    set<Student_class> students_classes;  // Stores information about students and their classes
    queue<Change> change_log;  // Records changes made to the system

    int option;

    cout << "1. Open previously saved files." << endl << "2. Open original set of data files. (WARNING: This will erease all previously saved data)" << endl;
    while (true) {
        cin >> option;
        if (option == 1 || option == 2) {
            break;
        }
        cout << "Please select a valid option." << endl;
    }

    fstream f;
    // Open and populate "classes.csv" or "classes_altered.csv- O(N)
    if (option == 2) {
        f.open("source/classes.csv");//open Class file
    }else if (option == 1){
        f.open("output/classes_altered.csv");
    }
    string line;//string

    getline(f,line);//ignore first line
    while(getline(f,line))
    {
        Class c;
        istringstream ss(line);
        string field;
        string b;
        std::getline(ss, field, ',');
        std::getline(ss, b, ',');
        c.setCl(Class_per_uc(b,field));

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
    classes.sort(); // Sort operation: O(M * log(M))
    f.close();

    // Open and populate "classes_per_uc.csv" or "classes_per_uc_altered.csv" - O(M)
    if (option == 2) {
        f.open("source/classes_per_uc.csv");
    }else if (option == 1){
        f.open("output/classes_per_uc_altered.csv");
    }

    getline(f,line);//ignore first line
    while(getline(f,line))
    {
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

    // Open and populate "students_classes.csv" or "students_classes_altered.csv" - O(K)
    if (option == 2) {
        f.open("source/students_classes.csv");//open Class file
    }else if (option == 1){
        f.open("output/students_classes_altered.csv");
    }
    getline(f,line);//ignore first line
    while(getline(f,line))
    {
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
        c.setCl(Class_per_uc(b,field));
        auto it = classes_per_uc.lower_bound((c.getCl()));
        const_cast<Class_per_uc&>(*it).setSize(it->getSize() + 1);

        students_classes.insert(c);
    }
    f.close();

    // Open and populate "change_log.csv" - O(J)
    if (option == 1) {
        f.open("output/change_log.csv");
        getline(f,line);//ignore first line
        while(getline(f,line))
        {
            Change c;
            istringstream ss(line);
            string field;
            string b;

            if (std::getline(ss, field, ',')) {
                c.setOp(field);

            }

            if (std::getline(ss, field, ',')) {
                c.setSnum(field);
            }

            std::getline(ss, b, ',');
            std::getline(ss, field, ',');
            c.setPrevCl(Class_per_uc(b,field));
            std::getline(ss, b, ',');
            std::getline(ss, field, '\r');
            c.setPostCl(Class_per_uc(b,field));
            change_log.emplace(c);
        }
    }

    Menu m = Menu(classes, classes_per_uc, students_classes, change_log);
    m.run();

    return 0;
}


