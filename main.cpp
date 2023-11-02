#include <iostream>
#include <fstream>
#include <sstream>
#include "Class.hpp"
#include "Class_per_uc.hpp"
#include "Student_class.hpp"
#include "change.hpp"
#include <map>
#import <set>
#include <list>
#include "Menu.hpp"


using namespace std;



int main() {



    list<Class> classes; //classes_per_uc, Weekday, StartHour, Duration, Type
    set<Class_per_uc> classes_per_uc;// UcCode, ClassCode
    set<Student_class> students_classes;//StudentCode, Name, Classes_per_uc
    map<int,Change> change_log;//int, operation, previous class, final class

    fstream f;
    f.open("source/classes_begin.csv");//open Class file
    string line;//string

    //populate classes
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
    classes.sort();
    f.close();

    f.open("source/classes_per_uc.csv");//open Class file

    //populate classes_per_uc
    getline(f,line);//ignore first line
    while(getline(f,line))
    {
        Class_per_uc c;
        istringstream ss(line);
        string field;

        if (std::getline(ss, field, ',')) {
            c.setUcCode(field);

        }

        if (std::getline(ss, field, ',')) {
            c.setClassCode(field);
        }
        classes_per_uc.insert(c);
    }
    f.close();

    //populate students_classes
    f.open("source/students_classes_begin.csv");//open Class file
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

        students_classes.insert(c);
    }
    f.close();

    Menu m = Menu(classes, classes_per_uc, students_classes, change_log);
    m.run();


    return 0;
}


