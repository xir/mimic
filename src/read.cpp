/* reads the command line to set the number of words to look at when 
 * generating n-grams. Print usage otherwise
 */

#include<fstream>
#include<sstream>
#include<cstdlib>
#include<iostream>

#include "read.h"
using namespace std;
int readCommandLine(int argc, char* argv[], vector<string> & words,
    unsigned int & numwords)
{
  if (argc==2 || argc==3)
  {
    if (argc==3)
      words=read(argv[2]);
    else
      words = read();


    int wordssize=words.size();
    if (atoi(argv[1])==0)
      numwords=0;
    else if (atoi(argv[1])<1 || atoi(argv[1])>wordssize-1)
    {
      cout << "Number of words reverting to 1 - input out of range" << endl;
      numwords = 1;
    }
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
  cout << "usage: ./mimic n [filename]"<< endl;
  cout << "where:" <<endl;
  cout << "n determines what n gram to make: 0-gram, 1-gram, 2-gram"<< endl;
  cout << "defaults to 0 (for simplicity the original file) if out of "
    "bounds or misformed" << endl;
  cout << "filename is optional, default is 'Example.txt'" <<endl;
}

vector<string> read(string filename)
{
  ifstream file(filename.c_str());
  if (file.good())
  {
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
  else
    cout << "Error opening file" << endl;
    exit(2);
}
