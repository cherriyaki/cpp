#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template <typename T>
class TreeNode
{
public:
    T data;
    // https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/, http://www.cplusplus.com/reference/memory/unique_ptr/unique_ptr/, unique_ptr stores an address of which you only want one copy. when its containing pointer is moved to another unique_ptr, the original pointer gives a null address i.e. 0.
    unique_ptr<TreeNode> leftChild;
    // REVIEW why initialising with nullptr doesn't work?
    // unique_ptr<TreeNode> left(nullptr);
    unique_ptr<TreeNode> rightChild;
    // unique_ptr<TreeNode> right(nullptr);
    TreeNode<T> *parent;

    TreeNode(T inData)
        : data(inData), parent(nullptr)
    {
    }

    void setParent(TreeNode *inParent)
    {
        parent = inParent;
    }

    /* https://www.geeksforgeeks.org/this-pointer-in-c/ */

    void setLeftChild(TreeNode *child)
    {
        (*child).setParent(this);
        leftChild.reset(child);
        // (*left.get()).setParent(&this);
    }

    void setRightChild(TreeNode *child)
    {
        (*child).setParent(this);

        rightChild.reset(child);
        // (*right.get()).setParent(&this);
    }

    ostream &write(ostream &out) const
    {
        if (leftChild.get())
        {
            (*leftChild.get()).write(out);
        }
        out << ' ' << data << ' ';
        if (rightChild.get())
        {
            (*rightChild.get()).write(out);
        }
        return out;
    }
};

// do not edit below this line

#endif
