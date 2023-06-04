#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* prev;
    Node* next;
    Node(int key) : key(key), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void add(int key)
    {
        Node* newNode = new Node(key);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
        size++;
    }

    void remove(int start, int count) 
    {
        if (start >= size || count == 0)
        {
            return;
        }
        Node* curr = head;
        for (int i = 0; i < start; i++) 
        {
            curr = curr->next;
        }
        for (int i = 0; i < count && curr != nullptr; i++)
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
            size--;
        }
        if (curr != nullptr)
        {
            curr->prev = curr->prev->prev;
            if (curr->prev == nullptr)
            {
                head = curr;
            }
            else
            {
                curr->prev->next = curr;
            }
        }
        else {
            tail = tail->prev;
            if (tail == nullptr) 
            {
                head = nullptr;
            }
            else 
            {
                tail->next = nullptr;
            }
        }
    }

    void insert(int start, int count) 
    {
        if (start > size)
        {
            return;
        }
        Node* curr = head;
        for (int i = 0; i < start; i++) 
        {
            curr = curr->next;
        }
        Node* prev = curr->prev;
        for (int i = 0; i < count; i++)
        {
            Node* newNode = new Node(rand() % 100);
            newNode->prev = prev;
            newNode->next = curr;
            if (prev == nullptr) 
            {
                head = newNode;
            }
            else 
            {
                prev->next = newNode;
            }
            curr->prev = newNode;
            prev = newNode;
            size++;
        }
    }

    void print() const 
    {
        Node* curr = head;
        while (curr != nullptr) 
        {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int size;
};

int main()
{
    DoublyLinkedList list;
    for (int i = 0; i < 10; i++)
    {
        list.add(i);
    }
    list.print();
}