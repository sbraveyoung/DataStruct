#include"Deque.h"

void test()
{
    Deque<int> dq;
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        dq.push_back(arr[i]);
    }
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}

int main()
{
    test();
    return 0;
}
