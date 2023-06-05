#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void add_remove_list()
{
    list<float> myList = { 1.5f, 2.5f, 3.5f, 4.5f, 5.5f };
    myList.push_front(0.5f);
    myList.push_back(6.5f);
    myList.remove(3.5f);

    for (auto it = myList.begin(); it != myList.end(); it++) 
    {
        cout << *it << " ";
    }
    cout << endl;

    auto min_it = min_element(myList.begin(), myList.end());
    myList.insert(next(myList.begin()), *min_it);
    float sum = 0.0f;
    for (auto it = myList.begin(); it != myList.end(); it++) 
    {
        sum += *it;
    }
    float average = sum / myList.size();

    for (auto it = myList.begin(); it != myList.end();)
    {
        if (*it > average)
        {
            it = myList.erase(it);
        }
        else
        {
            it++;
        }
    }

    float max_val = *max_element(myList.begin(), myList.end());
    for (auto& x : myList) 
    {
        x *= max_val;
    }

    for (auto it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    add_remove_list();
    return 0;
}