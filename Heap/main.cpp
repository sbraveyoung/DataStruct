#include<iostream>
#include"Heap.h"
using namespace std;

void test()
{
    heap<int> h;
    int arr[]={4,2,6,3,63,4,6,89,96,3,2};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        h.push_heap(arr[i]);
    }
    h.Print();
    h.make_heap();
    h.Print();
    h.sort_heap();
    h.Print();
}

int main()
{
    test();
    return 0;
}
