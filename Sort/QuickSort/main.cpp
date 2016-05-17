#include<iostream>
#include<vector>
#include"../include/func.h"
using namespace std;

//划分
template<typename T>
int Partition(vector<T>& v,int left,int right)
{
    if(v.size()<=1 || left>=right-1)
        return left;
    int i=left,j=right-1;
    T tmp=left;
    while(i<j)
    {
        while(i<j && 1!=compair(v[i],v[tmp]))
            i++;
        while(i<j && -1!=compair(v[j],v[tmp]))
            j--;
        swap(v[i],v[j]);
    }
    swap(v[i-1],v[tmp]);
    return i;
}

//快速排序
template<typename T>
void QSort(vector<T>& v,int left,int right)
{
    if(v.size()<=0 || left>=right-1)
        return;
    int mid=Partition(v,left,right);
    QSort(v,left,mid-1);
    QSort(v,mid+1,right);
}

template<typename T>
void QuickSort(vector<T>& v)
{
    QSort(v,0,v.size());//左闭右开
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
    QuickSort(v);
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
