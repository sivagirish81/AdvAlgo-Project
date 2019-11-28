#include "src/Bloom_Filter.cpp"
#include "src/Hash_Functions/Hasher.cpp"
#include "Input.cpp"

int main()
{
    Bloom_Filter_Implementation Bloom;
    Bloom.set_size();
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
    int total=0,total_mal=0,total_non_mal=0;
    cout<<"Inserting Malicious Urls into the Bloom Filter\n";
    while (getline(file,str))
    {
        Bloom.insert(str);
        total++;
        if(total%4000==0)cout<<"...\n";
        total_mal++;
    }
    cout<<endl;
    printf("%d Malicious Urls has been successfully inserted into the bloom filter\n",total);
    printf("Size occupied by Bloom filter %.3f KB\n\n",float(total/1024));
    file.clear();
    ifstream file1("spam.txt");
    cout<<"Sample URLs from the dataset:\n";
    int loop=0;
    while (getline(file1,str))
    {
        if(loop==5)break;
        cout<<str<<endl;
        loop++;
    }
    cout<<"_________________________________________________________________________________________________________________\n\n";
    cout<<"Testing The Bloom Filter\n";
    cout<<"_________________________________________________________________________________________________________________\n\n";
    cout<<"Bloom filter Result:\n"<<endl;
    ifstream test1("Norm.txt");
    string str_test1;
    int ind=0;
    vector<bool>result1;
    while(getline(test1,str_test1)){
        bool ret=Bloom.Check(str_test1);
        result1.push_back(ret);
        total++;
        total_non_mal++;
    }
    test1.clear();
    ifstream test2("spam.txt");
    string str_test2;
    ind=0;
    vector<bool>result2;
    while(getline(test2,str_test2)){
        bool ret=Bloom.Check(str_test2);
        result2.push_back(ret);
    }
     cout<<"_________________________________________________________________________________________________________________\n\n";
    printf("Total Actual Non Malicious URLs: %d\n\n",total_non_mal);
    printf("Filters as Malicious URLs: %d\n",count(result1.begin(),result1.end(),true));
    printf("True Positive : %f\n",float(count(result1.begin(),result1.end(),true)/(float)total_non_mal));
    cout<<endl;
    printf("Filters as Non-Malicious URLs: %d\n",count(result1.begin(),result1.end(),false));
    printf("False Negative : %f\n",float(count(result1.begin(),result1.end(),false)/total_non_mal));
    cout<<endl;
    cout<<"_________________________________________________________________________________________________________________\n\n";
    printf("Total Actual Malicious URLs: %d\n\n",total_mal);
    printf("Filters as Malicious URLs: %d\n",count(result2.begin(),result2.end(),true));
    printf("True Positive : %f\n",float(count(result2.begin(),result2.end(),true)/(float)total_mal));
    cout<<endl;
    printf("Filters as Non-Malicious URLs: %d\n",count(result2.begin(),result2.end(),false));
    printf("False Negative : %f\n",float(count(result2.begin(),result2.end(),false)/total_mal));
         cout<<"_________________________________________________________________________________________________________________\n\n";
    return 0;

}