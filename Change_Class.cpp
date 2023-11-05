#include <set>
#include <list>
#include <iostream>
#include <vector>
#include "Change_Class.hpp"
#include "Student_class.hpp"
#include "Class.hpp"

/**
 * @file Change_Class.cpp
 * @brief Implementation of the Change_Class class for managing classes associated with a specific UC.
 */
using namespace std;

/**
 * @brief Generate a student's class schedule.
 *
 * This function constructs a class schedule for a specific student based on their student code.
 *
 * @param num The student's code for which the schedule is generated.
 * @param students_classes A set of student class objects.
 * @param classes A list of class objects representing all available classes.
 * @return A vector of Class objects representing the student's schedule.
 *
 * @note This function finds and compiles a list of classes in which the student is enrolled
 * and creates a schedule based on those classes.
 *
 * @note Time Complexity: O(N * M), where N is the number of student_class objects and M is the number of class objects.
 */
vector<Class> Change_Class::Student_Schedule(string num, set<Student_class> &students_classes, list<Class> &classes) {
    vector<Student_class> out;
    auto it = students_classes.lower_bound(Student_class(num, "", "", ""));
    auto pos2 = it;
    pos2--;

    while (it->getStudentCode() == num) {
        out.push_back(*it);
        it++;
    }

    while (pos2->getStudentCode() == num) {
        out.push_back(*pos2);
        pos2--;
    }

    vector<Class> schedule;

    for (auto element : out) {
        for (auto class_element : classes) {
            if (element.getCl() == class_element.getCl()) {
                schedule.push_back(class_element);
                break;
            }
        }
    }

    return schedule;
}


/**
 * @brief Check if a class change is valid for a student.
 *
 * This function checks whether a proposed class change for a student is valid based on various criteria,
 * including class sizes, maximum differences, and schedule conflicts.
 *
 * @param num The student's code for whom the change is being checked.
 * @param UC The UC (University Course) code related to the class change.
 * @param class_code The code of the class for the change.
 * @param op The type of operation to perform (1 for add, -1 for remove).
 * @param students_classes A set of student class objects.
 * @param classes_per_uc A set of Class_per_uc objects representing class sizes in UCs.
 * @param classes A list of class objects representing all available classes.
 * @return true if the change is valid; false otherwise.
 *
 * @note This function evaluates the validity of a class change based on several conditions,
 * including class sizes, maximum differences, and schedule conflicts with the existing schedule.
 *
 * @note Time Complexity: O(N * M), where N is the number of student_class objects and M is the number of class objects.
 */
bool Change_Class::Check(string num, string UC, string class_code, int op, set<Student_class> &students_classes,
                         set<Class_per_uc> &classes_per_uc, list<Class> &classes) {
    vector<Class> schedule = Student_Schedule(num, students_classes, classes); // Vector with all Classes/UCs for the Student
    int class_size = classes_per_uc.lower_bound(Class_per_uc(UC, class_code))->getSize();

    if (op == 1) {
        if (Class_per_uc().max_size == class_size) {
            cout << "Unable to make the change, the class is full." << endl;
            return false;
        }

        auto it = classes_per_uc.lower_bound(Class_per_uc(UC, ""));
        while (it->getUcCode() == UC) {
            if (class_size + 1 - it->getSize() > 4 || class_size + 1 - it->getSize() < -4) {
                cout << "Unable to make the change, the maximum difference between class sizes in the UC becomes greater than 4." << endl;
                return false;
            }
            it++;
        }

        Class time;
        for (auto class_element : classes) {
            if (class_element.getCl() == Class_per_uc(UC, class_code) && class_element.getType() != "T") {
                time = class_element;
                break;
            }
        }

        float t_start = stof(time.getStartHour());
        float t_end = stof(time.getStartHour()) + stof(time.getDuration());

        for (auto student_class : schedule) {
            if (time.getWeekday() == student_class.getWeekday() && student_class.getType() != "T") {
                float start = stof(student_class.getStartHour());
                float end = stof(student_class.getStartHour()) + stof(student_class.getDuration());
                if ((start > t_start && start < t_end) || (start < t_start && end > t_start) || (start == t_start) || (end == t_end)) {
                    cout << "The changes conflict with the student's schedule, no changes made." << endl;
                    return false;
                }
            }
        }

        return true;
    } else if (op == -1) {
        auto it = classes_per_uc.lower_bound(Class_per_uc(UC, ""));
        while (it->getUcCode() == UC) {
            if (class_size - 1 - it->getSize() < -4 || class_size - 1 - it->getSize() > 4) {
                cout << "Unable to make the change, the maximum difference between class sizes in the UC becomes greater than 4." << endl;
                return false;
            }
            it++;
        }
        return true;
    }
}



/**
 * @brief Add a student to a class in a university course (UC).
 *
 * This function attempts to add a student to a class within a specific university course.
 *
 * @param num The student's code.
 * @param s_name The student's name.
 * @param UC The UC (University Course) code to which the student should be added.
 * @param class_code The code of the class to add the student.
 * @param change_log A queue to log changes.
 * @param students_classes A set of student class objects.
 * @param classes_per_uc A set of Class_per_uc objects representing class sizes in UCs.
 * @param classes A list of class objects representing all available classes.
 *
 * @note This function checks if the operation is valid using the `Check` method, and if it is valid,
 * adds the student to the specified UC and class. It also updates the change log and class size in UC.
 *
 * @note Time Complexity: O(N + M), where N is the number of student_class objects and M is the number of Class_per_uc objects.
 */
void Change_Class::Add(string num, string s_name, string UC, string class_code, queue<Change> &change_log,
                       set<Student_class> &students_classes, set<Class_per_uc> &classes_per_uc, list<Class> &classes) {

    if (Check(num, UC, class_code, 1, students_classes, classes_per_uc, classes)) {
        students_classes.insert(Student_class(num, s_name, UC, class_code));

        cout << "Successfully enrolled student " << s_name <<
             " (" << num << ") in UC " << UC << " and class " << class_code << ".\n";

        change_log.emplace(Change("Add", num, Class_per_uc(), Class_per_uc(UC, class_code)));

        auto it = classes_per_uc.lower_bound(Class_per_uc(UC, class_code));
        const_cast<Class_per_uc &>(*it).setSize(it->getSize() + 1);
    }
}

/**
 * @brief Remove a student from a class in a university course (UC).
 *
 * This function attempts to remove a student from a class within a specific university course.
 *
 * @param num The student's code.
 * @param s_name The student's name.
 * @param UC The UC (University Course) code from which the student should be removed.
 * @param class_code The code of the class to remove the student.
 * @param change_log A queue to log changes.
 * @param students_classes A set of student class objects.
 * @param classes_per_uc A set of Class_per_uc objects representing class sizes in UCs.
 * @param classes A list of class objects representing all available classes.
 *
 * @note This function checks if the operation is valid using the `Check` method, and if it is valid,
 * removes the student from the specified UC and class. It also updates the change log and class size in UC.
 *
 * @note Time Complexity: O(N + M), where N is the number of student_class objects and M is the number of Class_per_uc objects.
 */
void Change_Class::Remove(string num, string s_name, string UC, string class_code, queue<Change> &change_log,
                          set<Student_class> &students_classes, set<Class_per_uc> &classes_per_uc, list<Class> &classes) {
    if (Check(num, UC, class_code, -1, students_classes, classes_per_uc, classes)) {
        students_classes.erase(Student_class(num, s_name, UC, class_code));

        cout << "Successfully removed student " << s_name <<
             " (" << num << ") from UC " << UC << " and Class " << class_code << ".\n";

        change_log.emplace(Change("Remove", num, Class_per_uc(UC, class_code), Class_per_uc()));
        auto it = classes_per_uc.lower_bound(Class_per_uc(UC, class_code));
        const_cast<Class_per_uc &>(*it).setSize(it->getSize() - 1);
    }
}

/**
 * @brief Switch a student from one class to another within a university course (UC).
 *
 * This function allows a student to switch from one class to another within the same university course (UC).
 *
 * @param num The student's code.
 * @param s_name The student's name.
 * @param prev_UC The previous UC (University Course) code of the student.
 * @param final_UC The target UC code to switch to.
 * @param prev_class_code The code of the previous class from which the student is switching.
 * @param final_class_code The code of the target class to which the student is switching.
 * @param change_log A queue to log changes.
 * @param students_classes A set of student class objects.
 * @param classes_per_uc A set of Class_per_uc objects representing class sizes in UCs.
 * @param classes A list of class objects representing all available classes.
 *
 * @note This function first checks if the operation is valid using the `Check` method. If the operation is valid,
 * it updates the student's enrollment in the specified UC and classes, records the change in the change log,
 * and updates class sizes in UCs.
 *
 * @note Time Complexity: O(N + M), where N is the number of student_class objects, and M is the number of Class_per_uc objects.
 */
void Change_Class::Switch(string num, string s_name, string prev_UC, string final_UC, string prev_class_code, string final_class_code,
                          queue<Change> &change_log, set<Student_class> &students_classes, set<Class_per_uc> &classes_per_uc, list<Class> &classes) {
    bool flag = false;
    if (Check(num, prev_UC, prev_class_code, -1, students_classes, classes_per_uc, classes)) {
        auto it = classes_per_uc.lower_bound(Class_per_uc(prev_UC, prev_class_code));
        const_cast<Class_per_uc &>(*it).setSize(it->getSize() - 1);
        students_classes.erase(Student_class(num, s_name, prev_UC, prev_class_code));
        if (Check(num, final_UC, final_class_code, 1, students_classes, classes_per_uc, classes)) {
            students_classes.insert(Student_class(num, s_name, final_UC, final_class_code));

            cout << "Successfully switched student " << s_name <<
                 " (" << num << ") from Class " << prev_UC << "->" << prev_class_code <<
                 " to Class " << final_UC << "->" << final_class_code << ".\n";

            change_log.emplace(Change("Switch", num, Class_per_uc(prev_UC, prev_class_code), Class_per_uc(final_UC, final_class_code)));

            auto it = classes_per_uc.lower_bound(Class_per_uc(final_UC, final_class_code));
            const_cast<Class_per_uc &>(*it).setSize(it->getSize() + 1);
        } else {
            auto it = classes_per_uc.lower_bound(Class_per_uc(prev_UC, prev_class_code));
            const_cast<Class_per_uc &>(*it).setSize(it->getSize() + 1);
            students_classes.insert(Student_class(num, s_name, prev_UC, prev_class_code));
        }
    }
}

Change_Class::Change_Class(std::set<Student_class> &students_classes, std::list<Class> &classes, const std::string &stu, std::queue<Change> &change_log, std::set<Class_per_uc> &classes_per_uc) {
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

                for (Class c : classes) { // Checking if Class Code is valid/exist
                    if (c.getCl().getUcCode() == UC && c.getCl().getClassCode() == final_class_code) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << '\n' << "ERROR: Class not found." << endl;
                    continue;
                }

                Switch(num,s_name,UC,UC,prev_class_code,final_class_code,change_log,students_classes,classes_per_uc,classes);

                i=1;
            }else if(func=="Add")
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

                Add(num,s_name,UC,class_code,change_log,students_classes,classes_per_uc,classes);

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

                Remove(num,s_name,UC,class_code,change_log,students_classes,classes_per_uc,classes);

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
