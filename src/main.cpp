/* n-gram generator and frequency analyser
 * generates an n-gram and calculates the mean intervals between words and
 * the variance of the intervals.
 */

#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<string>

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

  testWord test;
  cout << "Sentence length is: "<< sentence.size() << endl;
  string yesno;
  cout << "Would you like to print the sentence? (y/n)";
  while(1)
  {
    getline (cin, yesno);
    if (yesno == "y")
    {
      print(sentence);
      break;
    }
    else if (yesno == "n")
      break;
    else
      cout << "Please enter (y/n):";
  }

  string input;
  while (input != "0")
  {
    cout << "Enter word to search for (0 to quit):" << endl;
    getline (cin,input);
    if (input!= "0")
    {
      strLower(input);
      test.outputVariance(sentence,input);
      cout << endl;
    }
  }
  return 0;
}
