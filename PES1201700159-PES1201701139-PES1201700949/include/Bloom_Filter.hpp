#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned int (*Hash_Functions)(string);

class Bloom_Filter
{
public:
    /*Get the optimal number of hash functions that have to be used*/
   
    virtual int set_size() = 0;

    
    void set_hash_functions(vector<Hash_Functions> Hashes);

    /*Insert item into filter*/
    virtual int insert(string) = 0;

    /*Check whether an element is in the set or not*/
    virtual bool Check(string) = 0;

    /*Various Hash Functions*/
    
};