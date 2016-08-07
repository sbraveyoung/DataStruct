#pragma once

#include<iostream>
using namespace std;

enum Color
{
    RED,
    BLANK,
};

template<typename K,typename V>
struct RBTreeNode{
    K _key;
    V _value;

    RBTreeNode<K,V>* _left;
    RBTreeNode<K,V>* _right;
    RBTreeNode<K,V>* _parent;

    Color _color;

    RBTreeNode(const K& key=K(),const V& value=V())
        :_key(key),_value(value)
         ,_left(NULL),_right(NULL)
         ,_parent(NULL)
         ,_color(RED)
    {}
};

template<typename K,typename V>
class RBTree{
    typedef RBTreeNode<K,V> Node;
public:
    RBTree()
        :_root(nil)
    {}
    bool Insert(const K& key,const V& value)
    {
        Node* s=new Node(key,value);
        Node* parent=nil;
        Node* cur=_root;
        while(cur!=nil)
        {
            parent=cur;
            if(cur->_key>cur->_key)
                cur=cur->_left;
            else
                cur=cur->_right;
        }
        cur->_parent=parent;
        if(parent==nil)
            _root=s;
        else if(s->_key>parent->_key)
            parent->_right=s;
        else 
            parent->_left=s;
        s->_left=s->_right=nil;
        //s->_color=RED;
        RB_INSERT_FIX(s);
    }
    bool Remove(const K& key);
    Node* Find(const K& key);
    bool IsBalance();
protected:
    void RotateL(Node* root)
    {
        if(root==NULL)
            return;
        Node* parent=root;
        Node* subR=parent->_right;
        Node* subRL=subR->_left;
        parent->_right=subRL;
        if(subRL!=NULL)
            subRL->_parent=parent;
        Node* ppNode=parent->_parent;
        subR->_left=parent;
        parent->_parent=subR;
        if(ppNode!=NULL)
        {
            if(ppNode->_left==parent)
                ppNode->_left=subR;
            else
                ppNode->_right=subR;
        }
        else
        {
            _root=subR;
        }
        subR->_parent=ppNode;
        parent->_bf = subR->_bf = 0;
    }
    void RotateR(Node* root)
    {
        if(root==NULL)
            return;
        Node* parent=root;
        Node* subL=parent->_left;
        Node* subLR=subL->_right;
        parent->_left=subLR;
        if(subLR!=NULL)
            subLR->_parent=parent;
        Node* ppNode=parent->_parent;
        subL->_right=parent;
        parent->_parent=subL;
        if(ppNode!=NULL)
        {
            if(ppNode->_left==parent)
                ppNode->_left=subL;
            else
                ppNode->_right=subL;
        }
        else
        {
            _root=subL;
        }
        subL->_parent=ppNode;
        parent->_bf = subL->_bf = 0;
    }
    void RB_INSERT_FIX(Node* cur)
    {
        while(cur->_parent._color==RED)
        {
            Node* parent=cur->_parent;
            Node* grandfather=parent->_parent;
            Node* uncle;
            if(parent=grandfather->_left)
            {
                uncle=grandfather->_right;
                if(uncle->_color=RED)
                {
                    parent->_color=BLANK;
                    uncle->_color=BLANK;
                    grandfather->_color=RED;
                    cur=grandfather;
                }
                else if(cur=parent->_right)
                {
                    cur=parent;
                    rotateL(cur);
                }
                else
                {
                    parent->_color=BLANK;
                    grandfather->_color=RED;
                    rotateR(grandfather);
                }
            }
            else
            {
                uncle=grandfather->_left;
                if(uncle->_color=RED)
                {
                    parent->_color=BLANK;
                    uncle->_color=BLANK;
                    grandfather->_color=RED;
                    cur=grandfather;
                }
                else if(cur=parent->_left)
                {
                    cur=parent;
                    rotateR(cur);
                }
                else
                {
                    parent->_color=BLANK;
                    grandfather->_color=RED;
                    rotateL(grandfather);
                }
            }
        }
    }
private:
    Node* _root;
    static Node* nil;
};

template<typename K,typename V>
RBTreeNode<K,V>* RBTree<K,V>::nil=new RBTreeNode<K,V>();
