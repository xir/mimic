#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<time.h>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<list>

using namespace std;
// Maybe change to vector list<string>?
// probably have the memory, save time

vector<string> read(string& fname);//can't get name argument working
int search(vector<vector<int> > v, int i);
void print(const vector<string> & v);
void iprint(const vector<int> & v, vector<string> y);
void viprint(const vector<vector<int> > & v, vector<string> y);
int find_string_in_vector(vector<string> v, string str);
vector<string> uniq(vector<string> v);

int main( int argc, char* argv[])
{
  int random_number;
  srand (time(NULL));
  int pos, prev;

  //read from file Example.txt and store words as strings in vector
  string fname = "Example.txt";
  vector<string> words = read(fname);

  vector<string> unique_words;
  unique_words = uniq(words);

  typedef map <list<int>, vector<int> > vvm;
  vvm wordorder;
  vvm::const_iterator end = wordorder.end();
  int wordssize = words.size();
  list<int> key;
  int numwords = atoi(argv[1]);
  for (unsigned int j = 0;j<numwords;++j)
  {
    int partkey= find_string_in_vector(unique_words, words[j]);
    key.push_back(partkey);
  }
  for (unsigned int i = 0; i<wordssize-numwords;++i)
  {
    key.pop_front();
    key.push_back(find_string_in_vector(unique_words, words[i+numwords-1]));
    int value = find_string_in_vector(unique_words, words[i+numwords]);
    wordorder[key].push_back(value);
  }
  //for (vvm::const_iterator it = wordorder.begin(); it!= end; ++it)
  {
    //iprint((it->first), unique_words);
    //iprint((it->second), unique_words);
  }
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
//searches through first terms of v(v(i)) returns position it finds or -1 if it doesn't
int search(vector<vector<int> > v, int i)
{
  for (unsigned int j =0; j<v.size()-1; ++j)
  {
    if (v.at(j).front()==i)
    {
      return j;
    }
  }
  return -1;
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

// function to print words from a vector of ints (looking them up in unique_words)

void iprint(const vector<int> & v, vector<string> y) 
{
  cout<<"[";
  for(unsigned int i=0;i<v.size() ;++i)
    {
      cout<<y.at(v.at(i));
      if(i!=v.size()-1)
        cout<<" ";
      else
        cout<<"]";
    }
  cout<<endl;
  return;
}

//function to print the words for a vector of vector of ints

void viprint(const vector<vector<int> > & v, vector<string> y)
{
  cout << "{" << endl;
  for (unsigned int i=0; i<v.size(); ++i)
  {
    iprint(v.at(i), y);
  }
  cout << "}" << endl;
}

/*function to find a string in a vector of strings and return its place in the vector
 *returns -1 if string not found
 */

int find_string_in_vector(vector<string> v, string str)
{
  int j=-1;
  for (int i=0; i<v.size(); ++i)
  {
    if (str == v.at(i))
    {
      j=i;
      break;
    }
  }
  return j;
}

vector<string> uniq(vector<string> v)
{
  vector<string> unique_words;
  vector<string>::iterator it;
  for (unsigned int i=0;i<v.size();++i)
  {
    unique_words.push_back(v.at(i));
  }
  //sort entries
  sort (unique_words.begin(), unique_words.end());
  //remove duplicates
  it = unique(unique_words.begin(),unique_words.end());
  //resize
  unique_words.resize(it - unique_words.begin());
  return unique_words;
}
