#include<iostream>
#include<vector>
#include"Heap.h"
using namespace std;

void test1()
{
    heap<int> h;
    int arr[]={4,2,6,3,63,4,6,89,96,3,2};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        h.push_heap(arr[i]);
    }
    h.Print();
    h.sort_heap();
    h.Print();
}

//GetTopK:最小前K个数
void test2()
{
    //生成10000000个数
    int i;
    vector<int> v;
    srand(time(NULL));
    for(i=0;i<10000000;++i)
    {
        v.push_back(rand());
    }

    int k=3;
    heap<int> h;
    h.make_heap();
    for(i=0;i<k;++i)
    {
        h.push_heap(v[i]);
    }
    for(;i<10000000;++i)
    {
        if(v[i]<h.top())
        {
            h.pop_heap();
            h.push_heap(v[i]);
        }
    }
    h.Print();
}

int main()
{
    //test1();
    test2();
    return 0;
}
