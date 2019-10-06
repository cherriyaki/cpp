#ifndef STACK_H
#define STACK_H

#include <vector>
using std::vector;

#include <string>
using std::stod;
using std::string;

#include <queue>
using std::queue;

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

    void push(double inElem)
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

queue<string> split(string str)
{
    queue<string> words;

    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            words.push(word);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    words.push(word);
    return words;
}

double evaluate(string inStr)
{
    Stack stack;

    queue<string> tokens = split(inStr);
    string front;
    while (!tokens.empty())
    {
        front = tokens.front();
        if (front.compare("+") == 0)
        {
            double a = stack.pop();
            double b = stack.pop();
            stack.push(b + a);
        }
        else if (front.compare("-") == 0)
        {
            double a = stack.pop();
            double b = stack.pop();
            stack.push(b - a);
        }
        else if (front.compare("*") == 0)
        {
            double a = stack.pop();
            double b = stack.pop();
            stack.push(b * a);
        }
        else if (front.compare("/") == 0)
        {
            double a = stack.pop();
            double b = stack.pop();
            stack.push(b / a);
        }
        else
        {
            stack.push(stod(front));
        }
        tokens.pop();
    }
    return stack.pop();
}

// Do not write anything below this line

#endif
