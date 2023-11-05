/**
 * @file Class_per_uc.cpp
 * @brief Implementation of the Class_per_uc class for managing classes associated with a specific UC.
 */

#include "Class_per_uc.hpp"

/**
 * @brief Default constructor for the Class_per_uc class.
 */
Class_per_uc::Class_per_uc() {
    this->UcCode = "";
    this->ClassCode = "";
    this->size = 0;
}

/**
 * @brief Parameterized constructor for the Class_per_uc class.
 *
 * @param UcCode The code of the UC.
 * @param ClassCode The code of the class.
 */
Class_per_uc::Class_per_uc(std::string UcCode, std::string ClassCode) {
    this->UcCode = UcCode;
    this->ClassCode = ClassCode;
    this->size = 0;
}

/**
 * @brief Get the UC code associated with the class.
 *
 * @return The UC code.
 */
const std::string &Class_per_uc::getUcCode() const {
    return UcCode;
}

/**
 * @brief Get the class code.
 *
 * @return The class code.
 */
const std::string &Class_per_uc::getClassCode() const {
    return ClassCode;
}

/**
 * @brief Set the UC code for the class.
 *
 * @param ucCode The UC code to set.
 */
void Class_per_uc::setUcCode(const std::string &ucCode) {
    UcCode = ucCode;
}

/**
 * @brief Compare if one Class_per_uc is less than another.
 *
 * @param rhs The right-hand side Class_per_uc object to compare.
 * @return True if this Class_per_uc is less than the right-hand side, false otherwise.
 */
bool Class_per_uc::operator<(const Class_per_uc &rhs) const {
    if (UcCode < rhs.UcCode)
        return true;
    if (rhs.UcCode < UcCode)
        return false;
    return ClassCode < rhs.ClassCode;
}

/**
 * @brief Compare if one Class_per_uc is greater than another.
 *
 * @param rhs The right-hand side Class_per_uc object to compare.
 * @return True if this Class_per_uc is greater than the right-hand side, false otherwise.
 */
bool Class_per_uc::operator>(const Class_per_uc &rhs) const {
    return rhs < *this;
}

/**
 * @brief Compare if one Class_per_uc is less than or equal to another.
 *
 * @param rhs The right-hand side Class_per_uc object to compare.
 * @return True if this Class_per_uc is less than or equal to the right-hand side, false otherwise.
 */
bool Class_per_uc::operator<=(const Class_per_uc &rhs) const {
    return !(rhs < *this);
}

/**
 * @brief Compare if one Class_per_uc is greater than or equal to another.
 *
 * @param rhs The right-hand side Class_per_uc object to compare.
 * @return True if this Class-per-uc is greater than or equal to the right-hand side, false otherwise.
 */
bool Class_per_uc::operator>=(const Class_per_uc &rhs) const {
    return !(*this < rhs);
}

/**
 * @brief Set the class code for the Class_per_uc.
 *
 * @param classCode The class code to set.
 */
void Class_per_uc::setClassCode(const std::string &classCode) {
    ClassCode = classCode;
}

/**
 * @brief Compare if two Class_per_uc objects are equal.
 *
 * @param rhs The right-hand side Class_per_uc object to compare.
 * @return True if the two Class_per_uc objects are equal, false otherwise.
 */
bool Class_per_uc::operator==(const Class_per_uc &rhs) const {
    return UcCode == rhs.UcCode &&
           ClassCode == rhs.ClassCode;
}

/**
 * @brief Compare if two Class_per_uc objects are not equal.
 *
 * @param rhs The right-hand side Class_per_uc object to compare.
 * @return True if the two Class_per_uc objects are not equal, false otherwise.
 */
bool Class_per_uc::operator!=(const Class_per_uc &rhs) const {
    return !(rhs == *this);
}

/**
 * @brief Get the size associated with the Class_per_uc.
 *
 * @return The size.
 */
int Class_per_uc::getSize() const {
    return size;
}

/**
 * @brief Set the size for the Class_per_uc.
 *
 * @param size The size to set.
 */
void Class_per_uc::setSize(int size) {
    Class_per_uc::size = size;
}