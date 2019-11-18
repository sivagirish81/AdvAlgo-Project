#include <bits/stdc++.h>

unsigned int sdbm(string str) 
{
    unsigned int hash = 0;
    for (auto i = str.begin(); i != str.end(); i++) 
    {
        hash = ((hash << 6) + (hash << 16) - hash) + *i;
    }
    return hash;
}