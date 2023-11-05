#include <iostream>
#include <fstream>
#include <sstream>
#include "Class.hpp"
#include "Class_per_uc.hpp"
#include "Student_class.hpp"
#include "change.hpp"
#import <queue>
#include <list>
#include "Menu.hpp"


using namespace std;



int main() {



    list<Class> classes; //classes_per_uc, Weekday, StartHour, Duration, Type
    set<Class_per_uc> classes_per_uc;// UcCode, ClassCode
    set<Student_class> students_classes;//StudentCode, Name, Classes_per_uc
    queue<Change> change_log;//int, operation, previous class, final class

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
    if (option == 2) {
        f.open("source/classes.csv");//open Class file
    }else if (option == 1){
        f.open("output/classes_altered.csv");
    }
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

    if (option == 2) {
        f.open("source/classes_per_uc.csv");
    }else if (option == 1){
        f.open("output/classes_per_uc_altered.csv");
    }

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

        if (std::getline(ss, field, '\r')) {
            c.setClassCode(field);
        }
        classes_per_uc.insert(c);
    }
    f.close();

    //populate students_classes
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


