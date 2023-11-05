#ifndef PROJETO_CHANGE_HPP
#define PROJETO_CHANGE_HPP

#include <string>
#include "Class_per_uc.hpp"
/**
 * @file Change.hpp
 * @brief A class that stores the data involved in a request for storing in the change log.
 */

/**
* @brief A class that stores the data involved in a request for storing in the change log.
*/
class Change {
private:
    std::string op;
    std::string snum;
    Class_per_uc prev;
    Class_per_uc post;

public:

    Change();

    Change(std::string op, std::string snum, Class_per_uc prev, Class_per_uc post);

    const Class_per_uc &getPrevCl() const;

    void setPrevCl(const Class_per_uc &cl);

    const Class_per_uc &getPostCl() const;

    void setPostCl(const Class_per_uc &cl);

    const std::string &getOp() const;

    void setOp(const std::string &operation);

    const std::string &getSnum() const;

    void setSnum(const std::string &snum);

};


#endif //PROJETO_CHANGE_HPP