//
// Created by avareno on 10/22/23.
//

#include "Student_class.hpp"


const std::string &Student_class::getStudentCode() const {
    return StudentCode;
}

const std::string &Student_class::getStudentName() const {
    return StudentName;
}

const std::string &Student_class::getUcCode() const {
    return UcCode;
}

const std::string &Student_class::getClassCode() const {
    return ClassCode;
}

bool Student_class::operator<(const Student_class &rhs) const {
    if (StudentCode < rhs.StudentCode)
        return true;
    else if(StudentCode > rhs.StudentCode)
        return false;
    else{
        if (UcCode < rhs.UcCode)
            return true;
        if (rhs.UcCode < UcCode)
            return false;
        return ClassCode < rhs.ClassCode;
    }
}



void Student_class::setClassCode(const std::string &classCode) {
    ClassCode = classCode;
}

void Student_class::setUcCode(const std::string &ucCode) {
    UcCode = ucCode;
}

void Student_class::setStudentName(const std::string &studentName) {
    StudentName = studentName;
}

void Student_class::setStudentCode(const std::string &studentCode) {
    StudentCode = studentCode;
}
