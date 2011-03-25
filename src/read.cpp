#include "read.h"
int readCommandLine(int argc, char* argv[], vector<string> & words, unsigned int & numwords)
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
    cout << "usage: ./mimic [integer n>0:default=1] \
      [filename:default=Example.txt]"<< endl;
    cout << "for n =:";
    cout << "0 - output words based on their frequency"<< endl;
    cout << "1 - output words based on their frequency of occuring after 1\
      previous word" << endl;
    cout << "2 - output words based on their frequency of occuring after 2\
      previous words" << endl;
    cout << "n - output words based on their frequency of occuring after n\
      previous words" << endl;
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
    //cout << "Omit the second argument to use the default file" << endl;
    exit(2);
}
