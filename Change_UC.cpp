//
// Created by avareno on 10/30/23.
//

#include "Change_UC.hpp"
#include <iostream>
#include <vector>
#include "change.hpp"
#include "Change_Class.hpp"

using namespace std;
Change_UC::Change_UC(std::set<Student_class> &students_classes, std::list<Class> &classes, const std::string &stu, queue<Change> &change_log, set<Class_per_uc> &classes_per_uc) {
    int i = 0;
    string num = stu, func;
    string s_name;

    // Check if student exists
    auto it = students_classes.lower_bound(Student_class(num, "", "", ""));

    vector<Student_class> out;

    while (i == 0) {

        it = students_classes.lower_bound(Student_class(num, "", "", ""));

        if (it != students_classes.end() && it->getStudentCode() == num) {
            s_name = it->getStudentName();
            if (out.size() == 0) {
                auto pos2 = it;
                pos2--;
                while (it->getStudentCode() == stu) {
                    out.push_back(*it);
                    it++;
                }
                while (pos2->getStudentCode() == stu) {
                    out.push_back(*pos2);
                    pos2--;
                }
            }

            cout << "Switch | Add | Remove | Switch" << endl;
            cin >> func;
            if(func == "Switch")
            {
                string prev_UC;
                string prev_class_code;
                cout << "UC Code to switch from: ";
                cin >> prev_UC;
                bool found = false;
                for (auto cl : out) {
                    if (cl.getCl().getUcCode() == prev_UC) {
                        prev_class_code = cl.getCl().getClassCode();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student is not enrolled in the mentioned UC" << endl;
                    continue;
                }

                string final_UC;
                cout << "UC Code to switch to: ";
                cin >> final_UC;
                found = false;
                for (Class c : classes) { // Checking if UC Code is valid/exist
                    if (c.getCl().getUcCode() == final_UC) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << '\n' << "ERROR: UC doesn't exist" << endl << '\n';
                    continue;
                }

                string final_class_code;
                cout << "Class Code (of the class you witch to switch to): ";
                cin >> final_class_code;
                found = false;

                if(prev_class_code == final_class_code && prev_UC == final_UC) {
                    cout << "ERROR: Final Class Code and UC Code are the same as the Initial ones." << endl;
                    continue;
                }

                for (Class c : classes) { // Checking if Class Code is valid/exist (pode ser optimizado)
                    if (c.getCl().getUcCode() == final_UC && c.getCl().getClassCode() == final_class_code) {
                        found = true;
                    }
                }
                if (!found) {
                    cout << '\n' << "ERROR: Class not found." << endl;
                    continue;
                }

                Change_Class::Switch(num,s_name,prev_UC,final_UC,prev_class_code,final_class_code,change_log,students_classes, classes_per_uc,classes);

                i=1;
            }else if(func=="Add") // Falta verificar se atlera o equilibrio das turmas.
            {
                if (out.size() >= 7){
                    cout << "Student is already registered to the maximum number of UC's" <<
                         endl << "Please use Switch, or Remove a class before using Add" << endl << '\n';
                    continue;
                }
                string UC;
                cout << "UC Code: ";
                cin >> UC;
                bool found = false;
                for (auto cl : out) {
                    if (cl.getCl().getUcCode() == UC) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    cout << "Student is already enrolled in a class in the same UC" <<
                         endl << "Please use Switch, or Remove the class before enrolling in another one" << endl << '\n';
                    continue;
                }
                for (Class c : classes) { // Checking if UC Code is valid/exist
                    if (c.getCl().getUcCode() == UC) {
                        found = true;
                    }
                }
                if (!found) {
                    cout << '\n' << "ERROR: UC doesn't exist" << endl << '\n';
                    continue;
                }

                string class_code;
                cout << "Class Code: ";
                cin >> class_code;
                found = false;

                for (Class c : classes) { // Checking if Class Code is valid/exist (pode ser optimizado)
                    if (c.getCl().getUcCode() == UC && c.getCl().getClassCode() == class_code) {
                        found = true;
                    }
                }
                if (!found) {
                    cout << '\n' << "ERROR: Class not found." << endl << '\n';
                    continue;
                }

                Change_Class::Add(num,s_name,UC,class_code,change_log,students_classes,classes_per_uc,classes);

                i=1;
            }else if(func=="Remove")
            {
                string UC;
                string class_code;
                cout << "UC Code: ";
                cin >> UC;
                bool found = false;
                for (auto cl : out) {
                    if (cl.getCl().getUcCode() == UC) {
                        class_code = cl.getCl().getClassCode();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student is not enrolled in the mentioned UC or UC doesn't exist." << endl;
                    continue;
                }

                Change_Class::Remove(num,s_name,UC,class_code,change_log,students_classes,classes_per_uc, classes);

                i=1;
            }else{

            }
        }
        else{
            cout << "Número mecanográfico não encontrado, introduza outro número ou use 'q' se desejar voltar atrás.    " << endl;
            cin >> num;
            if(num=="q"){
                break;
            }
        }
    }
}
