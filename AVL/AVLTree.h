#pragma once

#include<iostream>
using namespace std;

template<typename K,typename V>
struct AVLTreeNode{
    K _key;
    V _value;
    AVLTreeNode<K,V>* _parent;
    AVLTreeNode<K,V>* _left;
    AVLTreeNode<K,V>* _right;
    int _bf;
    AVLTreeNode(const K& key,const V& value)
        :_key(key),_value(value),_parent(NULL),_left(NULL),_right(NULL),_bf(0)
    {}
};

template<typename K,typename V>
class AVLTree{
    typedef AVLTreeNode<K,V> Node;
public:
    AVLTree()
        :_root(NULL)
    {}
    ~AVLTree()
    {
        _erase(_root);
    }
    bool Insert(const K& key,const V& value)
    {
        if(_root==NULL)
        {
            _root=new Node(key,value);
            return true;
        }
        Node* parent=NULL;
        Node* cur=_root;
        //插入节点
        while(cur!=NULL)
        {
            if(cur->_key<key)
            {
                parent=cur;
                cur=cur->_right;
            }
            else if(cur->_key>key)
            {
                parent=cur;
                cur=cur->_left;
            }
            else
                return false;
        }
        cur=new Node(key,value);
        if(parent->_key<key)
            parent->_right=cur;
        else
            parent->_left=cur;
        cur->_parent=parent;

        //调节平衡因子
        while(parent!=NULL)
        {
            if(cur==parent->_left)
                parent->_bf--;
            else
                parent->_bf++;

            /* parent->_bf==0:break;
             * parent->_bf==1/-1:continue go up;
             * parent->_bf==2/-2:rotate;
             */
            if(parent->_bf==0)
                break;
            else if(parent->_bf==1 || parent->_bf==-1)
            {
                cur=parent;
                parent=parent->_parent;
            }
            else //parent->_bf==2/-2
            {
                if(parent->_bf==2)
                {
                    if(cur->_bf==1)
                        RotateL(parent);
                    else
                        RotateRL(parent);
                }
                else
                {
                    if(cur->_bf==-1)
                        RotateR(parent);
                    else
                        RotateLR(parent);
                }
                break;
            }
        }
        return true;
    }
    Node* Find(const K& key)
    {
        Node* cur=_root;
        while(cur!=NULL)
        {
            if(cur->_key==key)
                return cur;
            else if(cur->key>key)
                cur=cur->_left;
            else
                cur=cur->_right;
        }
        return NULL;
    }
    void InOrder()
    {
        _InOrder(_root);
        cout<<endl;
    }
    bool IsBalance()
    {
        int depth=0;
        return _IsBalance(_root,depth);
    }
	bool Remove(const K& key)
	{
	}
protected:
    bool _IsBalance(Node* root,int& depth)
    {
        if(root==NULL)
        {
            depth=0;
            return true;
        }
        int left,right;
        if(_IsBalance(root->_left,left) && _IsBalance(root->_right,right))
        {
            depth=left>right?left+1:right+1;
            if(root->_bf==right-left)
                return true;
            else
                return false;
        }
        return false;
    }
    void _InOrder(Node* root)
    {
        if(root==NULL)
            return;
        _InOrder(root->_left);
        cout<<root->_key<<" ";
        _InOrder(root->_right);
    }
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
        //parent->_bf--;
        //subR->_bf--;
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
        //parent->_bf++;
        //subL->_bf++;
    }
    void RotateRL(Node* root)
    {
        if(root==NULL)
            return;
        Node* parent=root;
        Node* subR=parent->_right;
        Node* subRL=NULL;
        if(subR!=NULL)
            subRL=subR->_left;
        RotateR(subR);
        RotateL(parent);
    }
    void RotateLR(Node* root)
    {
        if(root==NULL)
            return;
        Node* parent=root;
        Node* subL=parent->_left;
        RotateL(subL);
        RotateR(parent);
    }
    void _erase(Node* root)
    {
        if(root==NULL)
            return;
        _erase(root->_left);
        _erase(root->_right);
        delete root;
    }
private:
    Node* _root;
};
