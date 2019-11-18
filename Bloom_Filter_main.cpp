#include "src/Bloom_Filter.cpp"
#include "src/Hash_Functions/Hasher.cpp"
#include "Input.cpp"

int main()
{
    Bloom_Filter_Implementation Bloom;
    int n;
    cin >> n;   //Total number of items
    int p;
    cin >> p;   //False Postive probability
    Bloom.set_size(n,p);
    vector<Hash_Functions> Hash;
    Hash.push_back(sdbm);
    Hash.push_back(djb2);
    Hash.push_back(DEKHash);
    Hash.push_back(APHash);
    Hash.push_back(BKDRHash);
    Hash.push_back(RSHash);
    Hash.push_back(JSHash);
    Hash.push_back(ELFHash);
    Bloom.set_hash_functions(Hash);
    //read_csv();
    ifstream file("spam.txt");
    string str;
    while (getline(file,str))
    {
        Bloom.insert(str);
    }
    vector<string> testSetOfStrings("https://files.uniblue.com/cm/downpanda/pcmechanicpm/banner1-pcm/setup",
                                    "https://files.uniblue.com/cm/terdwnldppc/pcmechanicpm/se_01-cast/setup",
                                    "https://firebasestorage.googleapis.com/v0/b/asw-yg-hqq.appspot.com/o"
                                    "tumblr.com",
                                    "flickr.com",
                                    "github.com",
                                    "w3.org");
    for (int i=0;i<testSetOfStrings.size();i++)
    {
        cout << Bloom.Check(testSetOfStrings[i]) << endl;
    }
    return 0;
}