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
        // (*child).setParent(this);
        leftChild.reset(child);
        leftChild->setParent(this);
        // (*left.get()).setParent(&this);
    }

    void setRightChild(TreeNode *child)
    {
        // (*child).setParent(this);
        rightChild.reset(child);
        rightChild->setParent(this);
        // (*right.get()).setParent(&this);
    }

    /* https://www.tutorialspoint.com/cplusplus/cpp_member_operators.htm */
    ostream &write(ostream &out) const
    {
        if (leftChild.get())
        {
            leftChild->write(out);
        }
        out << ' ' << data << ' ';
        if (rightChild.get())
        {
            rightChild->write(out);
        }
        return out;
    }

    TreeNode<T> *leftmost()
    {
        TreeNode<T> *cur = this;
        while (cur->leftChild)
        {

            cur = (cur->leftChild).get();
        }
        return cur;
    }

    int maxDepth()
    {
        if (!leftChild && !rightChild)
        {
            return 1;
        }
        else
        {
            int lD = 0;
            int rD = 0;
            if (leftChild)
                lD = leftChild->maxDepth();
            if (rightChild)
                rD = rightChild->maxDepth();
            if (lD > rD)
            {
                return lD + 1;
            }
            else
                return rD + 1;
        }
    }
};

// TODO TreeNodeIterator

template <typename T>
class TreeNodeIterator
{

private:
    TreeNode<T> *current;

public:
    TreeNodeIterator(TreeNode<T> *inN)
        : current(inN) {}

    TreeNode<T> *getPtr()
    {
        return current;
    }

    T &operator*()
    {
        return current->data;
    }

    bool operator==(TreeNodeIterator<T> inIt)
    {
        if (current == inIt.getPtr())
        {
            return true;
        }
        else
            return false;
    }

    bool operator!=(TreeNodeIterator<T> inIt)
    {
        if (current != inIt.getPtr())
            return true;
        else
            return false;
    }

    // inorder traversal
    void operator++()
    {

        if (current->rightChild)
        {
            current = current->rightChild->leftmost();
            // current = leftmost(current->rightChild.get());
        }
        else
        {
            int found = 0;
            while (!found)
            {
                if (current->parent == nullptr)
                {
                    current = nullptr;
                    break;
                }
                if (current->data < current->parent->data)
                {
                    found = 1;
                }
                current = current->parent;
            }
        }
    }
};

// do not edit below this line

#endif
