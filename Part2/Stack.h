#ifndef STACK_H
#define STACK_H

#include <vector>
using std::vector;

#include <string>
using std::string;

// TODO: Your code goes here

class Stack
{
private:
    vector<double> v;

public:
    Stack()
        : v()
    {
    }

    bool empty()
    {
        if (v.size() < 1)
            return true;
        else
            return false;
    }

    void push(const double inElem)
    {
        v.push_back(inElem);
    }

    double pop()
    {
        double last = v.back();
        v.pop_back();
        return last;
    }
};

double evaluate(string inS)
{
    
}

// Do not write anything below this line

#endif
