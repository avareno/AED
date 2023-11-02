//
// Created by avareno on 10/24/23.
//

#ifndef PROJETO_MENU_HPP
#define PROJETO_MENU_HPP


#include "Student_class.hpp"
#include "Class_per_uc.hpp"
#include "Class.hpp"
#import <set>
#include <list>
#include <map>
#include "change.hpp"

class Menu {
private:
    std::list<Class> classes; //classes_per_uc, Weekday, StartHour, Duration, Type
    std::set<Class_per_uc> classes_per_uc;// UcCode, ClassCode
    std::set<Student_class> students_classes;//StudentCode, Name, Classes_per_uc
    std::map<int,Change> change_log;
public:
    Menu(std::list<Class> &classes, std::set<Class_per_uc> &classes_per_uc, std::set<Student_class> &students_classes, std::map<int,Change> &change_log);

    void run();
    std::string homepage();

    const std::list<Class> &getClasses() const;

    void setClasses(const std::list<Class> &classes);

    const std::set<Class_per_uc> &getClassesPerUc() const;

    void setClassesPerUc(const std::set<Class_per_uc> &classesPerUc);

    const std::set<Student_class> &getStudentsClasses() const;

    void setStudentsClasses(const std::set<Student_class> &studentsClasses);
};




#endif //PROJETO_MENU_HPP
