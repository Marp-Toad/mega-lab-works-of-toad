﻿#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

template <typename T, template <typename, typename> class Container>
class Vector 
{
public:
    Vector() {}
    void add(T element)
    {
        container.push(element);
    }

    void remove() 
    {
        container.pop();
    }
  
    void multiply_by_max() 
    {
        T max_element = *max_element(begin(container), end(container));
        for (auto& element : container) 
        {
            element *= max_element;
        }
    }
    void print()
    {
        while (!container.empty())
        {
            cout << container.top() << " ";
            container.pop();
        }
        cout << endl;
    }
private:
    Container<T, deque<T>> container;
};

int main()
{
    Vector<int, stack> v;
    v.add(5);
    v.add(10);
    v.add(15);
    v.multiply_by_max();
    v.print();
    return 0;
}