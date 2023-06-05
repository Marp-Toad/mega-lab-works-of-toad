﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class MyVector 
{
private:
    vector<T> data;
public:
    MyVector() {}

    void fill(int size) 
    {
        for (int i = 0; i < size; ++i)
        {
            T value;
            cout << "Enter element " << i + 1 << ": ";
            cin >> value;
            data.push_back(value);
        }
    }

    void addMinToPosition(int pos) 
    {
        T minElement = *min_element(data.begin(), data.end());
        data.insert(data.begin() + pos, minElement);
    }

    void removeElementsLessThan(T value)
    {
        data.erase(remove_if(data.begin(), data.end(), [&](T x) { return x < value; }), data.end());
    }

    void print()
    {
        for (const T& x : data)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() 
{
    MyVector<int> myVector;
    myVector.fill(5);
    myVector.print();

    myVector.addMinToPosition(2);
    myVector.print();

    myVector.removeElementsLessThan(3);
    myVector.print();

    return 0;
}