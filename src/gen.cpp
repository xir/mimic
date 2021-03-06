/* Generates a map of a list of strings to a vector of strings being all the
 * words that follow the list of strings in the input text
 */

#include<cstdlib>
#include "gen.h"

using namespace std;

void genKey(list<string> & key, list<string> & startkey,
    vector<string> & words, const unsigned int numwords)
{
  if (numwords == 0)
    startkey.push_back(words[0]);
  else
  {
    for (unsigned int j = 0;j<numwords;++j)
      key.push_back(words[j]);
    startkey = key;
  }
}

void genWordOrder(map<list<string>, vector<string> > & wordorder,
    const vector<string> & words, list<string> & key,
    const unsigned int numwords)
{
  if (numwords != 0)
  {
    const int wordssize = words.size();
    for (unsigned int i = 0; i<wordssize-numwords-1;++i)
    {
      wordorder[key].push_back(words[i+numwords]);
      key.pop_front();
      key.push_back(words[i+numwords]);
    }
    wordorder[key].push_back(words[wordssize-1]);
  }
}

void genOutput(list<string> & startkey,
    map <list<string>, vector<string> > & wordorder,
    vector<string> & sentence)
{
  srand (time(NULL));
  int sentenceLength=100000;

  for (list<string>::iterator iit = startkey.begin(); iit != startkey.end();
      ++iit)
    sentence.push_back(*iit);
  for (int k = 0; k<sentenceLength; ++k)
  {
    int valsize = wordorder[startkey].size();
    if (valsize == 0)
      break;
    string place = wordorder[startkey].at(rand()%(valsize));
    startkey.pop_front();
    startkey.push_back(place);
    sentence.push_back(place);
  }
}
