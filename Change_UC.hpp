//
// Created by avareno on 10/30/23.
//

#ifndef PROJETO_CHANGE_UC_HPP
#define PROJETO_CHANGE_UC_HPP


#include <string>
#include <set>
#include <list>
#include <vector>
#include "Student_class.hpp"
#include "Class.hpp"
#include <queue>
#include "change.hpp"

class Change_UC {
private:

    std::string stu_;
public:
    Change_UC(std::set<Student_class> &students_classes, std::list<Class> &classes, const std::string &stu, std::queue<Change> &change_log, std::set<Class_per_uc> &classes_per_uc);
};


#endif //PROJETO_CHANGE_UC_HPP
