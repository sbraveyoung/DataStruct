#ifndef _FUNC_
#define _FUNC_
#include<iostream>
#include<vector>
using namespace std;
//模板函数只能将实现放在头文件里面，否则将不会被编译进包含它的文件里面

//模板函数，用于比较两个T类型的变量
template<typename T>
int compair(const T& t1,const T& t2)
{
    if(t1==t2)
        return 0;
    else if(t1<t2)
        return -1;
    else
        return 1;
}

//对上面模板函数的特化
template<>
int compair(const float& t1,const float& t2)
{
    if(t1-t2>-0.00001 && t1-t2<0.00001)
        return 0;
    else if(t1-t2<-0.00001)
        return -1;
    else
        return 1;
}

template<typename T>
int max(const vector<T>& v,int t1,int t2,int t3)
{
    if(1==compair(v[t1],v[t2]))
    {
        if(1==compair(v[t1],v[t3]))
        {
            return t1;
        }
        else
        {
            return t3;
        }
    }
    else
    {
        if(1==compair(v[t2],v[t3]))
        {
            return t2;
        }
        else
        {
            return t3;
        }
    }
}

template<typename T>
int min(const vector<T>& v,int t1,int t2,int t3)
{
    if(-1==compair(v[t1],v[t2]))
    {
        if(-1==compair(v[t1],v[t3]))
        {
            return t1;
        }
        else
        {
            return t3;
        }
    }
    else
    {
        if(-1==compair(v[t2],v[t3]))
        {
            return t2;
        }
        else
        {
            return t3;
        }
    }
}

#endif
