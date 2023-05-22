#include <iostream>

template <typename T>
class Vector
{
private:
    T* data;
    int size;
public:
    Vector() : data(nullptr), size(0) {}
    Vector(int size, T value = T()) : size(size) 
    {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = value;
        }
    }
    ~Vector()
    {
        delete[] data;
    }
    Vector(const Vector& other) : size(other.size) 
    {
        data = new T[size];
        for (int i = 0; i < size; i++) 
        {
            data[i] = other.data[i];
        }
    }
    Vector& operator=(const Vector& other) 
    {
        if (this != &other) 
        {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    T& operator[](int index) 
    {
        return data[index];
    }
    int get_size() const 
    {
        return size;
    }
    Vector operator*(const Vector& other) const 
    {
        int n = std::min(size, other.size);
        Vector result(n);
        for (int i = 0; i < n; i++)
        {
            result.data[i] = data[i] * other.data[i];
        }
        return result;
    }
};