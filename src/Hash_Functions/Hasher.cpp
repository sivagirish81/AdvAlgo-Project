#include <bits/stdc++.h>
using namespace std;

// Rotative and additive hash function
unsigned int APHash(string str)
{
   unsigned int hash = 0xAAAAAAAA;
   unsigned int i    = 0;

   for (auto iter = str.begin(); iter != str.end(); iter++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ (*iter) * (hash >> 3)) :(~((hash << 11) + ((*iter) ^ (hash >> 5))));
   }
   return hash;
}

// hash * 33 +any constant
// Our case constant value = 5381
unsigned int djb2(string str) 
{
    unsigned int hash = 5381;
    for (auto i = str.begin(); i != str.end(); i++) 
    {
        hash = ((hash << 5) + hash) + *i;
    }
    return hash;
}

// hash(i-1) + 65599 + asc(string[i])
// 2^16 + 2^6 - 1 = 65599
unsigned int sdbm(string str) 
{
    unsigned int hash = 0;
    for (auto i = str.begin(); i != str.end(); i++) 
    {
        hash = ((hash << 6) + (hash << 16) - hash) + *i;
    }
    return hash;
}

// ((hash (i - 1) * 2 ^ 5 ) ^ (hash ( i -1 ) / 2 ^ 27)) ^ str [i]
unsigned int DEKHash(string str)
{
   unsigned int hash = str.size();
   unsigned int i    = 0;

   for (auto iter = str.begin(); iter != str.end(); iter++)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ (*iter);
   }
   return hash;
}

// Multiply hash(i-1) with 63689 + add the string
// Multiply a * b ^ n where a varies with every iteraion b ^ i times.
unsigned int RSHash(string str)
{   
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (auto iter = str.begin(); iter != str.end(); iter++)
   {
      hash = hash * a + (*iter);
      a    = a * b;
   }

   return hash;
}

// hash(i-1) * 2 ^ 4 + str[i]
// x = & the value of the hash with 0xF0000000L
// IF the value is not 0
// Then hash ^ x/2^24
// hash = hash & ~x
unsigned int ELFHash( string str)
{
   unsigned int hash = 0;
   unsigned int x    = 0;
   unsigned int i    = 0;

   for ( auto iter = str.begin(); iter != str.end(); iter++)
   {
      hash = (hash << 4) + (*iter);

      if ((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }

      hash &= ~x;
   }

   return hash;
}

// hash (i-1) ^ ( hash(i-1)*2^5 + str[i] + hash /4 )
//Start of with a random arbitrary constants
unsigned int JSHash( string str)
{
   unsigned int hash = 1315423911;
   unsigned int i    = 0;

   for (auto iter = str.begin(); iter != str.end(); iter++)
   {
      hash ^= ((hash << 5) + (*iter) + (hash >> 2));
   }

   return hash;
}

// Uses a random seed of 31 , 131 ,1313 ... so on to generate a random number
// Thereby hashing the given input 
unsigned int BKDRHash( string str)
{
   unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (auto iter = str.begin(); iter != str.end(); iter++)
   {
      hash = (hash * seed) + (*iter);
   }

   return hash;
}