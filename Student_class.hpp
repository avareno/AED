//
// Created by avareno on 10/22/23.
//

#ifndef PROJETO_STUDENT_CLASS_HPP
#define PROJETO_STUDENT_CLASS_HPP


#include <string>
#include "Class_per_uc.hpp"

class Student_class {
private:
    std::string StudentCode;
    std::string StudentName;
    Class_per_uc cl_;
public:
    Student_class();

    Student_class(std::string StudentCode, std::string StudentName, std::string UcCode, std::string ClassCode);

    public:
    const std::string &getStudentCode() const;

    void setStudentCode(const std::string &studentCode);

    const std::string &getStudentName() const;

    void setStudentName(const std::string &studentName);

    const std::string &getUcCode() const;

    void setUcCode(const std::string &ucCode);

    const std::string &getClassCode() const;

    void setClassCode(const std::string &classCode);

        const Class_per_uc &getCl() const;

    void setCl(const Class_per_uc &cl);

    bool operator<(const Student_class &rhs) const;

    bool operator>(const Student_class &rhs) const;

    bool operator<=(const Student_class &rhs) const;

    bool operator>=(const Student_class &rhs) const;

    bool operator==(const Student_class &rhs) const;

    bool operator!=(const Student_class &rhs) const;

};


#endif //PROJETO_STUDENT_CLASS_HPP
