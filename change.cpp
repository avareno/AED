//
// Created by Gabriel Braga on 02/11/2023.
//

#include "change.hpp"
using namespace std;

Change::Change(std::string op, Class_per_uc prev, Class_per_uc post) {
    this->op = op;
    this->prev = prev;
    this->post = post;
}

const Class_per_uc &Change::getPrevCl() const {
    return prev;
}

const Class_per_uc &Change::getPostCl() const {
    return post;
}

const std::string &Change::getOp() const {
    return op;
}

void Change::setPrevCl(const Class_per_uc &cl) {
    prev = cl;
}

void Change::setPostCl(const Class_per_uc &cl) {
    post = cl;
}

void Change::setOp(const std::string &operation) {
    op = operation;
}