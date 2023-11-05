/**
 * @file Student_class.hpp
 * @brief Student_class class declaration.
 */

#ifndef STUDENT_CLASS_HPP
#define STUDENT_CLASS_HPP

#include <string>
#include "Class_per_uc.hpp"

/**
 * @class Student_class
 * @brief A class for representing student data and their associated class.
 */
class Student_class {
private:
    std::string StudentCode;
    std::string StudentName;
    Class_per_uc cl_;

public:
    /**
     * @brief Default constructor for Student_class.
     * Initializes class members with default values.
     */
    Student_class();

    /**
     * @brief Parameterized constructor for Student_class.
     * Initializes class members with the provided values.
     * @param StudentCode The student's code.
     * @param StudentName The student's name.
     * @param UcCode The code of the associated course unit (UC).
     * @param ClassCode The code of the associated class.
     */
    Student_class(std::string StudentCode, std::string StudentName, std::string UcCode, std::string ClassCode);

    /**
     * @brief Get the code of the associated student.
     * @return The student's code as a string.
     */
    const std::string &getStudentCode() const;

    /**
     * @brief Set the code of the associated student.
     * @param studentCode The student's code.
     */
    void setStudentCode(const std::string &studentCode);

    /**
     * @brief Get the name of the associated student.
     * @return The student's name as a string.
     */
    const std::string &getStudentName() const;

    /**
     * @brief Set the name of the associated student.
     * @param studentName The student's name.
     */
    void setStudentName(const std::string &studentName);

    /**
     * @brief Get the associated class for the student.
     * @return The associated class as a Class_per_uc object.
     */
    const Class_per_uc &getCl() const;

    /**
     * @brief Set the associated class for the student.
     * @param cl The associated class as a Class_per_uc object.
     */
    void setCl(const Class_per_uc &cl);

    /**
     * @brief Compare two Student_class objects for less than.
     * @param rhs The right-hand side Student_class object.
     * @return True if this object is less than rhs, false otherwise.
     */
    bool operator<(const Student_class &rhs) const;

    /**
     * @brief Compare two Student_class objects for greater than.
     * @param rhs The right-hand side Student_class object.
     * @return True if this object is greater than rhs, false otherwise.
     */
    bool operator>(const Student_class &rhs) const;

    /**
     * @brief Compare two Student_class objects for less than or equal to.
     * @param rhs The right-hand side Student_class object.
     * @return True if this object is less than or equal to rhs, false otherwise.
     */
    bool operator<=(const Student_class &rhs) const;

    /**
     * @brief Compare two Student_class objects for greater than or equal to.
     * @param rhs The right-hand side Student_class object.
     * @return True if this object is greater than or equal to rhs, false otherwise.
     */
    bool operator>=(const Student_class &rhs) const;

    /**
     * @brief Compare two Student_class objects for equality.
     * @param rhs The right-hand side Student_class object.
     * @return True if this object is equal to rhs, false otherwise.
     */
    bool operator==(const Student_class &rhs) const;

    /**
     * @brief Compare two Student_class objects for inequality.
     * @param rhs The right-hand side Student_class object.
     * @return True if this object is not equal to rhs, false otherwise.
     */
    bool operator!=(const Student_class &rhs) const;

};

#endif // STUDENT_CLASS_HPP