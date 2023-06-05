﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MyType 
{
    int value;

    MyType(int value) : value(value) {}

    bool operator<(const MyType& other) const 
    {
        return value < other.value;
    }

    bool operator>(const MyType& other) const
    {
        return value > other.value;
    }

    friend ostream& operator<<(ostream& os, const MyType& obj) 
    {
        os << obj.value;
        return os;
    }
};

double getAverage(const vector<MyType>& data)
{
    double sum = 0;
    for (const MyType& x : data) 
    {
        sum += x.value;
    }
    return sum / data.size();
}

void removeElementsGreaterThanAverage(vector<MyType>& data)
{
    double average = getAverage(data);
    data.erase(remove_if(data.begin(), data.end(), [&](const MyType& x) { return x > average; }), data.end());
}

int main()
{
    vector<MyType> myVector;
    myVector.push_back(MyType(5));
    myVector.push_back(MyType(3));
    myVector.push_back(MyType(8));
    myVector.push_back(MyType(4));
    myVector.push_back(MyType(6));

    cout << "Original vector: ";
    for (const MyType& x : myVector) 
    {
        cout << x << " ";
    }
    cout << endl;

    removeElementsGreaterThanAverage(myVector);

    cout << "Modified vector: ";
    for (const MyType& x : myVector)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}