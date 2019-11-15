
#include "../include/Bloom-Filter.hpp"
#include <bits/stdc++.h>
#include <iostream>

#define M 1024

using namespace std;

class Bloom_Filter_Implementation : public Bloom_Filter
{
    private :
        int size;
        int num_of_hash;
        float false_Prob;
        int item_count;
        bitset<M> Bloom_array;
    public :
        Bloom_Filter_Implementation(int , float);
        int get_num_hash(int , int);
        int get_size(int , float);
        int insert(char*);
        bool Check(char*);
        ~Bloom_Filter_Implementation();
};

Bloom_Filter_Implementation::Bloom_Filter_Implementation(int items_count,float FP)
{
    size=0;
    num_of_hash=0;
    false_Prob=FP;
    item_count=items_count;
}
int Bloom_Filter_Implementation::get_num_hash(int n,int m)
{
    return int((m/n)*log(2));
}

int Bloom_Filter_Implementation::get_size(int n,float p)
{
    return int(-1*(n*log(p))/(pow(log(2),2)));
}

int Bloom_Filter_Implementation::insert(char* txt)
{

}

bool Bloom_Filter_Implementation::Check(char* txt)
{

}