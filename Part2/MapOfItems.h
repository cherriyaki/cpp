#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"

#include <vector>
using std::vector;

// TODO: your code goes here

class MapOfItems
{
private:
    vector<Item> items;

public:
    void addItem(Item inItem)
    {
        items.push_back(inItem);
    }
    int size()
    {
        return items.size();
    }
    // see https://www.learncpp.com/cpp-tutorial/6-11a-references-and-const/ for info on const references
    vector<Item> getItems()
    {
        const vector<Item> &refV = items;
        return refV;
    }
    // assuming walking speed is in m/s
    vector<Item *> getTour(int inSpeed)
    {
        int currTime = 0;
        const int CLOSED = 15 * 60;
        vector<Item> notVisited;
        Item firstAvail = items[0];
        for (int i = 1; i < items.size(); ++i)
        {
            if (items[i].getSeconds() < firstAvail.getSeconds())
                firstAvail = items[i];
        }
        vector<Item *> pointers;
        pointers.push_back(&firstAvail);
        currTime = firstAvail.getSeconds();
        remove(notVisited.begin(), notVisited.end(), firstAvail);

        Item fastest = notVisited[0];

        for (int i = 0; i < notVisited.size(); ++i)
        {
            int visitT = currTime + (*pointers.back()).distanceTo(notVisited[i]) / inSpeed;
            if (visitT > notVisited[i].getSeconds() + CLOSED) continue;
            if (visitT )
        }
    }
};

// don't write any code below this line

#endif
