#include<iostream>
#include"Stack.h"
using namespace std;

//------测试代码---------
void test()
{
    MyStack<int> s;
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        s.push(arr[i]);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
