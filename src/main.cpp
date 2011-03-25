#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<map>
#include<list>
#include<vector>
#include<string>

//debug only
//#include "print.h"
#include "gen.h"
#include "read.h"

using namespace std;

int main( int argc, char* argv[])
{
  unsigned int numwords;
  vector<string> words;

  readCommandLine(argc, argv, words, numwords);

  map<list<string>, vector<string> > wordorder;
  list<string> key, startkey;

  genKey(key, startkey, words, numwords);

  genWordOrder(wordorder, words, key, numwords);

  genOutput(startkey, wordorder);

  cout << endl;
  return 0;
}

