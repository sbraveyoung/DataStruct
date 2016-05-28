#ifndef _VECTOR_
#define _VECTOR_

#include<iostream>
#include<assert.h>
#include<memory.h>
using namespace std;

template<typename T>
class MyVector{
public:
    MyVector()
    {
        _array=new T[1];
        _size=0;
        _capacity=1;
    }
    ~MyVector()
    {
        delete[] _array;
        _array=NULL;
        _capacity=0;
        _size=0;
    }
    MyVector(const MyVector<T>& v)
    {
        v._array=new T[this->_capacity];
        memmove(v._array,this->_array,sizeof(T)*this->_size);
        v._capacity=_capacity;
        v._size=_size;
    }
    const MyVector& operator=(const MyVector<T>& v)
    {
        if(&v!=this)
        {
            T* tmp=new T[this->_capacity];
            memmove(tmp,this->_array,sizeof(T)*this->_size);
            swap(tmp,_array);
            delete[] tmp;
        }
    }
    void push_back(const T& t)
    {
        if(_size==_capacity)
            _Increase();
        _array[_size++]=t;
    }
    void push_front(const T& t)
    {
        if(_size==_capacity)
            _Increase();
        memmove(_array,_array+1,sizeof(T)*_size++);
        _array[0]=t;
    }
    void pop_back()
    {
        if(_size>0)
            _size--;
    }
    void pop_front()
    {
        if(_size>0)
            memmove(_array+1,_array,sizeof(T)*--_size);
    }
    T& operator[](size_t pos)
    {
        assert(pos<_size);
        return _array[pos];
    }
private:
    void _Increase()
    {
        _capacity*=2;
        T* tmp=new T[_capacity];
        memmove(tmp,_array,sizeof(T)*_size);
        swap(tmp,_array);
        delete []tmp;
    }
private:
    T* _array;
    size_t _capacity;
    size_t _size;
};
#endif
