#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using std::ostream;

#include <string>
using std::string;

// TODO: your code  goes here

class Item
{
private:
    double latitude;
    double longitude;
    string id;
    int seconds;

public:
    Item(double inLatitude, double inLongitude, string inID, int inSeconds)
        : latitude(inLatitude), longitude(inLongitude), id(inID), seconds(inSeconds)
    {
    }

    double getLat() const
    {
        return latitude;
    }

    double getLong() const
    {
        return longitude;
    }

    string getID() const
    {
        return id;
    }

    int getSeconds() const
    {
        return seconds;
    }
};

ostream &operator<<(ostream &out, const Item &item)
    {
        out << "{" << item.getLat() << ", " << item.getLong() << ", " << "\"" << item.getID() << "\"" << ", " << item.getSeconds() << "}"
            << "\n";
        return out;
    }

// don't write any code below this line

#endif
