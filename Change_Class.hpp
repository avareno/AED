//
// Created by avareno on 10/30/23.
//

#ifndef PROJETO_CHANGE_CLASS_HPP
#define PROJETO_CHANGE_CLASS_HPP


#include <string>
#include "Student_class.hpp"
#include "Class.hpp"

class Change_Class {
private:
    std::string stu_;
public:
    Change_Class( std::set<Student_class> &students_classes,  std::list<Class> &classes, const std::string &stu);
    bool check( std::set<Student_class> &students_classes,  std::list<Class> &classes, const std::string &stu);
    void Switch();
    void Add();
    void Remove();
};



#endif //PROJETO_CHANGE_CLASS_HPP
