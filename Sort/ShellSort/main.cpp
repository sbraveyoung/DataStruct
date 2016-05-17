#include<iostream>
#include<vector>
#include"../include/func.h"
using namespace std;

//希尔排序
template<typename T>
void InsertSort(vector<T>& v)
{
    T tmp;
    int i,j,gap,k;
    int length=v.size();
    for(gap=length/2;gap>0;gap/=2)
    {
        for(k=0;k<gap;++k)
        {
            for(i=k+gap;i<length;i+=gap)
            {
                T tmp=v[i];
                for(j=i-gap;j>=0;j-=gap)
                {
                    if(compair(v[j],tmp)==1)
                    {
                        v[j+gap]=v[j];
                    }
                    else
                    {
                        break;
                    }
                }
                v[j+gap]=tmp;
            }
        }
    }
}

//-----测试代码-----

void test()
{
    vector<int> v;
    int arr[]={4,2,6,3,2,65,6768,34,2,65,767,34,23,541,874,3,76,4,2};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    InsertSort(v);
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
