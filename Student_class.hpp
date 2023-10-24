//
// Created by avareno on 10/22/23.
//

#ifndef PROJETO_STUDENT_CLASS_HPP
#define PROJETO_STUDENT_CLASS_HPP


#include <string>

class Student_class {
private:
    std::string StudentCode;
    std::string StudentName;
    std::string UcCode;
    std::string ClassCode;
public:
    const std::string &getStudentCode() const;

    void setStudentCode(const std::string &studentCode);

    const std::string &getStudentName() const;

    void setStudentName(const std::string &studentName);

    const std::string &getUcCode() const;

    void setUcCode(const std::string &ucCode);

    const std::string &getClassCode() const;

    void setClassCode(const std::string &classCode);

    bool operator<(const Student_class &rhs) const;

    bool operator>(const Student_class &rhs) const;

    bool operator<=(const Student_class &rhs) const;

    bool operator>=(const Student_class &rhs) const;




};


#endif //PROJETO_STUDENT_CLASS_HPP
