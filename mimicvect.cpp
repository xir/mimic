#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<time.h>
#include<cstdlib>
#include<algorithm>

using namespace std;

int search(vector<vector<int> > v, int i);
void print(const vector<string> & v);
void iprint(const vector<int> & v, vector<string> y);
void viprint(const vector<vector<int> > & v, vector<string> y);
int find_string_in_vector(vector<string> v, string str);
vector<string> uniq(vector<string> v);

int main()
{
  int random_number;
  srand (time(NULL));
  int pos, prev;

  //read from file Example.txt and store words as strings in vector
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

  vector<string> unique_words;
  unique_words = uniq(words);
  //initialise vector of ... of integers, to call from words
  vector<vector<int> > vect;

  vect.push_back(vector<int>());
  //set first word
  pos=find_string_in_vector(unique_words, "for");
  vect.back().push_back(pos);
  //cout << unique_words[6575];
  int wordssize = words.size();
  //viprint(vect, unique_words);
  for (unsigned int i=1; i<wordssize; ++i)
  {
    prev=pos;
    pos = find_string_in_vector(unique_words, words[i]);
    //cout << unique_words.at(prev) << " " << unique_words.at(pos) << endl;
    for (unsigned int j=0; j<vect.size();++j)
    {
      if (prev==vect.at(j).front())
      {
        vect.at(j).push_back(pos);
        break;
      }
    }
    for (unsigned int k=0; k<vect.size();++k)
    {
      if (pos == vect.at(k).front())
      {
        break;
      }
      else if (k == vect.size()-1)
      {
        vect.push_back(vector<int>());
        vect.back().push_back(pos);
        break;
      }
    }
  }

  int term;
  int num;
  term = vect.front().front();
  for (unsigned int i=0; i<1000; ++i)
  {
    if (i==0)
      cout << unique_words.at(term);
    else
      cout << " " << unique_words.at(term);
    for (unsigned int j=0;j<vect.size(); ++j)
    {
      if (term==vect.at(j).front())
      {
        num = j;
        break;
      }
    }
  if (vect.at(num).size() == 2)
    term = vect.at(num).back();
  else
    term = vect.at(num).at(rand()%(vect.at(num).size()-2)+1);
  }
  cout << endl;

  //viprint(vect, unique_words);
  return 0;
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
