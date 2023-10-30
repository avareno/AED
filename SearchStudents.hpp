//
// Created by avareno on 10/25/23.
//

#ifndef PROJETO_SEARCHSTUDENTS_HPP
#define PROJETO_SEARCHSTUDENTS_HPP


#include <set>
#include <list>
#include "SearchClass.hpp"
#include "Student_class.hpp"
#include "Class.hpp"


class SearchStudents : Search {
private:
    int i_=0;// used to check if we run() again the menu

public:
    SearchStudents(const std::set<Student_class> &students_classes, const std::list<Class> &classes);
    bool Checkstudent(const std::set<Student_class> &students_classes, std::string stu);
    std::string get_num() override;//get num from the student
    void back() override;

    int getI() const;
};


#endif //PROJETO_SEARCHSTUDENTS_HPP
