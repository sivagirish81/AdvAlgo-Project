#include <bits/stdc++.h>

unsigned int djb2(string str) 
{
    unsigned int hash = 5381;
    for (auto i = str.begin(); i != str.end(); i++) 
    {
        hash = ((hash << 5) + hash) + *i;
    }
    return hash;
}
