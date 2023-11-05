//
// Created by avareno on 10/24/23.
//
#include <iostream>
#include <string>
#include "Menu.hpp"
#include "SearchClass.hpp"
#include "SearchStudents.hpp"
#include "SearchUC.hpp"
#include "Change_Class.hpp"
#include "Change_UC.hpp"
#include "change.hpp"
#include "Quit.hpp"
#include <utility>


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
    cout << "Search | Requests | Undo | Change Log | Quit" << '\n';
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
    while(true)
    {
        string s = homepage();
        if(s=="Search")
        {

            string l;
            cout << "Student | UC | Back" << "\n";
            cin >> l;
            while(true)
            {
                if(l=="Student")
                {
                    SearchStudents s = SearchStudents(getStudentsClasses(), getClasses());
                    break;
                }else if(l=="UC")//implement class UC
                {
                    SearchUC u = SearchUC(getStudentsClasses(), getClasses());
                    break;
                    break;
                }else if(l=="Back" || l == "q"){
                    break;
                }else{
                    cout << "Selecione uma das opções ou escreva 'q' para retroceder" << "\n";
                    cin >> l;
                }
            }

        }
        else if(s=="Undo")//implement class UC
        {
            cout << "What action do you wish to undo? (type 0 if you wish to return)" << endl;
            map<int,Change> temp_change;
            ChangeLog(change_log, temp_change);
            while(true) {
                string input;
                if (cin >> input) {
                    if (input == "q") {break;}
                    int choice = stoi(input);
                    size_t test  = temp_change.size();
                    if (choice > temp_change.size() || choice <= 0) {
                        cout << "The input you entered is invalid." << endl
                             << "Please enter a valid input or 'q' if you wish to return." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }else{
                        Change change = temp_change[choice];
                        Undo(change, students_classes, classes, change_log, classes_per_uc);
                    }
                }else{
                    cout << "The input you entered is invalid." << endl
                         << "Please enter a valid input or 'q' if you wish to return." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }
        else if (s=="ChangeLog")
        {
            map<int,Change> temp_change;
            ChangeLog(change_log, temp_change);
        }
        else if(s=="Requests")//implement class UC
        {
            string req, num;
            cout << "UC | Class | Back" << endl;
            cin >> req;

            while(true)
            {
                if(req=="UC" ) {
                    cout << "Numero mecanográfico: ";
                    cin >> num;
                    Change_UC ch_uc = Change_UC(this->students_classes, this->classes, num, this->change_log, this->classes_per_uc);
                    break;
                }else if(req=="Class"){
                    cout << "Numero mecanográfico: ";
                    cin >> num;
                    Change_Class ch_cl = Change_Class(this->students_classes, this->classes, num, this->change_log,
                                                      this->classes_per_uc);
                    break;
                }else if(req=="Back" || req == "q"){
                    break;
                }else{
                    cout << "Selecione uma das opções ou escreva 'q' para retroceder" << "\n";
                    cin >> req;
                }
            }
        }
        else if(s=="Quit")
        {
            Quit(students_classes,classes_per_uc,classes,change_log);
            break;
        }else{
            cout << "Selecione uma das opções" << "\n";
        }
    }
}
