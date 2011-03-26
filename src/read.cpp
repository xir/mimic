#include<fstream>
#include<cstdlib>
#include<iostream>

#include "read.h"
int readCommandLine(int argc, char* argv[], vector<string> & words,
    unsigned int & numwords)
{
  if (argc==3 || argc==4)
  {
    if (argc==4)
    {
      words=read(argv[3]);
    }
    else if (argc==3)
    {
      words = read("Example.txt");
    }

    int wordssize=words.size();
    if (atoi(argv[1])==0)
      numwords=0;
    else if (atoi(argv[1])<1 || atoi(argv[1])>wordssize-1)
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
  cout << "usage: ./mimic n word [filename]"<< endl;
  cout << "where:"<<endl;
  cout << "n determines what n-gram to make: 0-gram, 1-gram, 2-gram" <<endl;
  cout << "(Defaults to 1 if out of bounds)" << endl;
  cout << "word is the word to consider in the output" <<endl;
  cout << "filename is optional, default is Example.txt" <<endl;
}

vector<string> read(const char* filename)
{
  ifstream file(filename);
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
