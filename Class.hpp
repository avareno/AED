#ifndef PROJETO_CLASS_HPP
#define PROJETO_CLASS_HPP


#include <string>
#include "Class_per_uc.hpp"

/**@file
 * @brief A class that holds the data from each individual class , having there respective Class_per_uc, "Weekday", "StartHour", "Duration", "Type"
 */

class Class {
private:
    Class_per_uc cl;
    std::string Weekday;
    std::string StartHour;
    std::string Duration;
    std::string Type;
    int max_cap_;
public:
    Class();

    Class(std::string Duration, std::string StartHour, std::string Type, std::string Weekdays, std::string UcCode, std::string ClassCode);

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

    int getMaxCap() const;

    void setMaxCap(int maxCap);


};


#endif //PROJETO_CLASS_HPP
