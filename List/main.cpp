#include"MyList.h"

void test()
{
    List<int> mylist;
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        mylist.push_back(arr[i]);
        mylist.push_front(arr[i]);
        Node<int>* s=new Node<int>(arr[i]);
        mylist.push_front(s);
        s=new Node<int>(arr[i]);
        mylist.push_back(s);
    }
    mylist.print();
    cout<<"begin():"<<mylist.begin()->data<<endl;
    cout<<"end():"<<mylist.end()->data<<endl;
    if(mylist.empty())
        cout<<"empty!"<<endl;
    else
        cout<<"not empty!"<<endl;
    cout<<"size():"<<mylist.size()<<endl;
    cout<<"pop_back():"<<endl;
    mylist.pop_back();
    mylist.print();
    cout<<"pop_front():"<<endl;
    mylist.pop_front();
    mylist.print();
    cout<<"insert(5,20):"<<endl;
    mylist.insert(5,20);
    mylist.print();
    cout<<"insert(5,Node(10))"<<endl;
    Node<int>* s=new Node<int>(10);
    mylist.insert(5,s);
    mylist.print();
    cout<<"erase(10):"<<endl;
    mylist.erase(10);
    mylist.print();
    cout<<"erase(5):"<<endl;
    mylist.erase(5);
    mylist.print();
}

int main()
{
    test();
    return 0;
}
