/**
 * @file Change_UC.hpp
 * @brief Declaration of the Change_UC class for changing the UC of a student.
 */


#ifndef PROJETO_CHANGE_UC_HPP
#define PROJETO_CHANGE_UC_HPP


#include <string>
#include <set>
#include <list>
#include <vector>
#include "Student_class.hpp"
#include "Class.hpp"
#include <queue>
#include "Change.hpp"

/**
 * @class Change_UC
 * @brief A class for changing the UC of a student.
 */
class Change_UC {
private:

    std::string stu_;
public:
    /**
     * @brief Constructor for the Change_UC class.
     *
     * @param students_classes A set of student classes.
     * @param classes A list of classes.
     * @param stu The student code.
     * @param change_log A queue of change log entries.
     * @param classes_per_uc A set of classes associated with UCs.
     */
    Change_UC(std::set<Student_class> &students_classes, std::list<Class> &classes, const std::string &stu, std::queue<Change> &change_log, std::set<Class_per_uc> &classes_per_uc);
};


#endif //PROJETO_CHANGE_UC_HPP
