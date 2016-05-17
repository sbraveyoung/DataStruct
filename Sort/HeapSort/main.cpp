#include<iostream>
#include<vector>
#include"../include/func.h"
using namespace std;

template<typename T>
void AdjustDown(vector<T>& v,int s)
{
    int length=v.size();
    int i;
    int mi;
    for(i=s;i<length;i*=2)
    {
        if(i*2+1<length)
        {
            mi=min(v,i,i*2,i*2+1);
        }
        else if(i*2<length)
        {
            mi=v[i]<v[i*2]?i:i*2;
        }
        else
        {
            mi=i;
        }
        swap(v[i],v[mi]);
    }
}

template<typename T>
void HeapSort(vector<T>& v)
{
    int i,length=v.size();
    for(i=length/2;i>=0;--i)
    {
        AdjustDown(v[i]);
    }
}

//--------测试代码------------

void test()
{
    vector<int> v;
    int arr[]={4,2,6,3,2,65,6768,34,2,65,767,34,23,541,874,3,76,4,2};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    BubbleSort(v);
    for(i=0;i<v.size();++i)
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
