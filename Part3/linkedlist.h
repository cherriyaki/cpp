#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

#include <initializer_list>
using std::initializer_list;

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

    LinkedList(initializer_list<T> inL)
        : head(nullptr), tail(nullptr), count(0)
    {
        for (T e : inL)
        {
            push_back(e);
        }
    }

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

    NodeIterator<T> insert(NodeIterator<T> inIt, T inData)
    {
        Node<T> *temp = new Node<T>(inData);
        Node<T> *pos = inIt.getPtr();
        Node<T> *prev = pos->previous;
        temp->next = pos;
        temp->previous = prev;
        pos->previous = temp;
        if (prev == nullptr)
        {
            head = temp;
        }
        else
            prev->next = temp;
        count++;
        return NodeIterator<T>(temp);
    }

    NodeIterator<T> erase(NodeIterator<T> inIt)
    {
        Node<T> *pos = inIt.getPtr();
        Node<T> *prev = pos->previous;
        Node<T> *nxt = pos->next;
        if (prev == nullptr)
        {
            head = nxt;
        }
        else
            prev->next = nxt;
        if (nxt == nullptr)
        {
            tail = prev;
        }
        else
            nxt->previous = prev;
        delete pos;
        count--;
        return NodeIterator<T>(nxt);
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
        // NOTE https://www.geeksforgeeks.org/delete-in-c/
        // delete temp;
        // idk why can't use delete?
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
        // delete temp;
    }

    const T &front() const
    {
        return head->data;
    }

    const T &back() const
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
