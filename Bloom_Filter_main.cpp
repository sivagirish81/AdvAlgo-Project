#include "src/Bloom_Filter.cpp"
#include "include/Bloom_Filter.hpp"
#include "src/Hash_Functions/sdbm.cpp"
#include "src/Hash_Functions/djb2.cpp"

#include <iostream>

using namespace std;
typedef int (*Hash_Functions)(string);

int main()
{
    Bloom_Filter_Implementation Bloom;
    int n;
    cin >> n;   //Total number of items
    int p;
    cin >> p;   //False Postive probability
    Bloom.set_size(n,p);
    Bloom.set_num_hash(n,p);
    vector<Hash_Functions> Hash = {*sdbm,*djb2};
    Bloom.set_hash_functions(Hash);
    vector<string> setOfStrings({
        "Hello World!",
        "sweet potato",
        "C++",
        "alpha",
        "beta",
        "gamma"
    });
    for (int i=0;i<setOfStrings.size();i++)
    {
        Bloom.insert(setOfStrings[i]);
    }
    std::vector<std::string> testSetOfStrings({
        "Hello World!",
        "sweet potato",
        "C++",
        "alpha",
        "beta",
        "gamma",
        "delta",
        "where am i?",
        "foo",
        "bar"
    });
    for (int i=0;i<testSetOfStrings.size();i++)
    {
        cout << Bloom.Check(testSetOfStrings[i]) << endl;
    }
    return 0;
}