/**
 * @file Quit.hpp
 * @brief Declaration of the Quit class for performing exit operations.
 */

#ifndef PROJETO_QUIT_HPP
#define PROJETO_QUIT_HPP

#include "Class_per_uc.hpp"
#include "Student_class.hpp"
#include "Class.hpp"
#include "Change.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <queue>
#include <list>

/**
 * @class Quit
 * @brief A class for performing exit operations.
 */
class Quit {
public:
    /**
     * @brief Construct a Quit object and perform exit operations.
     * @param students_classes A reference to the set of student classes.
     * @param classes_per_uc A reference to the set of classes per UC.
     * @param classes A reference to the list of classes.
     * @param change_log A reference to the queue of changes.
     */
    Quit(std::set<Student_class> &students_classes, std::set<Class_per_uc> &classes_per_uc, std::list<Class> &classes, std::queue<Change> &change_log);
};

#endif //PROJETO_QUIT_HPP
