#ifndef gen_h
#define gen_h

#include<list>
#include<string>
#include<vector>
#include<map>
using namespace std;

void genKey(list<string> & key, list<string> & startkey,
    vector<string> & words, const unsigned int numwords);
void genWordOrder(map <list<string>, vector<string> > & wordorder,
    const vector<string> & words, list<string> & key,
    const unsigned int numwords);
void genOutput(list<string> & startkey,
    map <list<string>, vector<string> > & wordorder,
    vector<string> &sentence);

#endif
