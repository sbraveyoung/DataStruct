#include<iostream>
#include<vector>
using namespace std;

template<typename T>
int compair(const T& t1,const T& t2)
{
    if(t1==t2)
        return 0;
    else if(t1<t2)
        return -1;
    else
        return 1;
}

template<>
int compair(const float& t1,const float& t2)
{
    if(t1-t2>-0.00001 && t1-t2<0.00001)
        return 0;
    else if(t1-t2<-0.00001)
        return -1;
    else
        return 1;
}

template<typename T>
void BubbleSort(vector<T>& v)
{
    int length=v.size();
    int i,j;
    for(i=0;i<length;++i)
    {
        for(j=0;j<length-i-1;++j)
        {
            if(1==compair(v[j],v[j+1]))
            {
                std::swap(v[j],v[j+1]);
            }
        }
    }
}

//--------测试代码------------

void test()
{
    vector<int> v;
    int arr[]={4,2,6,3,2,65,6768,34,2,65,767,34,23,541,874,3,76,4,2};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    BubbleSort(v);
    for(i=0;i<v.size();++i)
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
