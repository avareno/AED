//
// Created by avareno on 10/22/23.
//

#include "Student_class.hpp"
using namespace std;

Student_class::Student_class() {
    this->cl=Class_per_uc();
    this->StudentCode="";
    this->StudentName="";
}

const Class_per_uc &Student_class::getCl() const {
    return cl;
}

void Student_class::setCl(const Class_per_uc &cl) {
    Student_class::cl = cl;
}

Student_class::Student_class(string StudentCode, string StudentName, string UcCode, string ClassCode)
{
    this->StudentName=StudentName;
    this->StudentCode=StudentCode;
    this->cl.setClassCode(ClassCode);
    this->cl.setUcCode(UcCode);

}


const std::string &Student_class::getStudentCode() const {
    return StudentCode;
}

const std::string &Student_class::getStudentName() const {
    return StudentName;
}



void Student_class::setStudentName(const std::string &studentName) {
    StudentName = studentName;
}

void Student_class::setStudentCode(const std::string &studentCode) {
    StudentCode = studentCode;
}

bool Student_class::operator<(const Student_class &rhs) const {
    if (StudentCode < rhs.StudentCode)
        return true;
    if (rhs.StudentCode < StudentCode)
        return false;
    if (StudentName < rhs.StudentName)
        return true;
    if (rhs.StudentName < StudentName)
        return false;
    return cl < rhs.cl;
}

bool Student_class::operator>(const Student_class &rhs) const {
    return rhs < *this;
}

bool Student_class::operator<=(const Student_class &rhs) const {
    return !(rhs < *this);
}

bool Student_class::operator>=(const Student_class &rhs) const {
    return !(*this < rhs);
}

bool Student_class::operator==(const Student_class &rhs) const {
    return StudentCode == rhs.StudentCode &&
           StudentName == rhs.StudentName &&
           cl == rhs.cl;
}

bool Student_class::operator!=(const Student_class &rhs) const {
    return !(rhs == *this);
}
