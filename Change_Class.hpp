#ifndef PROJETO_CHANGE_CLASS_HPP
#define PROJETO_CHANGE_CLASS_HPP


#include <string>
#include "Student_class.hpp"
#include "Class.hpp"
#include "Change.hpp"
#include <map>
#include <queue>
#include <string>

/**
 * @file Change_Class.hpp
 * @brief A class responsible for managing class change operations.
 *
 * This class provides functionality to perform add, remove, and switch class operations for students, along with
 * various checks and student schedule retrieval.
 */

/**
 * @brief Header file for the Change_Class class, responsible for managing class change operations.
 *
 * This class provides functionality to perform add, remove, and switch class operations for students, along with
 * various checks and student schedule retrieval.
 */

class Change_Class {
public:
    /**
     * @brief
     * @param students_classes
     * @param classes
     * @param stu
     * @param change_log
     * @param classes_per_uc
     */
    Change_Class(std::set<Student_class> &students_classes, std::list<Class> &classes, const std::string &stu,std::queue<Change> &change_log, std::set<Class_per_uc> &classes_per_uc);
    /**
     * @brief
     * @param num
     * @param s_name
     * @param UC
     * @param class_code
     * @param change_log
     * @param students_classes
     * @param classes_per_uc
     * @param classes
     */
    static void Add(std::string num, std::string s_name, std::string UC, std::string class_code, std::queue<Change> &change_log, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    /**
     * @brief
     * @param num
     * @param s_name
     * @param UC
     * @param class_code
     * @param change_log
     * @param students_classes
     * @param classes_per_uc
     * @param classes
     */
    static void Remove(std::string num, std::string s_name, std::string UC, std::string class_code, std::queue<Change> &change_log, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    /**
     * @brief
     * @param num
     * @param s_name
     * @param prev_UC
     * @param final_UC
     * @param prev_class_code
     * @param final_class_code
     * @param change_log
     * @param students_classes
     * @param classes_per_uc
     * @param classes
     */
    static void Switch(std::string num, std::string s_name, std::string prev_UC, std::string final_UC, std::string prev_class_code, std::string final_class_code, std::queue<Change> &change_log, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    /**
     * @brief
     * @param num
     * @param UC
     * @param class_code
     * @param op
     * @param students_classes
     * @param classes_per_uc
     * @param classes
     * @return
     */
    static bool Check(std::string num, std::string UC, std::string class_code, int op, std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes);
    /**
     * @brief
     * @param num
     * @param students_classes
     * @param classes
     * @return
     */
    static std::vector<Class> Student_Schedule(std::string num, std::set<Student_class> &students_classes, std::list<Class> &classes);
};



#endif //PROJETO_CHANGE_CLASS_HPP
