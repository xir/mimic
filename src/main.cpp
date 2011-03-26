#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<string>

//debug only
#include "print.h"
#include "gen.h"
#include "read.h"
#include "test.h"

using namespace std;

int main( int argc, char* argv[])
{
  unsigned int numwords;
  vector<string> words;

  readCommandLine(argc, argv, words, numwords);

  vector<string> sentence;
  if (numwords==0)
    sentence=words;
  else
  {
    map<list<string>, vector<string> > wordorder;
    list<string> key, startkey;
    genKey(key, startkey, words, numwords);
    genWordOrder(wordorder, words, key, numwords);
    genOutput(startkey, wordorder, sentence);
  }

  testWord test;
  test.set("the");
  test.countOccurences(sentence);
  test.getVariance(sentence);
  test.printMean();
  cout << endl;
  test.printVariance();
  cout << endl;
  return 0;
}

