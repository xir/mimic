#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<map>
#include<list>
#include<vector>
#include<string>

using namespace std;

vector<string> read(string& fname);
void print(const vector<string> & v);

int main( int argc, char* argv[])
{
  int random_number;
  srand (time(NULL));

  string fname = "Example.txt";
  vector<string> words = read(fname);

  typedef map <list<string>, vector<string> > vlm;
  vlm wordorder;
  vlm::const_iterator end = wordorder.end();
  int wordssize = words.size();//no idea if the compiler does this anyway
  list<string> key, startkey;

  //int numwords = setnumwords(argc, argv[]);
  int numwords;

  if (argc < 2)
    numwords = 1;
  else 
    numwords = atoi(argv[1]);

  for (unsigned int j = 0;j<numwords;++j)
  {
    key.push_back(words[j]);
  }
  startkey = key;

  for (unsigned int i = 0; i<wordssize-numwords;++i)
  {
    key.pop_front();
    key.push_back(words[i+numwords-1]);
    wordorder[key].push_back(words[i+numwords]);
  }
  //for (vlm::const_iterator it = wordorder.begin(); it!= end; ++it)
  {
    //iprint((it->first), unique_words);
    //iprint((it->second), unique_words);
  }
  /* pick random key
   * print list
   * pop 
   * push print
   */
  for (list<string>::iterator iit = startkey.begin(); iit != startkey.end(); ++iit)
  {
    cout << *iit << " ";
  }
  for (int k = 0; k<100; ++k)
  {
    int valsize =wordorder[startkey].size();
    string place = wordorder[startkey].at(rand()%(valsize));
    startkey.pop_front();
    startkey.push_back(place);
    cout << place << " ";
     
  }
  cout << endl;
  return 0;
}

vector<string> read(string& fname)
{
  ifstream file("Example.txt");//Bodge
  vector<string> words;
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

//function to print a vector of strings

void print(const vector<string> & v)
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
