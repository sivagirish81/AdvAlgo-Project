#include "src/Bloom_Filter.cpp"
#include "src/Hash_Functions/sdbm.cpp"
#include "src/Hash_Functions/djb2.cpp"
#include "Input.cpp"

int main()
{
    /*
    Bloom_Filter_Implementation Bloom;
    int n;
    cin >> n;   //Total number of items
    int p;
    cin >> p;   //False Postive probability
    Bloom.set_size(n,p);
    //Bloom.set_num_hash(n,p);
    vector<Hash_Functions> Hash;
    Hash.push_back(sdbm);
    Hash.push_back(djb2);
    //cout << "a" << sdbm("a") << endl;
    
    Bloom.set_hash_functions(Hash);
    */
    read_csv();
    
    /*
    vector<string> setOfStrings({
        "Hello World!",
        "sweet potato",
        "C++",
        "alpha",
        "beta",
        "gamma"
    });
    */
   /*
    cout << setOfStrings[2] << endl;
    cout << Bloom.get_size() << endl;
    for (auto i : setOfStrings)
    {
        cout << i << endl;
        Bloom.insert(i);
    }
    /*
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
    */
   /*
    for (int i=0;i<testSetOfStrings.size();i++)
    {
        cout << Bloom.Check(testSetOfStrings[i]) << endl;
    }
    */
    return 0;
}