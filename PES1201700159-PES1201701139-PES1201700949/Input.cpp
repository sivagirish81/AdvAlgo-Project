#include <bits/stdc++.h>
#include <fstream>
#include <iostream>

using namespace std;
void read_csv()
{
    fstream Urls;
    Urls.open("dataset.csv",ios::in);
    string line;
    string data;
	string prev;
    int count;
    ofstream spamfile;
    spamfile.open("spam.txt");
    ofstream truefile;
    truefile.open("Norm.txt");
    while (getline(Urls,line))
    {
        stringstream s(line);
        while (getline(s,data,','))
        {
            if(count == 0)
                prev = data;
            count++;
        }
        if(data == "1")
            spamfile << prev  << "\n";
        else
        {
            truefile << prev << "\n";
        }
        
        count=0;
    }
    spamfile.close();
    truefile.close();
}