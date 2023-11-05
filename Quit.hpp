//
// Created by Gabriel Braga on 04/11/2023.
//

#ifndef PROJETO_QUIT_HPP
#define PROJETO_QUIT_HPP

#include "Class_per_uc.hpp"
#include "Student_class.hpp"
#include "Class.hpp"
#include "change.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <queue>
#include <list>

class Quit {
public:
    Quit(std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class>&classes, std::queue<Change> &change_log);
};
#endif //PROJETO_QUIT_HPP
