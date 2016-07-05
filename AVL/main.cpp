#include<iostream>
#include"AVLTree.h"
using namespace std;

void testAVLTree()
{
    AVLTree<int, int> t1;
    int a1[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
    for (int  i = 0; i < sizeof(a1)/sizeof(int); ++i)
    {
        t1.Insert(a1[i], a1[i]);
    }
    cout<<"AAAAAAAAAAAAAAAAAAAAAAAAA"<<endl;

    t1.InOrder();

    AVLTree<int, int> t2;
    int a2[] = {164, 34, 7, 112, 92, 26, 18, 143, 152, 9, 21, 3, 123};
    for (int  i = 0; i < sizeof(a2)/sizeof(int); ++i)
    {
    t2.Insert(a2[i], a2[i]);
    }

    t2.InOrder();

    AVLTree<int, int> t3;
    int a3[] = {4, 2, 6, 1, 3, 5, 15, 7, 16, 14};
    for (int  i = 0; i < sizeof(a3)/sizeof(int); ++i)
    {
    t3.Insert(a3[i], a3[i]);
    }

    t3.InOrder();

    cout<<"t1是否平衡?:"<<t1.IsBalance()<<endl;
    cout<<"t2是否平衡?:"<<t2.IsBalance()<<endl;
    cout<<"t3是否平衡?:"<<t3.IsBalance()<<endl;
}

int main()
{
    testAVLTree();
    return 0;
}
