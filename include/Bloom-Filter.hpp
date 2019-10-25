#include <iostream>
#include <vector>

using namespace std;

class Bloom_Filter
{
public:
    /*Get the optimal number of hash functions that have to be used*/
    virtual int get_num_hash(int,int) = 0;

    /*Get the size of the hash table to be used*/
    virtual int get_size(int,int) = 0;

    /*Insert item into filter*/
    virtual int insert(char*);

    /*Check whether an element is in the set or not*/
    virtual bool Check(char*);

    /*Various Hash Functions*/
    virtual int Murmur3(char*);

};