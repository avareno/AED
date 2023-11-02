//
// Created by avareno on 10/30/23.
//

#include <set>
#include <list>
#include <iostream>
#include <vector>
#include "Change_Class.hpp"
#include "Student_class.hpp"
#include "Class.hpp"

using namespace std;

void Change_Class::Add(string num, string s_name, string UC, string class_code, queue<Change> &change_log, set<Student_class> &students_classes) {
    students_classes.insert(Student_class(num,s_name,UC,class_code));

    cout << "Successfully enrolled student " << s_name <<
         " (" << num << ") in UC " << UC << " and class " << class_code << ".\n";

    change_log.emplace(Change("Add",num,Class_per_uc(), Class_per_uc(UC,class_code)));
}

void Change_Class::Remove(string num, string s_name, string UC, string class_code, queue<Change> &change_log,set<Student_class> &students_classes) {
    students_classes.erase(Student_class(num,s_name,UC,class_code));

    cout << "Successfully removed student " << s_name <<
         " (" << num << ") from UC " << UC << " and Class " << class_code << ".\n";

    change_log.emplace(Change("Remove",num,Class_per_uc(UC,class_code), Class_per_uc()));
}

void Change_Class::Switch(string num, string s_name,string prev_UC,string final_UC, string prev_class_code, string final_class_code, queue<Change> &change_log, set<Student_class> &students_classes){
    students_classes.erase(Student_class(num,s_name,prev_UC, prev_class_code));
    students_classes.insert(Student_class(num,s_name,final_class_code,final_class_code));

    cout << "Successfully switched student " << s_name <<
         " (" << num << ") from Class " << prev_UC << "->" << prev_class_code <<
         " to Class " << final_UC << "->" << final_class_code << ".\n";

    change_log.emplace(Change("Switch",num,Class_per_uc(prev_UC,prev_class_code), Class_per_uc(final_UC, final_class_code)));
}


Change_Class::Change_Class(set<Student_class> &students_classes, std::list<Class> &classes, const std::string &stu, queue<Change> &change_log) {
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

            cout << "Switch | Add | Remove" << endl;
            cin >> func;
            if(func == "Switch")
            {
                string UC;
                string prev_class_code;
                cout << "UC Code: ";
                cin >> UC;
                bool found = false;
                for (auto cl : out) {
                    if (cl.getCl().getUcCode() == UC) {
                        prev_class_code = cl.getCl().getClassCode();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student is not enrolled in the mentioned UC" << endl;
                    continue;
                }

                string final_class_code;
                cout << "Class Code (of the class you witch to switch to): ";
                cin >> final_class_code;
                found = false;

                if(prev_class_code == final_class_code) {
                    cout << "ERROR: Final Class Code is the same as the Initial Class Code" << endl;
                    continue;
                }

                for (Class c : classes) { // Checking if Class Code is valid/exist (pode ser optimizado)
                    if (c.getCl().getUcCode() == UC && c.getCl().getClassCode() == final_class_code) {
                        found = true;
                    }
                }
                if (!found) {
                    cout << '\n' << "ERROR: Class not found." << endl;
                    continue;
                }

                Switch(num,s_name,UC,UC,prev_class_code,final_class_code,change_log,students_classes);

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

                Add(num,s_name,UC,class_code,change_log,students_classes);

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

                Remove(num,s_name,UC,class_code,change_log,students_classes);

                i=1;
            }else{

            }
        }
        else{
            cout << "Número mecanográfico não encontrado, introduza outro número ou use 'q' se desejar voltar atrás" << endl;
            cin >> num;
            if(num=="q"){
                break;
            }
        }

    }
}
