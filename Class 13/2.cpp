#include <iostream>
#include <vector>
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
};

int main()
{
    vector<Time> times = { Time(10, 30), Time(9, 0), Time(12, 15), Time(8, 45) };

    auto min_time = min_element(times.begin(), times.end(), [](const Time& a, const Time& b)
        {
        return a.hours < b.hours || (a.hours == b.hours && a.minutes < b.minutes);
        });

    times.push_back(*min_time);

    int key_hours = 12;
    int key_minutes = 15;

    auto it = find_if(times.begin(), times.end(), [key_hours, key_minutes](const Time& t) 
        {
        return t.hours == key_hours && t.minutes == key_minutes;
        });

    if (it != times.end())
    {
        times.erase(it);
    }

    auto minmax = minmax_element(times.begin(), times.end(), [](const Time& a, const Time& b) 
        {
        return a.hours < b.hours || (a.hours == b.hours && a.minutes < b.minutes);
        });

    int min_hours = minmax.first->hours;
    int min_minutes = minmax.first->minutes;
    int max_hours = minmax.second->hours;
    int max_minutes = minmax.second->minutes;

    for_each(times.begin(), times.end(), [min_hours, min_minutes, max_hours, max_minutes](Time& t)
        {
        t.hours += min_hours + max_hours;
        t.minutes += min_minutes + max_minutes;
        });

    for (const auto& t : times) 
    {
        t.print();
    }

    return 0;
}