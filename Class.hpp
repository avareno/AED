//
// Created by avareno on 10/22/23.
//

#ifndef PROJETO_CLASS_HPP
#define PROJETO_CLASS_HPP


#include <string>
#include "Class_per_uc.hpp"

class Class {
private:
    Class_per_uc cl;
    std::string Weekday;
    std::string StartHour;
    std::string Duration;
    std::string Type;
public:
    Class();

    const Class_per_uc &getCl() const;

    void setCl(const Class_per_uc &cl);

    const std::string &getWeekday() const;

    void setWeekday(const std::string &weekday);

    const std::string &getStartHour() const;

    void setStartHour(const std::string &startHour);

    const std::string &getDuration() const;

    void setDuration(const std::string &duration);

    const std::string &getType() const;

    void setType(const std::string &type);

    bool operator<(const Class &rhs) const;

    bool operator>(const Class &rhs) const;

    bool operator<=(const Class &rhs) const;

    bool operator>=(const Class &rhs) const;


};


#endif //PROJETO_CLASS_HPP
