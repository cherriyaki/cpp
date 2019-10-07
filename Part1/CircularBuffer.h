#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

// NB: Do not add any extra #include statements to this file
#include "SimpleVector.h"
#include <iostream>

/** TODO: complete the definition of the class CircularBuffer here
 */
class CircularBuffer
{

private:
    int n = 0;
    int size = 0;
    int oldest = 0;
    int next = 0;
    SimpleVector<char> sv;

public:
    /*  
    CircularBuffer(int inN)
        : vector(new SimpleVector<char>(inN)), n(inN)
    {
        for (int i = 0; i < n; ++i)
        {
            vector[i] = ' ';
        }
    }
    */

    CircularBuffer(int inN)
        : n(inN), sv(n)
    {
        // SimpleVector<char> v(n);
        for (int i = 0; i < n; ++i)
        {
            sv[i] = ' ';
        }
        // sv = &v;
    }
    // REVIEW why ++ first
    void add(char inChar)
    {
        sv[next] = inChar;
        next = (next + 1) % n;
        size++;
    }

    int count()
    {
        return size;
    }

    bool full()
    {
        if (size == n)
        {
            return true;
        }
        else
            return false;
    }
    char remove()
    {
        char removed = sv[oldest];
        sv[oldest] = ' ';
        oldest = (oldest + 1) % n;
        size--;
        if (size == 0)
            next = 0;
        return removed;
    }
};

// don't write any code below this line

#endif
