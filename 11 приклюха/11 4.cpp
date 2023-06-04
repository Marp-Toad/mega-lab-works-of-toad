#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    struct Node 
    {
        T data;
        Node* next;
        Node* prev;
    };

    Node* front;
    Node* rear;

public:
    Queue() 
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() 
    {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }

    void enqueue(T item)
    {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (isEmpty()) 
        {
            front = newNode;
        }
        else
        {
            rear->next = newNode;
        }

        rear = newNode;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cerr << "Очередь пуста" << endl;
            exit(EXIT_FAILURE);
        }

        Node* temp = front;
        T data = temp->data;

        if (front == rear)
        {
            front = nullptr;
            rear = nullptr;
        }
        else 
        {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        return data;
    }

    T peek()
    {
        if (isEmpty())
        {
            cerr << "Очередь пуста" << endl;
            exit(EXIT_FAILURE);
        }

        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main() 
{
    setlocale(LC_ALL, "RUS");
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.peek() << endl;
    queue.dequeue();
    cout << queue.peek() << endl;
    queue.dequeue();
    cout << queue.peek() << endl;
    queue.dequeue();
    cout << queue.isEmpty() << endl;
    return 0;
}