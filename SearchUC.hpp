/**
 * @file SearchUC.hpp
 * @brief SearchUC class declaration.
 */

#ifndef SEARCHUC_HPP
#define SEARCHUC_HPP

#include "Class_per_uc.hpp"
#include "Class.hpp"
#include <set>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

/**
 * @class SearchUC
 * @brief A class for searching UCs and associated classes.
 */
class SearchUC {
public:
    /**
     * @brief Constructor for SearchUC.
     * @param classes_per_uc A set of Class_per_uc objects.
     * @param classes A list of Class objects.
     */
    SearchUC(const std::set<Class_per_uc> classes_per_uc, const std::list<Class>& classes);

    /**
     * @brief Navigate back to a previous state.
     */
    void back();

    /**
     * @brief Get a UcCode from user input.
     * @return The entered UcCode as a string.
     */
    std::string get_num();

private:
    int i_=0; // flag for return


};

#endif // SEARCHUC_HPP
