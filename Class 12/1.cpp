﻿#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<float> mySet;

void addElement(float element, int position)
{
    auto it = mySet.begin();
    for (int i = 0; i < position; i++)
    {
        it++;
    }
    mySet.insert(it, element);
}

float findAverage()
{
    float sum = 0;
    for (auto it = mySet.begin(); it != mySet.end(); it++)
    {
        sum += *it;
    }
    return sum / mySet.size();
}

vector<float> multiplyElementsByMax()
{
    float maxElement = *mySet.rbegin();
    vector<float> result;
    for (auto it = mySet.begin(); it != mySet.end(); it++)
    {
        result.push_back(*it * maxElement);
    }
    return result;
}

int main() 
{
    mySet.insert(1.2);
    mySet.insert(2.3);
    mySet.insert(3.4);
    mySet.insert(4.5);

    for (auto it = mySet.begin(); it != mySet.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    float minElement = *mySet.begin();
    addElement(minElement, 2);

    for (auto it = mySet.begin(); it != mySet.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    float average = findAverage();
    auto it = mySet.begin();
    while (it != mySet.end()) 
    {
        if (*it > average)
        {
            it = mySet.erase(it);
        }
        else 
        {
            it++;
        }
    }

    for (auto it = mySet.begin(); it != mySet.end(); it++) 
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<float> newSet = multiplyElementsByMax();

    for (auto it = newSet.begin(); it != newSet.end(); it++) 
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}