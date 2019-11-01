#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:

template <typename T>
class LinkedList
{

private:
    Node<T> *head;
    Node<T> *tail;
    int count;

public:
    LinkedList()
        : head(nullptr), tail(nullptr), count(0) {}

    ~LinkedList()
    {
        Node<T> *current = head;
        Node<T> *next;
        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void push_front(T inData)
    {

        Node<T> *temp = new Node<T>(inData);
        if (count != 0)
        {
            temp->next = head;
            head->previous = temp;
        }
        head = temp;
        if (count == 0)
        {
            tail = temp;
        }
        count++;
    }

    void push_back(T inData)
    {
        Node<T> *temp = new Node<T>(inData);
        if (count == 0)
        {
            head = temp;
        }
        else
        {
            temp->previous = tail;
            tail->next = temp;
        }
        tail = temp;
        count++;
    }

    T &front()
    {
        return head->data;
    }

    T &back()
    {
        return tail->data;
    }

    int size()
    {
        return count;
    }

    NodeIterator<T> begin()
    {
        return NodeIterator<T>(head);
    }

    NodeIterator<T> end()
    {
        return NodeIterator<T>(nullptr);
    }

    void reverse()
    {
        Node<T> *current = head;
        Node<T> *nxt;
        Node<T> *prev;
        Node<T> *temp;
        while (current != nullptr)
        {
            nxt = current->next;
            prev = current->previous;
            current->previous = nxt;
            current->next = prev;
            current = nxt;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
};

// do not edit below this line

#endif
