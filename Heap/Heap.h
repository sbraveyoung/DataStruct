#ifndef _HEAP_
#define _HEAP_

#include"../Vector/Vector.h"
#include<string>
using namespace std;

template<typename T>
class Less{
public:
    bool operator()(const T& t1,const T& t2)
    {
        return t1<t2;
    }
};

template<typename T>
class Greater{
public:
    bool operator()(const T& t1,const T& t2)
    {
        return t1>t2;
    }
};

template<typename T,typename Compair=Less<T>>
class heap{
public:
    heap():_vector()
    {}
    heap(const MyVector<T>& v):_vector(v)
    {
        make_heap();
    }
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
        Compair cp;
        _vector.push_back(t);
        int i=_vector.size()-1;
        for(;i>=0;)
        {
            if(cp(_vector[i],_vector[i/2]))
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
    size_t size()
    {
        return _vector.size();
    }
    T pop_heap()
    {
        if(empty())
            throw new string("heap is null!");
        swap(_vector[0],_vector[_vector.size()-1]);
        T tmp=_vector[_vector.size()-1];
        _vector.pop_back();
        _JustDown(0,_vector.size());
        return tmp;
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
        Compair cp;
        if(n<=1)
            return;
        if(s>=n)
            return;
        int i;
        for(i=s;i<n;)
        {
            if(i*2+2<n)
            {
                int select=cp(_vector[i*2+1],_vector[i*2+2])?i*2+1:i*2+2;
                select=cp(_vector[select],_vector[i])?select:i;
                if(i!=select)
                {
                    swap(_vector[i],_vector[select]);
                    i=select;
                }
                else
                {
                    break;
                }
            }
            else if(i*2+1<n)
            {
                if(cp(_vector[i*2+1],_vector[i]))
                    swap(_vector[i],_vector[i*2+1]);
                i=i*2+1;
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
