#include<iostream>
using namespace std;

class ListIsEmpty{};
class ArgIsIll{};

template<typename T>
class Node{
public:
    Node(const T& d=T()):data(d),prev(NULL),next(NULL)
    {}
    ~Node()
    {}
private:
    Node(const Node& n);
    Node& operator=(const Node& n);
public:
    T data;
    Node* prev;
    Node* next;
};

template<typename T>
class List{
public:
    List():front(NULL),tail(NULL),cur_size(0)
    {}
    ~List()
    {
        while(!this->empty())
        {
            this->pop_front();
        }
    }
    //List& operator=(const List& l)
    //{}
    Node<T>* begin()
    {
        return front;
    }
    Node<T>* end()
    {
        return tail;
    }
    bool empty()
    {
        if(cur_size==0)
            return true;
        else
            return false;
    }
    size_t size()
    {
        return cur_size;
    }
    bool push_front(Node<T>* n)
    {
        if(this->empty())
        {
            front=tail=n;
        }
        else
        {
            n->next=front;
            front->prev=n;
            n->prev=tail;
            tail->next=n;
            front=n;
        }
        cur_size++;
        return true;
    }
    bool pop_front()throw (ListIsEmpty)
    {
        if(this->empty())
        {
            throw ListIsEmpty();
        }
        else if(this->size()==1)
        {
            delete front;
            front=tail=NULL;
        }
        else
        {
            Node<T>* s=front;
            front=front->next;
            front->prev=tail;
            tail->next=front;
            delete s;
        }
        cur_size--;
        return true;
    }
    bool push_front(const T& t)
    {
        Node<T> *s=new Node<T>(t);
        return push_front(s);
    }
    bool push_back(Node<T>* n)
    {
        if(this->empty())
        {
            front=tail=n;
        }
        else
        {
            tail->next=n;
            n->prev=tail;
            n->next=front;
            front->prev=n;
            tail=n;
        }
        cur_size++;
        return true;
    }
    bool pop_back()throw (ListIsEmpty)
    {
        if(this->empty())
        {
            throw ListIsEmpty();
        }
        else if(this->size()==1)
        {
            delete tail;
            front=tail=NULL;
        }
        else
        {
            Node<T>* s=tail;
            tail=tail->prev;
            front->prev=tail;
            tail->next=front;
            delete s;
        }
        cur_size--;
        return true;
    }
    bool push_back(const T& t)
    {
        Node<T> *s=new Node<T>(t);
        return push_back(s);
    }
    bool insert(size_t pos,Node<T>* n)throw (ArgIsIll)
    {
        if(pos>this->size())
        {
            throw ArgIsIll();
        }
        else if(pos==this->size())
        {
            return push_back(n);
        }
        else if(pos==0)
        {
            return push_front(n);
        }
        else
        {
            size_t i=0;
            Node<T>* cur=front;
            for(i=0;i<pos-1;++i)
            {
                cur=cur->next;
            }
            n->next=cur->next;
            cur->next->prev=n;
            n->prev=cur;
            cur->next=n;
            cur_size++;
            return true;
        }
    }
    bool insert(size_t pos,const T& t)throw (ArgIsIll)
    {
        Node<T>* s=new Node<T>(t);
        return insert(pos,s);
    }
    bool erase(size_t pos)
    {
        if(pos>this->size())
        {
            throw ArgIsIll();
        }
        else if(pos==this->size())
        {
            return pop_back();
        }
        else if(pos==0)
        {
            return pop_front();
        }
        else
        {
            size_t i=0;
            Node<T>* cur=front;
            for(i=0;i<pos-1;++i)
            {
                cur=cur->next;
            }
            cur->next->prev=cur->prev;
            cur->prev->next=cur->next;
            delete cur;
            cur_size--;
            return true;
        }
    }
    void print()const
    {
        Node<T>* cur=front;
        while(true)
        {
            cout<<cur->data<<" ";
            if(cur==tail)
                break;
            cur=cur->next;
        }
        cout<<endl;
    }
private:
    List(const List& l);
private:
    Node<T>* front;
    Node<T>* tail;
    size_t cur_size;
};

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
