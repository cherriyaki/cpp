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
using std::fill;
using std::move;
using std::next;
using std::ostream;
using std::set;
using std::sqrt;
using std::vector;

// TODO: Your Sudoku class goes here:

class Sudoku : public Searchable
{

private:
    int size = 0;
    int sqr = 0;
    vector<vector<set<int>>> rows; // [row][col]
    // vector<vector<bool>> checked;  // grid indicating squares with one answer that need to be checked. bools - 0 if set has one element and it hasn't been checked. 1 if either the element has been checked or set has >one options so it doesn't need checking.

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
        // for every row
        // for (auto &r : checked)
        // {
        //     r.resize(inSize);
        //     fill(r.begin(), r.end(), 1);
        // }
    }

    int getE(const set<int> &searchSet, int n) const
    {
        int result;
        if (searchSet.size() > n)
        {
            result = *next(searchSet.begin(), n);
        }

        return result;
    }

    /* ANCHOR part c) */

    // virtual bool isSolution() const = 0;
    bool isSolution() const
    {
        // for every row
        for (int i = 0; i < size; ++i)
        {
            // for every set in current row
            for (int j = 0; j < size; ++j)
            {
                const set<int> &s = rows[i][j];

                if (s.size() != 1)
                    return false;
            }
        }
        return true;
    }

    // virtual void write(ostream &o) const = 0;
    void write(ostream &o) const
    {
        // for every row
        for (int i = 0; i < size; ++i)
        {
            // for every set in current row
            for (int j = 0; j < size; ++j)
            {
                const set<int> &s = rows[i][j];

                if (s.size() != 1)
                    o << "_ ";
                else
                    o << getE(s, 0) << ' ';
            }
            o << endl;
        }
    }

    // virtual vector<unique_ptr<Searchable>> successors() const = 0;
    vector<unique_ptr<Searchable>> successors() const
    {
        vector<unique_ptr<Searchable>> vec;

        bool found = 0;

        // for every row
        for (int i = 0; i < size; ++i)
        {
            // for every set in current row
            for (int j = 0; j < size; ++j)
            {
                const set<int> &s = rows[i][j];

                // if set has >1 options, this set is found
                if (s.size() > 1)
                    found = 1;

                if (found)
                {
                    for (auto &v : s)
                    {
                        Sudoku *suCopy = new Sudoku(*this);

                        if (suCopy->setSquare(i, j, v))
                        {
                            unique_ptr<Searchable> uP;
                            uP.reset(suCopy);
                            vec.push_back(move(uP));
                        }

                        else
                        {
                            delete suCopy;
                        }
                    }
                    return vec;
                }
            }
        }
    }

    /* ANCHOR part b) */

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

    bool remove(int r, int c)
    {
        set<int> &s = rows[r][c];
        if (s.size() == 1)
        {
            int target = getE(s, 0);

            for (int k = 0; k < size; ++k)
            {
                // for every set in same row
                set<int> &setR = rows[r][k];
                // iterator it = set.find(target);
                if ((setR.find(target) != setR.end()) && k != c)
                {
                    setR.erase(setR.find(target));
                    if (setR.size() == 1)
                    {
                        remove(r, k);
                    }
                    if (setR.empty())
                        return false;
                }

                // for every set in the same column
                set<int> &setC = rows[k][c];
                if ((setC.find(target) != setC.end()) && k != r)
                {
                    setC.erase(setC.find(target));
                    if (setC.size() == 1)
                    {
                        remove(k, c);
                    }
                    if (setC.empty())
                        return false;
                }
            }

            // for every set in same box
            // eg. row 7 in 9x9grid. 4-(4%3)=3. look at rows 3 to 3+2.
            int lowBoundR = r - (r % sqr);
            int lowBoundC = c - (c % sqr);
            for (int k = lowBoundR; k <= (lowBoundR + 2); ++k)
            {
                for (int x = lowBoundC; x <= (lowBoundC + 2); ++x)
                {
                    set<int> &set = rows[k][x];

                    if ((set.find(target) != set.end()) && k != r && x != c)
                    {
                        set.erase(set.find(target));
                        if (set.size() == 1)
                        {
                            remove(k, x);
                        }
                        if (set.empty())
                            return false;
                    }
                }
            }
        }

        return true;
    }

    bool setSquare(int r, int c, int v)
    {
        // set in that square should only contain v
        rows[r][c].clear();
        rows[r][c].insert(v);
        // write(cout);
        // cout << '\n';
        return remove(r, c);
    }
};

#endif
