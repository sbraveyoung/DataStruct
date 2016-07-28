#include"BSTree.h"

void test()
{
    BSTree<int> bt;
    int arr[]={4,3,6,7,3,54,3,2,4,73,233};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        bt.insert(arr[i]);
    }
    bt.InOrder();
}

int main()
{
    test();
    return 0;
}
