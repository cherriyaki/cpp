#ifndef MAPOFITEMS_H
#define MAPOFITEMS_H

#include "Item.h"

#include <vector>
using std::vector;

#include <cmath>
using std::round;

/**
#include <iostream>
using std::cout;
using std::endl;
*/

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
    // see http://www.cplusplus.com/forum/general/56177/ for info on returning a const reference
    const vector<Item> &getItems() const
    {
        //const vector<Item> &refV = items;
        // return refV;
        return items;
    }
    // assuming walking speed is in m/s
    vector<Item *> getTour(double inSpeed)
    {
        // cout << "~~~~~~~~~ new tour ~~~~~~" << endl;

        int currTime = 0;
        const int OPEN_DUR = 15 * 60;
        vector<Item *> notVisited;

        // vector of * to Items not visited yet
        for (int i = 0; i < items.size(); ++i)
        {
            notVisited.push_back(&(items[i]));
        }

        Item *firstAvail = notVisited[0];
        int faIdx = 0;

        // loop through items to find the item with smallest seconds
        for (int i = 1; i < items.size(); ++i)
        {
            if (items[i].getSeconds() < (*firstAvail).getSeconds())
            {
                faIdx = i;
                firstAvail = &(items[i]);
            }
        }
        // cout << "\n first available item is of index " << faIdx << endl;

        // add address of first available item to vector of item pointers to be returned
        vector<Item *> pointers;
        pointers.push_back(firstAvail);

        // cout << " pointers[0] " << pointers[0] << " &(items[0]) " << &(items[0]) << " &(getItems()[0]) " << &(getItems()[0]) << endl;

        // we have now visited the first available item
        currTime = (*firstAvail).getSeconds();
        // cout << "current time is now " << currTime << endl;

        // https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
        notVisited.erase(notVisited.begin() + faIdx);

        int smallest;
        Item *fastest;
        int fastestIdx = 0;

        // loop for adding item pointers to the returned vector
        while (!notVisited.empty())
        {
            // cout << "------- " << endl;
            smallest = 3600;
            // among the items we can make it for, find the one with the earliest visit time
            for (int i = 0; i < notVisited.size(); ++i)
            {

                // cout << "checking notVisited index " << i << endl;

                Item itemBeingChecked = *(notVisited[i]);

                // time of visit is current time + time it takes to get from previously visited item to this item
                int visitT = currTime + round((*(pointers.back())).distanceTo(itemBeingChecked) / inSpeed);

                // if time of visit is after item's closing time, check the next item
                if (visitT > (itemBeingChecked.getSeconds() + OPEN_DUR))
                    continue;

                // cout << "item can be visited" << endl;

                //  if visiting time is less than opening time, change it to the opening time itself cuz we'd have to visit the item only then
                if (visitT < itemBeingChecked.getSeconds())
                    visitT = itemBeingChecked.getSeconds();
                // cout << "visit time = " << visitT << endl;

                // record the item with the earliest visiting time
                if (visitT < smallest)
                {
                    smallest = visitT;
                    fastest = notVisited[i];
                    fastestIdx = i;
                }
            }

            // cout << "smallest visit time is " << smallest << endl;

            // if after finding the earliest visiting time it's still not before time 3600, end this loop
            if (smallest >= 3600)
            {
                // cout << "none of the items can be visited before 3600" << endl;

                break;
            }

            // else add item address to tour
            pointers.push_back(fastest);
            // cout << "item added" << endl;

            // we have now visited the item
            currTime = smallest;
            // cout << "current time is now " << smallest << endl;
            // cout << "fastest index is " << fastestIdx << endl;

            // https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
            notVisited.erase(notVisited.begin() + fastestIdx);
            // cout << "item removed from notVisited" << endl;
        }
        // cout << "whileloop ok" << endl;

        return pointers;
    }
};

// don't write any code below this line

#endif
