#ifndef _PRIORITY_
#define _PRIORITY_

#include<iostream>
#include"../Heap/Heap.h"
using namespace std;

template<typename T,typename U>
class PriorityQueue{
public:
    PriorityQueue():MyHeap()
    {}
    ~PriorityQueue()
    {}
    PriorityQueue(const PriorityQueue& pq)
    {
        MyHeap=pq.MyHeap;
    }
    PriorityQueue& operator=(const PriorityQueue& pq)
    {
        if(&pq!=this)
        {
            MyHeap=pq.MyHeap;
        }
    }
    size_t size()
    {
        return MyHeap.size();
    }
    bool empty()
    {
        return MyHeap.empty();
    }
    void push(const T& key,const U& value)
    {
    }
private:
    heap<T> MyHeap;
};

#endif
