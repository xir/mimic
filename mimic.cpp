#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<map>
#include<list>
#include<vector>
#include<string>

using namespace std;
//seems to be sort of working

vector<string> read();
void print(const vector<string> & v);
void print(list<string> & l);

int main( int argc, char* argv[])
{
  int random_number;
  srand (time(NULL));

  vector<string> words = read();

  typedef map <list<string>, vector<string> > vlm;
  vlm wordorder;
  vlm::const_iterator end = wordorder.end();

  int wordssize = words.size();
  list<string> key, startkey;

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
  //lprint(key);

  for (unsigned int i = 0; i<wordssize-numwords-1;++i)
  {
    wordorder[key].push_back(words[i+numwords]);
    //lprint(key);
    //cout << "\t";
    //print(wordorder[key]);
    key.pop_front();
    key.push_back(words[i+numwords]);
  }
  wordorder[key].push_back(words[wordssize-1]);
  //cout << wordorder[key].size();

  for (int k = 0; k<100000; ++k)
  {
    int valsize =wordorder[startkey].size();
    //lprint(startkey);
    //cout << endl;
    //print(wordorder[startkey]);

    //if (wordorder.count(startkey)==0)
    if (valsize == 0)
    {
      //lprint(startkey);
      cout << "\n\n\n";

      break;
    }
    string place = wordorder[startkey].at(rand()%(valsize));
    //string place = wordorder[startkey].front();
    startkey.pop_front();
    startkey.push_back(place);
    cout << place << " ";
     
  }
  cout << endl;
  return 0;
}

vector<string> read()
{
  ifstream file("Example.txt");
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

void print(list<string> & l)
{
  for (list<string>::iterator iit = l.begin(); iit != l.end(); ++iit)
  {
    cout << *iit << " ";
  }
  return;
}
