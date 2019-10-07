#ifndef NEARLYSORTED_H
#define NEARLYSORTED_H

#include <vector>
using std::vector;

/** @brief Class that describes how to sort a nearly-sorted vector */
class HowToSort
{
protected:
    /** @brief The index of the first element to use */
    int firstElement;

    /** @brief The index of the second element to use */
    int secondElement;

    /** @brief If true, firstElement and secondElement should be swapped; if false, the range of elements should be reversed */
    bool swapThem;

public:
    /** @brief Default constructor.
     * 
     * This assumes that we can't sort the vector by swapping/reversing a range -- it sets both elements
     * to have an index -1.
     */
    HowToSort()
        : firstElement(-1),
          secondElement(-1),
          swapThem(false)
    {
    }

    /** @brief The actual constructor: use this to define how to sort a nearly-sorted vector
     * 
     * @param firstElementIn   The first element to use
     * @param secondElementIn  The second element to use
     * @param swapThemIn       If true, swap firstElementIn and secondElementIn; if false, reverse the range of elements
     */
    HowToSort(const int firstElementIn, const int secondElementIn,
              const bool swapThemIn)
        : firstElement(firstElementIn),
          secondElement(secondElementIn),
          swapThem(swapThemIn)
    {
    }

    /** @brief Returns false if no way to sort the vector could be found (i.e. if firstElement == -1) */
    bool canBeMadeSorted() const
    {
        return (firstElement != -1);
    }

    /** @brief Accessor function -- get the first element to use */
    int getFirstElement() const
    {
        return firstElement;
    }

    /** @brief Accessor function -- get the second element to use */
    int getSecondElement() const
    {
        return secondElement;
    }

    /** @brief If true, the element indices denote a swap.  If false, they denote a range reversal. */
    bool isASwap() const
    {
        return swapThem;
    }
};

// TODO your code goes here:

HowToSort nearlySorted(vector<int> inV)
{
    int n = inV.size();
    vector<int> sorted = inV;
    vector<int> reversed = inV;
    vector<int> diff;

    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i)
    {
        if (inV[i] != sorted[i])
            diff.push_back(i);
    }

    if (diff.size() == 0)
    {
        return HowToSort(0, 0, true);
    }

    if (diff.size() == 2 && inV[diff[0]] == sorted[diff[1]] && sorted[diff[0]] == inV[diff[1]])
    {
        return HowToSort(diff[0], diff[1], true);
    }

    reverse(reversed.begin() + diff[0], reversed.begin() + diff.back() + 1);
    bool reverseWorks = false;

    for (int i = 0; i < n; ++i)
        reverseWorks = (reversed[i] == sorted[i]);

    if (reverseWorks)
        return HowToSort(diff[0], diff.back(), false);

    else
        return HowToSort();
}

// Don't write any code below this line

#endif
