//
// Created by avareno on 10/22/23.
//

/**
 * @file Student_class.cpp
 * @brief Implementation of the Student_class class.
 */

#include "Student_class.hpp"
using namespace std;

/**
 * @brief Default constructor for Student_class.
 *
 * Initializes class members with default values.
 */
Student_class::Student_class() {
    this->cl_.setUcCode("");
    this->cl_.setClassCode("");
    this->StudentCode="";
    this->StudentName="";
}

/**
 * @brief Parameterized constructor for Student_class.
 *
 * Initializes class members with the provided values.
 * @param StudentCode The student's code.
 * @param StudentName The student's name.
 * @param UcCode The code of the associated course unit (UC).
 * @param ClassCode The code of the associated class.
 */
Student_class::Student_class(string StudentCode, string StudentName, string UcCode, string ClassCode)
{
    this->StudentName=StudentName;
    this->StudentCode=StudentCode;
    this->cl_.setClassCode(ClassCode);
    this->cl_.setUcCode(UcCode);

}


/**
 * @brief Get the code of the associated student.
 * @return The student's code as a string.
 */
const std::string &Student_class::getStudentCode() const {
    return StudentCode;
}

/**
 * @brief Get the name of the associated student.
 * @return The student's name as a string.
 */
const std::string &Student_class::getStudentName() const {
    return StudentName;
}

/**
 * @brief Set the name of the associated student.
 * @param studentName The student's name.
 */
void Student_class::setStudentName(const std::string &studentName) {
    StudentName = studentName;
}

/**
 * @brief Set the code of the associated student.
 * @param studentCode The student's code.
 */
void Student_class::setStudentCode(const std::string &studentCode) {
    StudentCode = studentCode;
}

/**
 * @brief Get the associated class for the student.
 * @return The associated class as a Class_per_uc object.
 */
const Class_per_uc &Student_class::getCl() const {
    return this->cl_;
}

/**
 * @brief Set the associated class for the student.
 * @param cl The associated class as a Class_per_uc object.
 */
void Student_class::setCl(const Class_per_uc &cl) {
    this->cl_ = cl;
}

/**
 * @brief Compare two Student_class objects for less than.
 * @param rhs The right-hand side Student_class object.
 * @return True if this object is less than rhs, false otherwise.
 */
bool Student_class::operator<(const Student_class &rhs) const {
    if (StudentCode < rhs.StudentCode)
        return true;
    if (rhs.StudentCode < StudentCode)
        return false;
    if (StudentName < rhs.StudentName)
        return true;
    if (rhs.StudentName < StudentName)
        return false;
    return cl_ < rhs.cl_;
}

/**
 * @brief Compare two Student_class objects for greater than.
 * @param rhs The right-hand side Student_class object.
 * @return True if this object is greater than rhs, false otherwise.
 */
bool Student_class::operator>(const Student_class &rhs) const {
    return rhs < *this;
}

/**
 * @brief Compare two Student_class objects for less than or equal to.
 * @param rhs The right-hand side Student_class object.
 * @return True if this object is less than or equal to rhs, false otherwise.
 */
bool Student_class::operator<=(const Student_class &rhs) const {
    return !(rhs < *this);
}

/**
 * @brief Compare two Student_class objects for greater than or equal to.
 * @param rhs The right-hand side Student_class object.
 * @return True if this object is greater than or equal to rhs, false otherwise.
 */
bool Student_class::operator>=(const Student_class &rhs) const {
    return !(*this < rhs);
}

/**
 * @brief Compare two Student_class objects for equality.
 * @param rhs The right-hand side Student_class object.
 * @return True if this object is equal to rhs, false otherwise.
 */
bool Student_class::operator==(const Student_class &rhs) const {
    return StudentCode == rhs.StudentCode &&
           StudentName == rhs.StudentName &&
           cl_ == rhs.cl_;
}

/**
 * @brief Compare two Student_class objects for inequality.
 * @param rhs The right-hand side Student_class object.
 * @return True if this object is not equal to rhs, false otherwise.
 */
bool Student_class::operator!=(const Student_class &rhs) const {
    return !(rhs == *this);
}
