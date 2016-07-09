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

    Color _col;
};

template<typename K,typename V>
class RBTree{
    typedef RBTreeNode<K,V> Node;
public:
    bool Insert(const K& key,const V& value);
    bool Remove(cosnt K& key);
    Node* Find(const K& key);
    void RotateR(Node* parent);
    void RotateL(Node* parent);
    bool IsBalance();
private:
};
