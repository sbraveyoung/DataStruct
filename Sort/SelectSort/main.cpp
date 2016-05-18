#include<iostream>
#include<vector>
#include"../include/func.h"
using namespace std;

//选择排序
//template<typename T>
//void SelectSort(vector<T>& v)
//{
//    if(v.size()<=1)
//        return;
//    int length=v.size();
//    int i,j;
//    for(i=0;i<length;++i)
//    {
//        for(j=i+1;j<length;++j)
//        {
//            if(-1==compair(v[j],v[i]))
//            {
//                swap(v[j],v[i]);
//            }
//        }
//    }
//}

//改进一:如果一趟排序中没有进行交换，则表明排序完成
//template<typename T>
//void SelectSort(vector<T>& v)
//{
//    if(v.size()<=1)
//        return;
//    bool flag=true;
//    int length=v.size();
//    int i,j;
//    for(i=0;i<length;++i)
//    {
//        flag=true;
//        for(j=i+1;j<length;++j)
//        {
//            if(-1==compair(v[j],v[i]))
//            {
//                flag=false;
//                swap(v[j],v[i]);
//            }
//        }
//        if(flag==true)
//            break;
//    }
//}

//改进二:在每一趟排序中进行双向选择
template<typename T>
void SelectSort(vector<T>& v)
{
    if(v.size()<=1)
        return;
    int length=v.size();
    int i,j;
    for(i=0;i<length;++i)
    {
        for(j=i+1;j<length-i;++j)
        {
            int ma=max(v,i,j,length-i-1);
            int mi=min(v,i,j,length-i-1);
            swap(v[i],v[mi]);
            if(1==compair(v[ma],v[length-i-1]))
                swap(v[length-i-1],v[ma]);
        }
    }
}

//-----测试代码------
void test()
{
    vector<int> v;
    int arr[]={10000,4,2,6,3,2,65,6768,34,2,65,767,34,23,541,874,3,76,4,2};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    SelectSort(v);
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
