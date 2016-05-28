#ifndef _STACK_
#define _STACK_

#include<iostream>
#include"../List/MyList.h"
using namespace std;

class StackIsEmpty{};

template<typename T>
class MyStack{
public:
    MyStack():mylist()
    {}
    ~MyStack()
    {}
    MyStack(const MyStack<T>& mystack)
    {
        mylist=mystack.mylist;
    }
    MyStack<T>& operator=(const MyStack<T>& mystack)
    {
        mylist=mystack.mylist;
    }
    void push(const T& t)
    {
        mylist.push_back(t);
    }
    void pop()throw (StackIsEmpty)
    {
        try
        {
            mylist.pop_back();
        }
        catch(ListIsEmpty&)
        {
            throw StackIsEmpty();
        }
    }
    T top()
    {
        return mylist.end()->data;
    }
    bool empty()
    {
        return mylist.empty();
    }
    size_t size()
    {
        return mylist.size();
    }
private:
    List<T> mylist;
};

#endif
