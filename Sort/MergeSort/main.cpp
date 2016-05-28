#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include"../include/func.h"
using namespace std;

#define NUMBERS 10000
#define FILENUMS 100

template<typename T>
void Merge(vector<T>& v,int left,int mid,int right,vector<T>& tmp)
{
    int i=left,j=mid+1;
    int k=left;
    while(i<=mid && j<=right)
    {
        if(compair(v[i],v[j])==1)
        {
            tmp[k++]=v[j++];
        }
        else
        {
            tmp[k++]=v[i++];
        }
    }
    while(i<=mid)
    {
        tmp[k++]=v[i++];
    }
    while(j<=right)
    {
        tmp[k++]=v[j++];
    }
    for(i=left;i<=right;++i)
    {
        v[i]=tmp[i];
    }
}

template<typename T>
void _MergeSort(vector<T>& v,int left,int right,vector<T>& tmp)
{
    if(left==right)
    {
        return;
    }
    _MergeSort(v,left,left+(right-left)/2,tmp);
    _MergeSort(v,left+(right-left)/2+1,right,tmp);
    Merge(v,left,left+(right-left)/2,right,tmp);
}

template<typename T>
void MergeSort(vector<T>& v)
{
    vector<T> tmp;
    tmp.resize(v.size());
    _MergeSort(v,0,v.size()-1,tmp);//闭区间
}


void _MergeSort_file(FILE* file,FILE* newfile,int number)
{
    if(number<=NUMBERS/FILENUMS)//只有一个文件
        return;
    //_MergeSort_file(file,);
    //FILE* newfile=NULL;
    //int i,j;
    //char str[13];
    //int num;
    //for(i=0;i<FILENUMS;i++)
    //{
    //    sprintf(str,"newfile%d.txt",i);
    //    newfile=fopen(str,"w");
    //    for(j=0;j<NUMBERS/FILENUMS;j++)
    //    {
    //        //fread(&num,13,sizeof(char),file);
    //        fgets(str,13,file);
    //        num=atoi(str);
    //        sprintf(str,"%d\n",num);
    //        fwrite(str,sizeof(char),strlen(str),newfile);
    //    }
    //    fclose(newfile);
    //}
}

void MergeSort_file(FILE* file)
{
    FILE* newfile=fopen("./newfile.txt","w");
    _MergeSort_file(file,newfile,NUMBERS);
}

//-------测试代码--------
void test()
{
    vector<int> v;
    int arr[]={4,2,6,3,2,65,6768,34,2,65,767,34,23,541,874,3,76,4,2};
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    for(i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    MergeSort(v);
    for(i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void test2()
{
    //生成随机数
    int srand(time(NULL));
    FILE* file=fopen("./number.txt","w");
    int i;
    int num;
    char str[13];
    memset(str,' ',sizeof(str));
    for(i=0;i<NUMBERS;++i)
    {
        num=rand();
        sprintf(str,"%d\n",num);
        fwrite(str,sizeof(char),strlen(str),file);
    }
    fclose(file);

    //排序
    file=fopen("./number.txt","r");
    FILE* newfile=fopen("./newnumber.txt","w");
    MergeSort_file(file);
    fclose(file);
    fclose(newfile);
}

int main()
{
    //test();//简单测试
    test2();//对外存的归并排序
    return 0;
}
