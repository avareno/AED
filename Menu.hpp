//
// Created by avareno on 10/24/23.
//

#ifndef PROJETO_MENU_HPP
#define PROJETO_MENU_HPP


#include "Student_class.hpp"
#include "Class_per_uc.hpp"
#include "Class.hpp"
#import <set>
#import <map>
#include <list>
#include <queue>
#include "Change.hpp"

/**
 * @brief A class responsible for receiving all the data from all the csv files and redirect the user to the other classes according to their input
 */

class Menu {
private:

    std::list<Class> classes; //classes_per_uc, Weekday, StartHour, Duration, Type
    std::set<Class_per_uc> classes_per_uc;// UcCode, ClassCode
    std::set<Student_class> students_classes;//StudentCode, Name, Classes_per_uc
    std::queue<Change> change_log;
public:
    Menu(std::list<Class> &classes, std::set<Class_per_uc> &classes_per_uc, std::set<Student_class> &students_classes, std::queue<Change> &change_log);

    void ChangeLog(std::queue<Change> change_log, std::map<int,Change> &temp_change);

    void run();

    std::string homepage();

    const std::list<Class> &getClasses() const;

    void setClasses(const std::list<Class> &classes);

    const std::set<Class_per_uc> &getClassesPerUc() const;

    void setClassesPerUc(const std::set<Class_per_uc> &classesPerUc);

    const std::set<Student_class> &getStudentsClasses() const;

    void setStudentsClasses(const std::set<Student_class> &studentsClasses);

    static void Undo(Change change,std::set<Student_class> &students_classes,std::list<Class> &classes, std::queue<Change> &change_log, std::set<Class_per_uc> &classes_per_uc);
};




#endif //PROJETO_MENU_HPP
