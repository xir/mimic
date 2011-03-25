#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<cstdlib>
using namespace std;

#ifndef gen_h
#define gen_h
void genKey(list<string> & key, list<string> & startkey, vector<string> & words, 
    const unsigned int numwords);
void genWordOrder(map <list<string>, vector<string> > & wordorder, 
    const vector<string> & words, list<string> & key, const unsigned int numwords);
void genOutput(list<string> & startkey, 
    map <list<string>, vector<string> > & wordorder);

#endif