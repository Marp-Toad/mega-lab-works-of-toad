#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct Time 
{
    int hours;
    int minutes;

    Time(int h, int m) : hours(h), minutes(m) {}

    void print() const
    {
        cout << hours << ":" << minutes << endl;
    }

    bool operator<(const Time& other) const
    {
        return hours < other.hours || (hours == other.hours && minutes < other.minutes);
    }
};

int main()
{
    set<Time> times = { Time(10, 30), Time(9, 0), Time(12, 15), Time(8, 45) };

    auto min_time = *min_element(times.begin(), times.end());

    times.insert(min_time);

    int key_hours = 12;
    int key_minutes = 15;

    auto it =find_if(times.begin(), times.end(), [key_hours, key_minutes](const Time& t)
        {
        return t.hours == key_hours && t.minutes == key_minutes;
        });

    if (it != times.end())
    {
        times.erase(it);
    }

    auto minmax = minmax_element(times.begin(), times.end());

    int min_hours = minmax.first->hours;
    int min_minutes = minmax.first->minutes;
    int max_hours = minmax.second->hours;
    int max_minutes = minmax.second->minutes;

    for_each(times.begin(), times.end(), [min_hours, min_minutes, max_hours, max_minutes](const Time& t)
        {
        const_cast<Time&>(t).hours += min_hours + max_hours;
        const_cast<Time&>(t).minutes += min_minutes + max_minutes;
        });

    for (const auto& t : times)
    {
        t.print();
    }

    return 0;
}