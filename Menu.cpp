//
// Created by avareno on 10/24/23.
//
#include <iostream>
#include <string>
#include "Menu.hpp"
#include "SearchClass.hpp"
#include "SearchStudents.hpp"
#include "SearchUC.hpp"

using namespace std;

Menu::Menu(std::list<Class> &classes, std::set<Class_per_uc> &classes_per_uc, std::set<Student_class> &students_classes)
{
    this->students_classes = students_classes;
    this->classes_per_uc = classes_per_uc,
    this->classes = classes;
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
    cout << "Search | Requests | Undo | Check_Record" << '\n';
    cin >> line;
    return line;
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
            if(l=="Student")
            {
                SearchStudents s = SearchStudents(getStudentsClasses(), getClasses());
                if(s.getI()==1)
                {
                    run();
                }
            }else if(l=="UC")//implement class UC
            {
                SearchUC u = SearchUC(getStudentsClasses(), getClasses());
                if(u.getI()==1)
                {
                    run();
                }
                break;
            }else{
                cout << "Selecione uma das opções" << "\n";
            }
        }else if(s=="Undo")//implement class UC
        {
            break;
        }else if(s=="Requests")//implement class UC
        {
            break;
        }
        else if(s=="Back")
        {
            run();
        }else{
            cout << "Selecione uma das opções" << "\n";
        }
    }

}



