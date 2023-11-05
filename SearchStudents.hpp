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

/**
 * @class SearchStudents
 * @brief Provides functionality to search for students and their classes.
 */

class SearchStudents : Search {
private:
    int i_=0;// used to check if we run() again the menu

public:
    /**
     * Constructor for SearchStudents.
     * @param students_classes A set of Student_class objects.
     * @param classes A list of Class objects.
     */
    SearchStudents(const std::set<Student_class> &students_classes, const std::list<Class> &classes);

    /**
     * Get a student's code from the user.
     * @return The student's code.
     */
    std::string get_num() override;//get num from the student

    /**
     * Navigate back to the previous menu.
     */
    void back() override;
};


#endif //PROJETO_SEARCHSTUDENTS_HPP
