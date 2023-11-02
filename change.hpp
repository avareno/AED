
#ifndef PROJETO_CHANGE_HPP
#define PROJETO_CHANGE_HPP

#include <string>
#include "Class_per_uc.hpp"

class Change {
private:
    std::string op;
    Class_per_uc prev;
    Class_per_uc post;

public:

    Change(std::string op, Class_per_uc prev, Class_per_uc post);

    const Class_per_uc &getPrevCl() const;

    void setPrevCl(const Class_per_uc &cl);

    const Class_per_uc &getPostCl() const;

    void setPostCl(const Class_per_uc &cl);

    const std::string &getOp() const;

    void setOp(const std::string &operation);

};


#endif //PROJETO_CHANGE_HPP