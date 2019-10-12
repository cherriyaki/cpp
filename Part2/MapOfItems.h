#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"

#include <vector>
using std::vector;

#include <cmath>
using std::round;

// TODO: your code goes here

class MapOfItems
{

private:
    vector<Item> items;

public:
    MapOfItems()
        : items()
    {
    }

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
    vector<Item *> getTour(double inSpeed)
    {

        int currTime = 0;
        const int OPEN_DUR = 15 * 60;
        vector<Item> notVisited = items;

        Item firstAvail = items[0];
        int faIdx = 0;
        // loop through items to find the item with smallest seconds
        for (int i = 1; i < items.size(); ++i)
        {
            if (items[i].getSeconds() < firstAvail.getSeconds())
            {
                faIdx = i;
                firstAvail = items[i];
            }
        }
        // add address of first available item to vector of item pointers to be returned
        vector<Item *> pointers;
        pointers.push_back(&firstAvail);
        // we have now visited the first available item
        currTime = firstAvail.getSeconds();
        // https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
        notVisited.erase(notVisited.begin() + faIdx);

        int smallest = 3600;
        Item fastest = notVisited[0];
        int fastestIdx = 0;

        // loop for adding item pointers to the returned vector
        while (!notVisited.empty())
        {
            // among the items we can make it for, find the one with the earliest visit time
            for (int i = 0; i < notVisited.size(); ++i)
            {
                // time of visit is current time + time it takes to get from previously visited item to this item
                int visitT = currTime + round((*(pointers.back())).distanceTo(notVisited[i]) / inSpeed);
                // if time of visit is after item's closing time, check the next item
                if (visitT > (notVisited[i].getSeconds() + OPEN_DUR))
                    continue;
                //  if visiting time is less than opening time, change it to the opening time itself cuz we'd have to visit the item only then
                if (visitT < notVisited[i].getSeconds())
                    visitT = notVisited[i].getSeconds();
                // record the item with the earliest visiting time
                if (visitT < smallest)
                {
                    smallest = visitT;
                    fastest = notVisited[i];
                    fastestIdx = i;
                }
            }
            // if after finding the earliest visiting time it's still not before time 3600, end this loop
            if (smallest >= 3600)
                break;
            // else add item address to tour
            pointers.push_back(&fastest);
            // we have now visited the item
            currTime = smallest;
            notVisited.erase(notVisited.begin() + fastestIdx);
        }

        return pointers;
    }
};

// don't write any code below this line

#endif
