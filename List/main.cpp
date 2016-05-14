#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    Node(const T& d=T()):data(d),prev(NULL),next(NULL)
    {}
public:
    T data;
    Node* prev;
    Node* next;
};

template<typename T>
class List{
public:
    List()
private:
    Node<T>* front;
    Node<T>* tail;
    size_t size;
};

int main()
{
    return 0;
}
