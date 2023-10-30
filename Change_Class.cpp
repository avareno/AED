//
// Created by avareno on 10/30/23.
//

#include <set>
#include <list>
#include <iostream>
#include "Change_Class.hpp"
#include "Student_class.hpp"
#include "Class.hpp"

using namespace std;

bool Change_Class::check( std::set<Student_class> &students_classes,  std::list<Class> &classes, const std::string &stu){
    auto it = students_classes.lower_bound(Student_class(stu, "", "", ""));


    it = students_classes.lower_bound(Student_class(stu, "", "", ""));

    // Check if the student was found
    if (it != students_classes.end() && it->getStudentCode() == stu) {
        return true;
    }
    return false;

}

Change_Class::Change_Class(set<Student_class> &students_classes, std::list<Class> &classes, const std::string &stu) {
    int i = 0;
    string num = stu, func;

    while (i == 0) {
        if (check(students_classes, classes, num)) {//check if student exists
            cout << "Switch | Add | Remove" << endl;
            cin >> func;
            if(func == "Switch")
            {
                Switch();//implement remove followed by add;
                i=1;
            }else if(func=="Add")
            {
                i=1;
            }else if(func=="Remove")
            {
                i=1;
            }else{

            }
        }
        else{
            cout << "Número mecanpográfico não encontrado introduza outro número ou use 'q' se desejar voltar atrás" << endl;
            cin >> num;
            if(num=="q"){
                break;
            }
        }

    }
}



void Change_Class::Add() {

}

void Change_Class::Remove() {

}

void Change_Class::Switch(){

}

