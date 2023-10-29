//
// Created by avareno on 10/25/23.
//

#ifndef PROJETO_SEARCHUC_HPP
#define PROJETO_SEARCHUC_HPP


#include <set>
#include <list>
#include "SearchClass.hpp"
#include "Student_class.hpp"
#include "Class.hpp"


class SearchUC : Search {
private:
    int i=0;// used to check if we run() again the menu

public:
    SearchUC(const std::set<Student_class> &students_classes, const std::list<Class> &classes);
    SearchUC(const std::set<Student_class> &students_classes, const std::list<Class> &classes,std::string num);
    std::string get_num() override;//get num from the student
    void back() override;

    int getI() const;
};


#endif //PROJETO_SEARCHSUC_HPP
