/**
 * @file Class_per_uc.cpp
 * @brief Implementation of the Class_per_uc class for managing classes associated with a specific UC.
 */


#include "Class_per_uc.hpp"

Class_per_uc::Class_per_uc() {
    this->UcCode="";
    this->ClassCode="";
    this->size = 0;
}

Class_per_uc::Class_per_uc(std::string UcCode, std::string ClassCode) {
    this->UcCode=UcCode;
    this->ClassCode=ClassCode;
    this->size = 0;
};

const std::string &Class_per_uc::getUcCode() const {
    return UcCode;
}


const std::string &Class_per_uc::getClassCode() const {
    return ClassCode;
}

void Class_per_uc::setUcCode(const std::string &ucCode) {
    UcCode = ucCode;
}

bool Class_per_uc::operator<(const Class_per_uc &rhs) const {
    if (UcCode < rhs.UcCode)
        return true;
    if (rhs.UcCode < UcCode)
        return false;
    return ClassCode < rhs.ClassCode;
}

bool Class_per_uc::operator>(const Class_per_uc &rhs) const {
    return rhs < *this;
}

bool Class_per_uc::operator<=(const Class_per_uc &rhs) const {
    return !(rhs < *this);
}

bool Class_per_uc::operator>=(const Class_per_uc &rhs) const {
    return !(*this < rhs);
}

void Class_per_uc::setClassCode(const std::string &classCode) {
    ClassCode = classCode;
}

bool Class_per_uc::operator==(const Class_per_uc &rhs) const {
    return UcCode == rhs.UcCode &&
           ClassCode == rhs.ClassCode;
}

bool Class_per_uc::operator!=(const Class_per_uc &rhs) const {
    return !(rhs == *this);
}

int Class_per_uc::getSize() const {
    return size;
}

void Class_per_uc::setSize(int size) {
    Class_per_uc::size = size;
}
