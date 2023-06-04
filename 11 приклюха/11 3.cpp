#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    struct Node 
    {
        T data;
        Node* next;
    };

    Node* top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T item) 
    {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    T pop()
    {
        if (isEmpty()) 
        {
            cerr << "Стек пуст" << endl;
            exit(EXIT_FAILURE);
        }

        Node* temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    T peek() 
    {
        if (isEmpty())
        {
            cerr << "Стек пуст" << endl;
            exit(EXIT_FAILURE);
        }

        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

int main() 
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << stack.peek() << endl;
    stack.pop();
    cout << stack.peek() << endl;
    stack.pop();
    cout << stack.peek() << endl;
    stack.pop();
    cout << stack.isEmpty() << endl;
    return 0;
}