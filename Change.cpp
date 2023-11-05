#include "Change.hpp"
using namespace std;

/**
 * @file Change.cpp
 * @brief Implementation of Change.hpp
 */

/**
* @brief Implementation of Change.hpp
*/

Change::Change() {
    this->op = "";
    this->snum = "";
    this->prev = Class_per_uc();
    this->post = Class_per_uc();
}

Change::Change(string op, string snum, Class_per_uc prev, Class_per_uc post) {
    this->op = op;
    this->snum = snum;
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

const std::string &Change::getSnum() const {
    return snum;
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

void Change::setSnum(const std::string &student_num) {
    snum = student_num;
}
