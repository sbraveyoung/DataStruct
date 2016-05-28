#ifndef _MYLIST_
#define _MYLIST_

#include<iostream>
using namespace std;

class ListIsEmpty{};
class ArgIsIll{};

template<typename T>
class Node{
public:
    Node(const T& d=T()):data(d),prev(NULL),next(NULL)
    {}
    ~Node()
    {}
private:
    Node(const Node& n);
    Node& operator=(const Node& n);
public:
    T data;
    Node* prev;
    Node* next;
};

template<typename T>
class List{
public:
    List():front(NULL),tail(NULL),cur_size(0)
    {}
    ~List()
    {
        while(!this->empty())
        {
            this->pop_front();
        }
    }
    List& operator=(const List& l)
    {
        if(&l!=this)
        {
            Node<T>* cur=l.front;
            List newlist;
            while(cur!=NULL)
            {
                newlist.push_front(cur->data);
            }
        }
        return newlist;
    }
    Node<T>* begin()
    {
        return front;
    }
    Node<T>* end()//此处end函数与STL中稍微有点不同，STL中end返回值指向最后一个元素的下一个，这里指向最后一个元素
    {
        return tail;
    }
    bool empty()
    {
        if(cur_size==0)
            return true;
        else
            return false;
    }
    size_t size()
    {
        return cur_size;
    }
    bool push_front(Node<T>* n)
    {
        if(this->empty())
        {
            front=tail=n;
        }
        else
        {
            n->next=front;
            front->prev=n;
            n->prev=tail;
            tail->next=n;
            front=n;
        }
        cur_size++;
        return true;
    }
    bool pop_front()throw (ListIsEmpty)
    {
        if(this->empty())
        {
            throw ListIsEmpty();
        }
        else if(this->size()==1)
        {
            delete front;
            front=tail=NULL;
        }
        else
        {
            Node<T>* s=front;
            front=front->next;
            front->prev=tail;
            tail->next=front;
            delete s;
        }
        cur_size--;
        return true;
    }
    bool push_front(const T& t)
    {
        Node<T> *s=new Node<T>(t);
        return push_front(s);
    }
    bool push_back(Node<T>* n)
    {
        if(this->empty())
        {
            front=tail=n;
        }
        else
        {
            tail->next=n;
            n->prev=tail;
            n->next=front;
            front->prev=n;
            tail=n;
        }
        cur_size++;
        return true;
    }
    bool pop_back()throw (ListIsEmpty)
    {
        if(this->empty())
        {
            throw ListIsEmpty();
        }
        else if(this->size()==1)
        {
            delete tail;
            front=tail=NULL;
        }
        else
        {
            Node<T>* s=tail;
            tail=tail->prev;
            front->prev=tail;
            tail->next=front;
            delete s;
        }
        cur_size--;
        return true;
    }
    bool push_back(const T& t)
    {
        Node<T> *s=new Node<T>(t);
        return push_back(s);
    }
    bool insert(size_t pos,Node<T>* n)throw (ArgIsIll)
    {
        if(pos>this->size())
        {
            throw ArgIsIll();
        }
        else if(pos==this->size())
        {
            return push_back(n);
        }
        else if(pos==0)
        {
            return push_front(n);
        }
        else
        {
            size_t i=0;
            Node<T>* cur=front;
            for(i=0;i<pos-1;++i)
            {
                cur=cur->next;
            }
            n->next=cur->next;
            cur->next->prev=n;
            n->prev=cur;
            cur->next=n;
            cur_size++;
            return true;
        }
    }
    bool insert(size_t pos,const T& t)throw (ArgIsIll)
    {
        Node<T>* s=new Node<T>(t);
        return insert(pos,s);
    }
    bool erase(size_t pos)
    {
        if(pos>this->size())
        {
            throw ArgIsIll();
        }
        else if(pos==this->size())
        {
            return pop_back();
        }
        else if(pos==0)
        {
            return pop_front();
        }
        else
        {
            size_t i=0;
            Node<T>* cur=front;
            for(i=0;i<pos-1;++i)
            {
                cur=cur->next;
            }
            cur->next->prev=cur->prev;
            cur->prev->next=cur->next;
            delete cur;
            cur_size--;
            return true;
        }
    }
    void print()const
    {
        Node<T>* cur=front;
        while(true)
        {
            cout<<cur->data<<" ";
            if(cur==tail)
                break;
            cur=cur->next;
        }
        cout<<endl;
    }
private:
    List(const List& l);
private:
    Node<T>* front;
    Node<T>* tail;
    size_t cur_size;
};

#endif

