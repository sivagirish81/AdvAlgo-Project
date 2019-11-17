#include "src/Bloom_Filter.cpp"
#include "include/Bloom_Filter.hpp"
#include <iostream>

using namespace std;

int main()
{
    Bloom_Filter_Implementation Bloom;
    int n;
    cin >> n;   //Total number of items
    int p;
    cin >> p;   //False Postive probability
    Bloom.set_size(n,p);
    Bloom.set_num_hash(n,p);

}