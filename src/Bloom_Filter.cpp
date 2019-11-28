
#include "../include/Bloom_Filter.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int (*Hash_Functions)(string);

class Bloom_Filter_Implementation 
{
    private :
        int size;
        int num_of_hash;
        float false_Prob;
        int item_count;
        bool* Bloom_array;
        vector<Hash_Functions> Hashes;
    public :
        Bloom_Filter_Implementation();
        int set_size();
        void set_hash_functions(vector<Hash_Functions> Hashes);
        int insert(string);
        bool Check(string);
        ~Bloom_Filter_Implementation();
};

Bloom_Filter_Implementation::Bloom_Filter_Implementation()
{
    size=0;
    num_of_hash=8;
    false_Prob=0;
    item_count=0;
}

int Bloom_Filter_Implementation::set_size()
{
    //size = int(-1*(n*log(p))/(pow(log(2),2)));
    size=551238;
    Bloom_array  = (bool*)calloc(size,sizeof(bool));
    return 1;
}

void Bloom_Filter_Implementation::set_hash_functions(vector<Hash_Functions> Hash_funcs)
{
    Hashes = Hash_funcs;
    return;
}

int Bloom_Filter_Implementation::insert(string txt)
{
    for (auto i = Hashes.begin();i!=Hashes.end();i++)
    {
        Bloom_array[((*i)(txt))%size]=true;
    }
    return 0;
}

bool Bloom_Filter_Implementation::Check(string txt)
{
    for (auto i = Hashes.begin();i!=Hashes.end();i++)
    {
        if (Bloom_array[((*i)(txt))%size]==false)
            return false;
    }
    return true;
}

Bloom_Filter_Implementation::~Bloom_Filter_Implementation()
{
    Bloom_array={};
}
