#include "../../include/Bloom_Filter.hpp"

int sdbm(string str) 
{
    int hash = 0;
    for (auto i = str.begin(); i != str.end(); i++) 
    {
        hash = ((hash << 6) + (hash << 16) - hash) + *i;
    }
    return hash;
}