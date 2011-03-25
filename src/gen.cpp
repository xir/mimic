#include "gen.h"
#include "print.h"

void genKey(list<string> & key, list<string> & startkey, vector<string> & words,
    const unsigned int numwords)
{
  for (unsigned int j = 0;j<numwords;++j)
    key.push_back(words[j]);
  startkey = key;
}

void genWordOrder(map<list<string>, vector<string> > & wordorder,
    const vector<string> & words, list<string> & key, const unsigned int numwords)
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

void genOutput(list<string> & startkey,
    map <list<string>, vector<string> > & wordorder)
{
  srand (time(NULL));
  print(startkey);
  for (int k = 0; k<100000; ++k)
  {
    int valsize =wordorder[startkey].size();
    if (valsize == 0)
    {
      cout << endl;
      cout << "------------" << endl;
      cout << "No more data" << endl;
      break;
    }
    string place = wordorder[startkey].at(rand()%(valsize));
    startkey.pop_front();
    startkey.push_back(place);
    cout << place << " ";
  }
}
