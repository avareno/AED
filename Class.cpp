//
// Created by avareno on 10/22/23.
//

#include "Class.hpp"



const std::string &Class::getWeekday() const {
    return Weekday;
}

const std::string &Class::getStartHour() const {
    return StartHour;
}

const std::string &Class::getDuration() const {
    return Duration;
}

const std::string &Class::getType() const {
    return Type;
}

void Class::setType(const std::string &type) {
    Type = type;
}

void Class::setDuration(const std::string &duration) {
    Duration = duration;
}

void Class::setStartHour(const std::string &startHour) {
    StartHour = startHour;
}

bool Class::operator<(const Class &rhs) const {
    return cl < rhs.cl;
}

bool Class::operator>(const Class &rhs) const {
    return rhs < *this;
}

bool Class::operator<=(const Class &rhs) const {
    return !(rhs < *this);
}

bool Class::operator>=(const Class &rhs) const {
    return !(*this < rhs);
}

void Class::setWeekday(const std::string &weekday) {
    Weekday = weekday;
}



Class::Class() {
    cl = Class_per_uc();
}

const Class_per_uc &Class::getCl() const {
    return cl;
}

void Class::setCl(const Class_per_uc &cl) {
    Class::cl = cl;
}
