
#include "../include/Bloom_Filter.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef int (*Hash_Functions)(string);

class Bloom_Filter_Implementation : public Bloom_Filter
{
    private :
        int size;
        int num_of_hash;
        float false_Prob;
        int item_count;
        vector<bool> Bloom_array;
        vector<Hash_Functions> Hashes;
    public :
        Bloom_Filter_Implementation();
        int set_num_hash(int , int);
        int set_size(int , float);
        int insert(string);
        bool Check(string);
        ~Bloom_Filter_Implementation();
};

Bloom_Filter_Implementation::Bloom_Filter_Implementation()
{
    size=0;
    num_of_hash=0;
    false_Prob=0;
    item_count=0;
}

int Bloom_Filter_Implementation::set_num_hash(int n,int m)
{ 
    return num_of_hash = int((m/n)*log(2));
}

int Bloom_Filter_Implementation::set_size(int n,float p)
{
    return size = int(-1*(n*log(p))/(pow(log(2),2)));
}

int Bloom_Filter_Implementation::insert(string txt)
{
    for (auto i = Hashes.begin();i!=Hashes.end;i++)
    {
        Bloom_array[(*i)(txt)]=true;
    }
}

bool Bloom_Filter_Implementation::Check(string txt)
{
    for (auto i = Hashes.begin();i!=Hashes.end;i++)
    {
        if (Bloom_array[(*i)(txt)]==false)
            return false;
    }
    return true;
}

Bloom_Filter_Implementation::~Bloom_Filter_Implementation()
{
    //Bloom_array=NULL;
    Bloom_array={};
    //Bloom_array=NULL;
}
