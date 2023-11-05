//
// Created by avareno on 10/24/23.
//
#include <iostream>
#include <string>
#include <limits>
#include "Menu.hpp"
#include "SearchStudents.hpp"
#include "SearchUC.hpp"
#include "Change_Class.hpp"
#include "Change_UC.hpp"
#include "Change.hpp"
#include "Quit.hpp"

/**
 * @file Menu.cpp
 * @brief Implementation of the class Menu.hpp
 */
using namespace std;

Menu::Menu(std::list<Class> &classes, std::set<Class_per_uc> &classes_per_uc, std::set<Student_class> &students_classes, queue<Change> &change_log)
{
    this->students_classes = students_classes;
    this->classes_per_uc = classes_per_uc;
    this->classes = classes;
    this->change_log = change_log;
}

const std::list<Class> &Menu::getClasses() const {
    return classes;
}

const std::set<Class_per_uc> &Menu::getClassesPerUc() const {
    return classes_per_uc;
}

const std::set<Student_class> &Menu::getStudentsClasses() const {
    return students_classes;
}

void Menu::setStudentsClasses(const std::set<Student_class> &studentsClasses) {
    students_classes = studentsClasses;
}

void Menu::setClassesPerUc(const std::set<Class_per_uc> &classesPerUc) {
    classes_per_uc = classesPerUc;
}

void Menu::setClasses(const std::list<Class> &classes) {
    Menu::classes = classes;
}


string Menu::homepage()
{
    string line;
    cout << "1.Search | 2.Requests | 3.Undo | 4.Change Log | 5.Quit" << '\n';
    cin >> line;
    return line;
}

void Menu::ChangeLog(queue<Change> change_log, map<int,Change> &temp_change) {
    int i = 1;
    while(!change_log.empty()) {
        Change element = change_log.front();
        if (element.getOp() == "Add") {
            cout << i << ". Added Student nº" << element.getSnum() << " in " <<
                 element.getPostCl().getUcCode() << "->" << element.getPostCl().getClassCode() << endl;

        }else if(element.getOp() == "Remove"){
            cout << i << ". Removed Student nº" << element.getSnum() << " from " <<
                 element.getPrevCl().getUcCode() << "->" << element.getPrevCl().getClassCode() << endl;

        }else if(element.getOp() == "Switch"){
            cout << i << ". Switched Student nº" << element.getSnum() << " from " <<
                 element.getPrevCl().getUcCode() << "->" << element.getPrevCl().getClassCode() << " to " <<
                 element.getPostCl().getUcCode() << "->" << element.getPostCl().getClassCode() << endl;
        }
        temp_change.emplace(i,element);
        change_log.pop();
        i++;
    }
}

void Menu::Undo(Change change, set<Student_class> &students_classes, std::list<Class> &classes, queue<Change> &change_log, set<Class_per_uc> &classes_per_uc) {
    auto it = students_classes.lower_bound(Student_class(change.getSnum(), "", "", ""));
    string sname = it->getStudentName();
    if (change.getOp() == "Add") {
        Change_Class::Remove(change.getSnum(), sname, change.getPostCl().getUcCode(), change.getPostCl().getClassCode(), change_log, students_classes,classes_per_uc,classes);
    }else if(change.getOp() == "Remove"){
        Change_Class::Add(change.getSnum(), sname, change.getPrevCl().getUcCode(), change.getPrevCl().getClassCode(), change_log, students_classes,classes_per_uc,classes);
    }else if(change.getOp() == "Switch"){
        Change_Class::Switch(change.getSnum(), sname, change.getPostCl().getUcCode(), change.getPrevCl().getUcCode(), change.getPostCl().getClassCode(),change.getPrevCl().getClassCode(), change_log, students_classes,classes_per_uc,classes);
    }
}

void Menu::run() {
    cout << "Welcome to your Schedule Mangement System" << endl;
    while(true)
    {
        string s = homepage();
        if(s=="1")//Search
        {

            string l;
            cout << "1.Student | 2.UC | 3.Back" << "\n";
            cin >> l;
            while(true)
            {
                if(l=="1")//Student
                {
                    SearchStudents s = SearchStudents(getStudentsClasses(), getClasses());
                    break;
                }else if(l=="2")//UC
                {
                    SearchUC u = SearchUC(getClassesPerUc(), getClasses());
                    break;
                }else if(l=="3" || l == "q"){//Back
                    break;
                }else{
                    cout << "Select on of the options or select 'q' to go back" << "\n";
                    cin >> l;
                }
            }

        }
        else if(s=="3")//Undo
        {
            cout << "What action do you wish to undo? (type 0 if you wish to return)" << endl;
            map<int,Change> temp_change;
            ChangeLog(change_log, temp_change);
            while(true) {
                int choice;
                if (cin >> choice) {
                    if (choice == 0) {break;}
                    if (choice > temp_change.size()) {
                        cout << "The input you entered is invalid." << endl
                             << "Please enter a valid input or 'q' if you wish to return." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    Change change = temp_change[choice];
                    Undo(change, students_classes, classes, change_log, classes_per_uc);
                }else{
                    cout << "The input you entered is invalid." << endl
                         << "Please enter a valid input or 'q' if you wish to return." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
        else if (s=="4")//Change Log
        {
            map<int,Change> temp_change;
            ChangeLog(change_log, temp_change);
        }
        else if(s=="2")//Requests
        {
            string req, num;
            cout << "1.UC | 2.Class | 3.Back" << endl;
            cin >> req;

            while(true)
            {
                if(req=="1" ) {//UC
                    cout << "Enter the Student Code: ";
                    cin >> num;
                    Change_UC ch_uc = Change_UC(this->students_classes, this->classes, num, this->change_log, this->classes_per_uc);
                    break;
                }else if(req=="2"){//Class
                    cout << "Enter the Student Code: ";
                    cin >> num;
                    Change_Class ch_cl = Change_Class(this->students_classes, this->classes, num, this->change_log,
                                                      this->classes_per_uc);
                    break;
                }else if(req=="3" || req == "q"){//Back
                    break;
                }else{
                    cout << "Please enter a valid input or 'q' if you wish to return." << "\n";
                    cin >> req;
                }
            }
        }
        else if(s=="5")//Quit
        {
            Quit(students_classes,classes_per_uc,classes,change_log);
            break;
        }else{
            cout << "Select on of the options" << "\n";
        }
    }
}
