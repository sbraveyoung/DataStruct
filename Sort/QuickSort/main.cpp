#include<iostream>
#include<vector>
#include"../include/func.h"
using namespace std;

//划分
//template<typename T>
//int Partition(vector<T>& v,int left,int right)
//{
//    if(v.size()<=1 || left>=right-1)
//        return left;
//    T tmp=v[left];
//    int i=left,j=right-1;
//    while(i<j)
//    {
//        while(i<j && -1!=compair(v[j],tmp))
//            j--;
//        swap(v[j],v[i]);
//        while(i<j && 1!=compair(v[i],tmp))
//            i++;
//        swap(v[i],v[j]);
//    }
//    return i;
//}


//另一种划分方法，单向移动，所以可以对单链表进行排序
template<typename T>
int Partition(vector<T>& v,int left,int right)
{
    if(v.size()<=0 || left>=right-1)
        return left;
    int cur=left,prev=left-1;
    while(cur<right-1)
    {
        while(cur<right-1 && compair(v[cur],v[right-1])!=-1)
            cur++;
        if(cur<right-1)
        {
            prev++;
            swap(v[cur],v[prev]);
            cur++;
        }
    }
    ++prev;
    swap(v[prev],v[right-1]);
    return prev;
}

//快速排序
template<typename T>
void QSort(vector<T>& v,int left,int right)
{
    if(v.size()<=0 || left>=right-1)
        return;
    int mid=Partition(v,left,right);
    QSort(v,left,mid);
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
    for(i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
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
