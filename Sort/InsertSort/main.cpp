#include<iostream>
#include<vector>
#include"../include/func.h"
using namespace std;

//直接插入排序
//template<typename T>
//void InsertSort(vector<T>& v)
//{
//    if(v.size()<=1)
//        return;
//    T tmp;
//    int i,j;
//    int length=v.size();
//    for(i=1;i<length;++i)
//    {
//        tmp=v[i];
//        for(j=i-1;j>=0;--j)
//        {
//            if(1==compair(v[j],tmp))
//            {
//                v[j+1]=v[j];
//            }
//            else
//            {
//                break;
//            }
//        }
//        v[j+1]=tmp;
//    }
//}

//二分插入排序
//仅仅是减少了比较的次数，并没有减少移动的次数
//template<typename T>
//void InsertSort(vector<T>& v)
//{
//    if(v.size()<=1)
//        return;
//    T tmp;
//    int i;
//    int left,right,mid;
//    int length=v.size();
//    for(i=1;i<length;++i)
//    {
//        tmp=v[i];
//        left=0,right=i-1;
//        while(left<=right)
//        {
//            mid=left+(right-left)/2;
//            if(compair(v[mid],tmp)==1)
//                right=mid-1;
//            else
//                left=mid+1;
//        }
//        for(right=i-1;right>=left;--right)
//        {
//            v[right+1]=v[right];
//        }
//        v[left]=tmp;
//    }
//}

//2路插入排序
template<typename T>
void InsertSort(vector<T>& v)
{
    if(v.size()<=1)
        return;
    T tmp;
    int i,j;
    int length=v.size();
    int left=0,right=0;
    vector<T> newv;
    newv.resize(length);
    newv[0]=v[0];
    for(i=1;i<length;++i)
    {
        tmp=v[i];
        if(1!=compair(tmp,newv[left]))
        {
            newv[++left]=tmp;
        }
        else if(-1!=compair(tmp,newv[right]))
        {
            if(right==0)
                right=length-1;
            else
                right--;
            newv[right]=tmp;
        }
        else
        {
            //此处还可以再优化，改为二分插入或2路插入
            for(j=left;j!=right;--j)
            {
                if(j==-1)
                    j=length-1;
                if(1!=compair(newv[j],tmp))
                {
                    if(j==length-1)
                        newv[0]=newv[length-1];
                    else
                        newv[j+1]=newv[j];
                }
                else
                {
                    break;
                }
            }
            left++;
            newv[j+1]=tmp;
        }
    }
    v.clear();
    for(i=left;i>=0;--i)
    {
        v.push_back(newv[i]);
    }
    for(i=length-1;i>=right;--i)
    {
        v.push_back(newv[i]);
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
