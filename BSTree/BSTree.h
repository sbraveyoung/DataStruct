#pragma once

#include<iostream>
using namespace std;

template<typename T>
struct BSTreeNode
{
    T _data;
    BSTreeNode<T>* _left;
    BSTreeNode<T>* _right;
    BSTreeNode(const T& t=T())
        :_data(t)
         ,_left(NULL)
         ,_right(NULL)
    {}
};

template<typename T>
class BSTree
{
    typedef BSTreeNode<T> Node;
public:
    BSTree()
        :_root(NULL)
    {}
    bool insert(const T& t)
    {
        Node* s=new Node(t);
        if(_root==NULL)
        {
            _root=s;
            return true;
        }
        else
        {
            Node* father=NULL;
            Node* cur=_root;
            while(cur!=NULL)
            {
                if(cur->_data==s->_data)
                    return false;
                if(cur->_data<s->_data)
                {
                    father=cur;
                    cur=cur->_right;
                }
                else
                {
                    father=cur;
                    cur=cur->_left;
                }
            }
            if(father->_data<s->_data)
                father->_right=s;
            else
                father->_left=s;
            return true;
        }
    }
    void InOrder()
    {
        _InOrder(_root);
        cout<<endl;
    }
protected:
    void _InOrder(Node* root)
    {
        if(root==NULL)
            return;
        _InOrder(root->_left);
        cout<<root->_data<<" ";
        _InOrder(root->_right);
    }
private:
    Node* _root;
};
