#ifndef _DEQUE_
#define _DEQUE_

#include<iostream>
#include"../List/MyList.h"

template<typename T>
class Deque{
public:
    Deque():mylist()
    {}
    Deque(const Deque<T>& dq)
    {
        this->mylist=dq.mylist;
    }
    Deque& operator=(const Deque<T>& dq)
    {
        this->mylist=dq.mylist;
    }
    ~Deque()
    {}
    size_t size()
    {
        return mylist.size();
    }
    bool empty()
    {
        return mylist.empty();
    }
    const T& front()
    {
        return mylist.begin()->data;
    }
    void push_back(const T& t)
    {
        mylist.push_back(t);
    }
    void push_front(const T& t)
    {
        mylist.push_front(t);
    }
    void pop_back()
    {
        mylist.pop_back();
    }
    void pop_front()
    {
        mylist.pop_front();
    }
private:
    List<T> mylist;
};

#endif
