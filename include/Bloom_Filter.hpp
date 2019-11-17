#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Bloom_Filter
{
public:
    /*Get the optimal number of hash functions that have to be used*/
    virtual int set_num_hash(int,int) = 0;

    /*Get the size of the hash table to be used*/
    virtual int set_size(int,float) = 0;

    /*Insert item into filter*/
    virtual int insert(string);

    /*Check whether an element is in the set or not*/
    virtual bool Check(string);

    /*Various Hash Functions*/

};