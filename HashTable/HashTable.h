#pragma once

#include<iostream>
#include<vector>
#include<list>
using namespace std;

//template<typename key_type,typename value_type>
//struct Pair<key_type,value_type>
//{
//    key_type _first;
//    value_type _second;
//};

template<typename key_type,typename value_type>
bool operator==(const pair<key_type,value_type>& p1,const pair<key_type,value_type>& p2)
{
    if(p1.first==p2.first)
        return true;
    return false;
}

template<typename key_type>
struct HashFunc{
    size_t operator()(const key_type* key)
    {
        return BKDRHash(key);
    }
    size_t BKDRHash(const key_type* str)
    {
        register size_t hash=0;
        while(size_t ch=(size_t)*str++)
        {
            hash=hash*131+ch;
        }
        return hash;
    }
};

template<typename key_type,typename value_type,typename Hash=HashFunc<key_type>>
class HashTable{
public:
    HashTable()
        :_size(0)
    {
        HashBase.resize(_GetNextSize());
    }
    bool Insert(const key_type& key,const value_type& value)
    {
        if(Find(key))
            return false;
        size_t index=_Hash(key);
        HashBase[index].insert(pair<key_type,value_type>(key,value));
        return true;
    }
    bool Find(const key_type& key)
    {
        size_t index=_Hash(key);
        if(find(HashBase[index].begin(),HashBase[index].end(),key)!=HashBase[index].end())
            return false;//the key has existed!
        return true;
    }

protected:
    size_t _Hash(const key_type& key)
    {
        Hash hs;
        return hs(key)%_size;
    }
    size_t _GetNextSize()
    {
        enum {__stl_num_primes=28};
        static const size_t __stl_prime_list[__stl_num_primes] =
        {
            53ul,         97ul,         193ul,       389ul,       769ul,
            1543ul,       3079ul,       6151ul,      12289ul,     24593ul,
            49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
            1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
            50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul, 
            1610612741ul, 3221225473ul, 4294967291ul
        };
        size_t size=HashBase.size();
        int i;
        for(i=0;i<__stl_num_primes;++i)
        {
            if(__stl_prime_list[i]>size)
                return __stl_prime_list[i];
        }
        return __stl_prime_list[__stl_num_primes-1];

    }
private:
    vector<list<pair<key_type,value_type> > > HashBase;
    size_t _size;
};
