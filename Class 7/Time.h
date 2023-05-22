#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}
    Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {} 
    ~Time() {}

    Time& operator=(const Time& other) 
    {
        if (this != &other) {
            hours = other.hours;
            minutes = other.minutes;
            seconds = other.seconds;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t) 
    {
        os << t.hours << ":" << t.minutes << ":" << t.seconds;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Time& t) 
    {
        is >> t.hours >> t.minutes >> t.seconds;
        return is;
    }

    Time operator*(const Time& other) const 
    { 
        int total_seconds = hours * 3600 + minutes * 60 + seconds; 
        int other_total_seconds = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int result_total_seconds = total_seconds * other_total_seconds;
        int result_hours = result_total_seconds / 3600;
        int result_minutes = (result_total_seconds % 3600) / 60;
        int result_seconds = result_total_seconds % 60;
        return Time(result_hours, result_minutes, result_seconds);
    }
};