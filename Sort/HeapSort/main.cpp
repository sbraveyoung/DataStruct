#include<iostream>
#include<vector>
#include"../include/func.h"
using namespace std;

//最大堆
template<typename T>
void AdjustDown(vector<T>& v,int length,int s)
{
    int i;
    int MinChild;
    for(i=s;i<length;)
    {
        if(i*2+1<length)
        {
            MinChild=i;
            if(compair(v[i*2+1],v[i*2])==-1)
                MinChild=i*2;
            else
                MinChild=i*2+1;
            if(compair(v[i],v[MinChild])==-1)
            {
                swap(v[i],v[MinChild]);
                i=MinChild;
            }
            else
            {
                break;
            }
        }
        else if(i*2<length)
        {
            if(compair(v[i],v[i*2])==-1)
            {
                swap(v[i],v[i*2]);
            }
            i=i*2;
        }
        else
        {
            i*=2;
        }
    }
}

template<typename T>
void HeapSort(vector<T>& v)
{
    int i,length=v.size();
    for(i=(length+1)/2;i>0;--i)
    {
        AdjustDown(v,length,i);
    }
    while(length>1)
    {
        swap(v[1],v[length-1]);
        length--;
        AdjustDown(v,length,1);
    }
}

//--------测试代码------------

void test()
{
    vector<int> v;
    int arr[]={0,4,2,6,3,2,65,6768,34,2,65,767,34,23,541,874,3,76,4,2};//0为占位符
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    for(i=1;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    HeapSort(v);
    for(i=1;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
