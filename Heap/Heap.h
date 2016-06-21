#ifndef _HEAP_
#define _HEAP_

#include"../Vector/Vector.h"
#include<string>
using namespace std;

template<typename T>
class heap{
public:
    heap():_vector()
    {}
    ~heap()
    {}
    heap(const heap& h)
    {
        _vector=h._vector;
    }
    heap& operator=(const heap& h)
    {
        _vector=h._vector;
    }
    const T& top()
    {
        if(empty())
            throw new string("heap is null!");
        return _vector[0];
    }
    void make_heap()
    {
        int i;
        int n=_vector.size();
        for(i=n/2;i>=0;--i)
        {
            _JustDown(i,n);
        }
    }
    void push_heap(const T& t)
    {
        _vector.push_back(t);
        int i=_vector.size()-1;
        for(;i>=0;)
        {
            if(_vector[i]>_vector[i/2])
            {
                swap(_vector[i],_vector[i/2]);
                i=i/2;
            }
            else
            {
                break;
            }
        }
    }
    bool empty()
    {
        return _vector.empty();
    }
    T& pop_heap()
    {
        if(empty())
            throw new string("heap is null!");
        swap(_vector[0],_vector[_vector.size()-1]);
        T tmp=_vector[_vector.size()-1];
        _vector.pop_back();
        _JustDown(0,_vector.size());
    }
    void sort_heap()
    {
        if(empty())
            throw new string("heap is null!");
        int i=_vector.size()-1;
        for(;i>0;)
        {
            swap(_vector[0],_vector[i]);
            _JustDown(0,i);
            i--;
        }
    }
    void Print()
    {
        int i;
        for(i=0;i<_vector.size();++i)
        {
            cout<<_vector[i]<<" ";
        }
        cout<<endl;
    }
private:
    void _JustDown(int s,int n)
    {
        if(n<=1)
            return;
        if(s>=n)
            return;
        int i;
        for(i=s;i<n;)
        {
            if(i*2+1<n)
            {
                int max=_vector[i*2+1]>_vector[i*2]?i*2+1:i*2;
                max=_vector[max]>_vector[i]?max:i;
                if(i!=max)
                {
                    swap(_vector[i],_vector[max]);
                    i=max;
                }
                else
                {
                    break;
                }
            }
            else if(i*2<n)
            {
                if(_vector[i*2]>_vector[i])
                    swap(_vector[i],_vector[i*2]);
                i*=2;
            }
            else
            {
                break;
            }
        }
    }
private:
    MyVector<T> _vector;
};
#endif
