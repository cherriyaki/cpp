#ifndef ITEM_H
#define ITEM_H

// TODO: copy your Item.h file from assignment 1 over this file
#define _USE_MATH_DEFINES

#include <iostream>
using std::ostream;

#include <string>
using std::string;

#include <cmath>

// radius of the earth in metres
const double R = 6373000;

/* non-class functions */
double toRadian(double inD)
{
    return inD * M_PI / 180;
}

/* class */
class Item
{
private:
    double latitude;
    double longitude;
    string id;
    int seconds;

public:
    /* constructor */
    Item(double inLatitude, double inLongitude, string inID, int inSeconds)
        : latitude(inLatitude), longitude(inLongitude), id(inID), seconds(inSeconds)
    {
    }

    /* get methods */
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

    /* class method */
    double distanceTo(const Item &inItem)
    {
        //convert longitudes and latitudes to radians
        double lon1 = toRadian(longitude);
        double lon2 = toRadian(inItem.getLong());
        double lat1 = toRadian(latitude);
        double lat2 = toRadian(inItem.getLat());

        // Haversine formula. return distance to another item in metres
        double dlon = lon2 - lon1;
        double dlat = lat2 - lat1;

        double a = pow((sin(dlat / 2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlon / 2)), 2);
        double c = 2 * atan2(sqrt(a), sqrt(1 - a));
        double distance = R * c;

        return distance;
    }
};

/* non-class functions */
// REVIEW why outside class?
// REVIEW ostream
ostream &operator<<(ostream &out, const Item &item)
{
    out << "{" << item.getLat() << ", " << item.getLong() << ", "
        << "\"" << item.getID() << "\""
        << ", " << item.getSeconds() << "}";
    return out;
}

// don't write any code below this line

#endif

