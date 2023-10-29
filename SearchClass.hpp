//
// Created by avareno on 10/24/23.
//

#ifndef PROJETO_SEARCHCLASS_HPP
#define PROJETO_SEARCHCLASS_HPP


#include <string>

class Search {//Abstract Class
public:
    virtual std::string get_num() = 0;
    virtual void back() = 0;
};


#endif //PROJETO_SEARCHCLASS_HPP
