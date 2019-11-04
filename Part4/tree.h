#ifndef TREE_H
#define TREE_H

#include "treenode.h"

#include <iostream>
using std::cout;
using std::ostream;

#include <memory>
using std::unique_ptr;

// TODO your code goes here:

template <typename T>
class BinarySearchTree
{

private:
    unique_ptr<TreeNode<T>> root;

public:
    BinarySearchTree() {}
    BinarySearchTree(const BinarySearchTree &inT)
    {
        root.reset(inT.root.get());
    }

    // void clear(TreeNode<T> *n)
    // {
    //     if (n->leftChild)
    //     {
    //         clear(n->leftChild.get());
    //     }
    //     if (n->rightChild)
    //     {
    //         clear(n->rightChild.get());
    //     }
    //     free(n);
    // }

    // void operator=(const BinarySearchTree &inT)
    // {

    //     root.reset(inT.root.get());

    //     // return *this;
    // }

    ostream &write(ostream &out) const
    {
        root->write(out);
        return out;
    }

    int maxDepth()
    {
        if (!root)
            return 0;
        else
            return root->maxDepth();
    }

    TreeNodeIterator<T> begin()
    {
        if (!root)
        {
            return TreeNodeIterator<T>(nullptr);
        }
        // NOTE always rmb to account for all cases. i.e. the case of null root object from which you can't call methods
        else
            return TreeNodeIterator<T>(root->leftmost());
    }

    TreeNodeIterator<T> end()
    {
        return TreeNodeIterator<T>(nullptr);
    }

    /* ANCHOR rotation task */

    int balanceFactor(TreeNode<T> *inN)
    {
        int lD = 0;
        int rD = 0;
        if (inN->leftChild)
            lD = inN->leftChild->maxDepth();
        if (inN->rightChild)
            rD = inN->rightChild->maxDepth();
        return lD - rD;
    }

    void leftRota(TreeNode<T> *inN)
    {
        TreeNode<T> *rt = (inN->rightChild).get();
        TreeNode<T> *prt = nullptr;
        if (inN->parent)
        {
            prt = inN->parent;
            if (rt->data < prt->data)
            {
                prt->leftChild.release();
                prt->setLeftChild(rt);

                // prt->leftChild.reset(rt);
            }
            if (prt->data < rt->data)
            {
                prt->rightChild.release();
                prt->setRightChild(rt);
                // prt->rightChild.reset(rt);
            }
        }
        else
            rt->setParent(prt);

        rt->setLeftChild(inN);
        (inN->rightChild).release();

        if (!rt->parent)
        {
            root.release();
            root.reset(rt);
        }

        // cout << "leftrota " << endl;
        // cout << "root is now " << rt->data << endl;
        // cout << "left is now " << rt->leftChild->data << endl;
    }

    void rightRota(TreeNode<T> *inN)
    {
        TreeNode<T> *lt = (inN->leftChild).get();
        TreeNode<T> *prt = nullptr;
        if (inN->parent)
        {
            prt = inN->parent;
            if (lt->data < prt->data)
            {
                prt->leftChild.release();
                prt->setLeftChild(lt);
                // prt->leftChild.reset(lt);
            }

            if (prt->data < lt->data)
            {
                prt->rightChild.release();
                prt->setRightChild(lt);
                // prt->rightChild.reset(lt);
            }
        }
        else
            lt->setParent(prt);

        lt->setRightChild(inN);
        (inN->leftChild).release();

        if (!lt->parent)
        {
            root.release();
            root.reset(lt);
        }

        // cout << "rightrota " << endl;
        // cout << "root is now " << lt->data << endl;
        // cout << "right is now " << lt->rightChild->data << endl;
    }

    void balance(TreeNode<T> *inN)
    {
        if (inN->parent && inN->parent->parent)
        {
            TreeNode<T> *prt = inN->parent;
            TreeNode<T> *prtprt = prt->parent;

            int bF = balanceFactor(prtprt);
            // cout << bF << endl;
            if ((bF == 2) || (bF == -2))
            {
                if ((prt->data < inN->data) && (prtprt->data < prt->data))
                {
                    leftRota(prtprt);
                }
                if ((inN->data < prt->data) && (prt->data < prtprt->data))
                {
                    rightRota(prtprt);
                }
                // left right rotation
                if ((prt->data < inN->data) && (prt->data < prtprt->data))
                {
                    // cout << inN->data << " " << prt->data << " " << prtprt->data << endl;
                    leftRota(prt);
                    rightRota(prtprt);
                }
                // right left rotation
                if ((inN->data < prt->data) && (prtprt->data < prt->data))
                {
                    rightRota(prt);
                    leftRota(prtprt);
                }
            }
        }
        else
            return;
    }

    /* end of rotation task */

    TreeNode<T> *insert(T inData)
    {
        TreeNode<T> *newN = new TreeNode<T>(inData);
        if (!root)
        {
            root.reset(newN);
        }
        TreeNode<T> *current = root.get();
        bool inserted = 0;

        while (!inserted)
        {
            if (current->data < inData)
            {
                if (current->rightChild)
                {
                    current = current->rightChild.get();
                    continue;
                }
                else
                {
                    current->setRightChild(newN);
                    inserted = 1;
                    balance(newN);
                }
            }
            else if (inData < current->data)
            {
                if (current->leftChild)
                {
                    current = current->leftChild.get();
                    continue;
                }
                else
                {
                    current->setLeftChild(newN);
                    inserted = 1;
                    balance(newN);
                }
            }
            else
                return current;
        }
        return newN;
    }

    TreeNode<T> *find(T inData)
    {
        TreeNode<T> *current = root.get();
        bool found = 0;

        while (!found)
        {
            if (current->data < inData)
            {
                if (current->rightChild)
                {
                    current = current->rightChild.get();
                    continue;
                }
                else
                {
                    return nullptr;
                }
            }
            else if (inData < current->data)
            {
                if (current->leftChild)
                {
                    current = current->leftChild.get();
                    continue;
                }
                else
                {
                    return nullptr;
                }
            }
            else
                found = 1;
        }
        return current;
    }

    // TreeNode<T> getRoot()
    // {
    //     return root.get();
    // }
};

// do not edit below this line

#endif
