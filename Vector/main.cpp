#include"Vector.h"
#include<iostream>
using namespace std;

void test()
{
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    int i;
    MyVector<int> v;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
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
