#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"
#include <vector>
#include <set>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;
// using std::iota;
using std::next;
using std::set;
using std::sqrt;
using std::vector;

// TODO: Your Sudoku class goes here:

class Sudoku
{

private:
    int size = 0;
    int sqr = 0;
    vector<vector<set<int>>> rows; // [row][col]

public:
    Sudoku(int inSize)
        : size(inSize), rows(inSize), sqr(sqrt(inSize))
    {
        // for every row
        for (auto &r : rows)
        {
            r.resize(inSize);
            // for every set in current row
            for (auto &s : r)
            {
                // iota(s.begin(), s.end(), 1);
                // populate set
                for (int i = 1; i <= inSize; ++i)
                {
                    s.insert(i);
                }
            }
        }
    }

    int getE(set<int> &searchSet, int n)
    {
        int result;
        if (searchSet.size() > n)
        {
            result = *next(searchSet.begin(), n);
        }

        return result;
    }

    int getSquare(int r, int c)
    {
        set<int> set = rows[r][c];
        if (set.size() == 1)
        {
            return getE(set, 0);
        }
        else
            return -1;
    }

    bool setSquare(int r, int c, int v)
    {
        // set in that square should only contain v
        rows[r][c].clear();
        rows[r][c].insert(v);

        bool eraseOccured = 1;

        while (eraseOccured)
        {
            eraseOccured = 0;
            // for every row
            for (int i = 0; i < size; ++i)
            {
                // for every set in current row
                for (int j = 0; j < size; ++j)
                {
                    set<int> &s = rows[i][j];

                    // if only one value, erase that value elsewhere
                    if (s.size() == 1)
                    {
                        int target = getE(s, 0);

                        // for every set in same row
                        for (int k = 0; k < size; ++k)
                        {
                            set<int> &set = rows[i][k];
                            // iterator it = set.find(target);
                            if ((set.find(target) != set.end()) && k != j)
                            {
                                set.erase(set.find(target));
                                eraseOccured = 1;
                                if (set.empty())
                                    return false;
                            }
                        }

                        // for every set in the same column
                        for (int k = 0; k < size; ++k)
                        {
                            set<int> &set = rows[k][j];

                            if ((set.find(target) != set.end()) && k != i)
                            {
                                set.erase(set.find(target));
                                eraseOccured = 1;

                                if (set.empty())
                                    return false;
                            }
                        }

                        // for every set in same box
                        // eg. row 7 in 9x9grid. 4-(4%3)=3. look at rows 3 to 3+2.
                        int lowBoundR = i - (i % sqr);
                        int lowBoundC = j - (j % sqr);
                        for (int k = lowBoundR; k <= (lowBoundR + 2); ++k)
                        {
                            for (int x = lowBoundC; x <= (lowBoundC + 2); ++x)
                            {
                                set<int> &set = rows[k][x];

                                if ((set.find(target) != set.end()) && k != i && x != j)
                                {
                                    set.erase(set.find(target));
                                    eraseOccured = 1;

                                    if (set.empty())
                                        return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

#endif
