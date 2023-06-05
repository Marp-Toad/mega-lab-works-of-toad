﻿#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void fill_vector(vector<int>& v)
{
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Введите элемент: ";
        cin >> x;
        v.push_back(x);
    }
}

void print_vector(const vector<int>& v)
{
    cout << "Вектор: ";
    for (int x : v) 
    {
        cout << x << " ";
    }
    cout << endl;
}

void multiply_by_max(vector<int>& v) 
{
    if (v.empty()) 
    {
        return;
    }
    int max_elem = *max_element(v.begin(), v.end());
    for (int& x : v)
    {
        x *= max_elem;
    }
}

void remove_max(vector<int>& v)
{
    if (v.empty())
    {
        return;
    }
    int max_elem = *max_element(v.begin(), v.end());
    v.erase(remove(v.begin(), v.end(), max_elem), v.end());
}

void fill_map(map<int, int>& m) 
{
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int key, value;
        cout << "Введите ключ и значение: ";
        cin >> key >> value;
        m[key] = value;
    }
}

void print_map(const map<int, int>& m)
{
    cout << "Ассоциативный контейнер:" << endl;
    for (const auto& kv : m) 
    {
        cout << kv.first << " -> " << kv.second << endl;
    }
}

int main()
{
    setlocale(0, "");
    vector<int> v;
    fill_vector(v);
    print_vector(v);
    multiply_by_max(v);
    print_vector(v);
    remove_max(v);
    print_vector(v);

    map<int, int> m;
    fill_map(m);
    print_map(m);

    return 0;
}