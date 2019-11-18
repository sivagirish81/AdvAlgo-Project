
#include "../include/Bloom_Filter.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int (*Hash_Functions)(string);

class Bloom_Filter_Implementation : public Bloom_Filter
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
        int set_num_hash(int , int);
        int get_num_hash();
        int set_size(int , float);
        int get_size();
        void set_hash_functions(vector<Hash_Functions> Hashes);
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
    //num_of_hash = int((m/n)*log(2));
    //cout << num_of_hash <<endl;
    //Bloom_array = new bool(100);
    num_of_hash=2;
    return 1;
}

int Bloom_Filter_Implementation::get_num_hash()
{ 
    return num_of_hash;
}

int Bloom_Filter_Implementation::set_size(int n,float p)
{
    //size = int(-1*(n*log(p))/(pow(log(2),2)));
    size=1024;
    Bloom_array  = (bool*)calloc(size,sizeof(bool));
    return 1;
}

int Bloom_Filter_Implementation::get_size()
{ 
    return size;
}

void Bloom_Filter_Implementation::set_hash_functions(vector<Hash_Functions> Hash_funcs)
{
    Hashes = Hash_funcs;
    return;
}

int Bloom_Filter_Implementation::insert(string txt)
{
    /*
    cout << txt << endl;
    cout << (Hashes[0])(txt) <<endl;
    cout << (Hashes[1])(txt) <<endl;
    cout << "************" <<endl;
    */
    for (auto i = Hashes.begin();i!=Hashes.end();i++)
    {
        Bloom_array[((*i)(txt))%1024]=true;
    }
}

bool Bloom_Filter_Implementation::Check(string txt)
{
    for (auto i = Hashes.begin();i!=Hashes.end();i++)
    {
        if (Bloom_array[((*i)(txt))%1024]==false)
            return false;
    }
    return true;
}

Bloom_Filter_Implementation::~Bloom_Filter_Implementation()
{
    Bloom_array={};
}
