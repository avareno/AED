//
// Created by avareno on 10/30/23.
//

#ifndef PROJETO_CHANGE_CLASS_HPP
#define PROJETO_CHANGE_CLASS_HPP


#include <string>
#include "Student_class.hpp"
#include "Class.hpp"
#include "change.hpp"
#include <map>
#include <queue>
#include <string>

class Change_Class {
private:
    std::string stu_;
public:
    Change_Class(std::set<Student_class> &students_classes, std::list<Class> &classes, const std::string &stu,
                 std::queue<Change> &change_log, std::set<Class_per_uc> &classes_per_uc);
    static void Add(std::string num, std::string s_name, std::string UC, std::string class_code, std::queue<Change> &change_log, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    static void Remove(std::string num, std::string s_name, std::string UC, std::string class_code, std::queue<Change> &change_log, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    static void Switch(std::string num, std::string s_name, std::string prev_UC, std::string final_UC, std::string prev_class_code, std::string final_class_code, std::queue<Change> &change_log, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    static bool Check(std::string num, std::string UC, std::string class_code, int op, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    static std::vector<Class> Student_Schedule(std::string num, std::set<Student_class> &students_classes, std::list<Class> &classes);
    static void Submit(std::queue<Change> &requests, std::string s_name, std::queue<Change> &change_log, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    static double Standard_Deviation(std::string UC, std::string class_code, std::set<Class_per_uc> classes_per_uc, int op);
};



#endif //PROJETO_CHANGE_CLASS_HPP
