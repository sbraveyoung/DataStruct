#include<iostream>
#include<vector>
using namespace std;
#include"../include/func.h"

//冒泡排序
//template<typename T>
//void BubbleSort(vector<T>& v)
//{
//    int length=v.size();
//    int i,j;
//    for(i=0;i<length;++i)
//    {
//        for(j=0;j<length-1;++j)
//        {
//            if(1==compair(v[j],v[j+1]))
//            {
//                std::swap(v[j],v[j+1]);
//            }
//        }
//    }
//}

//改进一:如果一趟排序中没有进行交换，则表明排序完成
//template<typename T>
//void BubbleSort(vector<T>& v)
//{
//    bool flag=true;
//    int length=v.size();
//    int i,j;
//    for(i=0;i<length;++i)
//    {
//        flag=true;
//        for(j=0;j<length-1;++j)
//        {
//            if(1==compair(v[j],v[j+1]))
//            {
//                flag=false;
//                std::swap(v[j],v[j+1]);
//            }
//        }
//        if(flag==true)
//            break;
//    }
//}

//改进二:每一趟排序，都可将一个当前序列中最大的值"冒泡"到最后面，所以下一次只需要进行到这里就可以结束了
template<typename T>
void BubbleSort(vector<T>& v)
{
    int length=v.size();
    int i,j;
    for(i=0;i<length;++i)
    {
        for(j=0;j<length-i-1;++j)
        {
            if(1==compair(v[j],v[j+1]))
            {
                std::swap(v[j],v[j+1]);
            }
        }
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
