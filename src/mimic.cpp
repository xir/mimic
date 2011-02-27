//ABSOLUTELY NO WARRANTY

#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<map>
#include<list>
#include<vector>
#include<string>

using namespace std;
typedef vector<string> vs;
typedef list<string> ls;
typedef map <ls, vs > mlv;

int readCommandLine(int argc, char* argv[], vs & words, int & numwords);
void usage();
vs read(const char* filename);
void print(const vs & v);
void print(ls & l);
void genKey(ls & key, ls & startkey, vs & words, int numwords);
void genWordOrder(mlv & wordorder, const vs & words, ls & key, const int numwords);
void genOutput(ls & startkey, mlv & wordorder);


int main( int argc, char* argv[])
{
  int numwords;
  vs words;

  readCommandLine(argc, argv, words, numwords);

  mlv wordorder;
  mlv::const_iterator end = wordorder.end();
  ls key, startkey;

  genKey(key, startkey, words, numwords);

  genWordOrder(wordorder, words, key, numwords);

  genOutput(startkey, wordorder);

  cout << endl;
  return 0;
}

int readCommandLine(int argc, char* argv[], vs & words, int & numwords)
{
  if (argc==2 || argc==3)
  {
    if (argc==3)
    {
      words=read(argv[2]);
    }
    else if (argc==2)
    {
      words = read("Example.txt");
    }
    if (atoi(argv[1])<1 || atoi(argv[1])>words.size()-1)
      numwords = 1;
    else
      numwords=atoi(argv[1]);
    return 0;
  }
  else
  {
    usage();
    exit(1);
  }
}

void usage()
{
    cout << "usage: ./mimic [integer n>0:default=1] [filename:default=Example.txt]"<< endl;
    cout << "for n =:";
    cout << "0 - output words based on their frequency"<< endl;
    cout << "1 - output words based on their frequency of occuring after 1 previous word" << endl;
    cout << "2 - output words based on their frequency of occuring after 2 previous words" << endl;
    cout << "n - output words based on their frequency of occuring after n previous words" << endl;
}

vs read(const char* filename)
{
  ifstream file(filename);
  if (file.good())
  {
    vs words;
    while(!file.eof())
    {
      string word;
      file>>word;
      if(!file.eof())
        words.push_back(word);
    }
    file.close();
    return words;
  }
  else 
    cout << "Error opening file" << endl;
    cout << "Omit the second argument to use the default file" << endl;
    exit(2);
}

void print(const vs & v)
{
  cout<<"[";
  for(unsigned int i=0;i<v.size() ;++i)
  {
    cout<<v.at(i);
    if(i!=v.size()-1)
      cout<<" ";
    else
      cout<<"]";
  }
  cout<<endl;
  return;
}

void print(ls & l)
{
  for (ls::iterator iit = l.begin(); iit != l.end(); ++iit)
    cout << *iit << " ";
  return;
}

void genKey(ls & key, ls & startkey, vs & words, int numwords)
{
  for (unsigned int j = 0;j<numwords;++j)
    key.push_back(words[j]);
  startkey = key;
}

void genOutput(ls & startkey, mlv & wordorder)
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

void genWordOrder(mlv & wordorder, const vs & words, ls & key, const int numwords)
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
