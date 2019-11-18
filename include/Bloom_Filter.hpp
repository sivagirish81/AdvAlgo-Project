#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned int (*Hash_Functions)(string);

class Bloom_Filter
{
public:
    /*Get the optimal number of hash functions that have to be used*/
    virtual int set_num_hash(int,int) = 0;

    virtual int get_num_hash() = 0;

    /*Get the size of the hash table to be used*/
    virtual int set_size(int,float) = 0;

    virtual int get_size() = 0;
    
    /*Set Array Containing Hash Functions*/
    void set_hash_functions(vector<Hash_Functions> Hashes);

    /*Insert item into filter*/
    virtual int insert(string) = 0;

    /*Check whether an element is in the set or not*/
    virtual bool Check(string) = 0;

    /*Various Hash Functions*/
    
};