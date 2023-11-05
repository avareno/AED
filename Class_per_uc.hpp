//
// Created by avareno on 10/20/23.
//

#ifndef PROJETO_CLASS_PER_UC_HPP
#define PROJETO_CLASS_PER_UC_HPP


#include <string>

class Class_per_uc {
private:
    std::string UcCode;
    int size;
public:
    int getSize() const;

    void setSize(int size);

public:
    bool operator==(const Class_per_uc &rhs) const;

    bool operator!=(const Class_per_uc &rhs) const;

private:
    std::string ClassCode;
public:

    const static int max_size = 26;

    Class_per_uc();

    Class_per_uc(std::string UcCode, std::string ClassCode);

    const std::string &getClassCode() const;

    const std::string &getUcCode() const;

    void setUcCode(const std::string &ucCode);

    void setClassCode(const std::string &classCode);

    bool operator<(const Class_per_uc &rhs) const;

    bool operator>(const Class_per_uc &rhs) const;

    bool operator<=(const Class_per_uc &rhs) const;

    bool operator>=(const Class_per_uc &rhs) const;

};


#endif //PROJETO_CLASS_PER_UC_HPP
