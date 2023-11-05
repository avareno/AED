/**
 * @file SearchClass.hpp
 * @brief Declaration of the abstract Search class.
 */

#ifndef PROJETO_SEARCHCLASS_HPP
#define PROJETO_SEARCHCLASS_HPP

#include <string>

/**
 * @class Search
 * @brief An abstract class for searching classes.
 */
class Search {
public:
    /**
     * @brief Get input from the user.
     * @return A string containing the user's input.
     */
    virtual std::string get_num() = 0;

    /**
     * @brief Navigate back or return to a previous menu.
     */
    virtual void back() = 0;
};

#endif //PROJETO_SEARCHCLASS_HPP