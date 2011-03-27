/* n-gram generator and frequency analyser
 * generates an n-gram and calculates the mean intervals between words and
 * the variance of the intervals.
 */

/* Notes
 * If the last word of the input is the first occurence of that word, 
 * generation of the 1-gram sentence will probably get cut short.
 * To omit the word would not be in keeping with the frequency of occurences
 * of words after the previous word.
 * Similar problems can occur when dealing with higher order n-grams where 
 * you can get stuck on a path that leads to the end of the file and
 * terminates. 
 */

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
#include "strfunc.h"

using namespace std;

int main( int argc, char* argv[])
{
  unsigned int numwords;
  vector<string> words;

  readCommandLine(argc, argv, words, numwords);

  map<list<string>, vector<string> > wordorder;
  list<string> key, startkey;
  vector<string> sentence;
  if (numwords==0)
    sentence=words;
  else
  {
    genKey(key, startkey, words, numwords);
    genWordOrder(wordorder, words, key, numwords);
    genOutput(startkey, wordorder, sentence);
  }

  /*
  list<string> shor;
  shor.push_back("interval");
  print(wordorder[shor]);
  */
  testWord test;
  cout << "Sentence length is: "<< sentence.size() << endl;
  string lst;
  cout << "Enter word to search for (0 to quit):" << endl;
  while (lst != "0")
  {
    getline (cin,lst);
    if (lst!= "0")
      strLower(lst);
      test.outputVariance(sentence,lst);
  }
  return 0;
}

