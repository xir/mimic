#include<string>
#include<vector>
#include<iostream>
#include<cstdlib>
using namespace std;

#include "test.h"

void testWord::set(string word)
{
  this->word=word;
  count=0;
  diffsum=0;
  mean=0;
  variance=0;
}

void testWord::getVariance(vector<string> & sentence)
{
  unsigned int interval=1;
  for(unsigned int i=0;i<sentence.size();++i)
  {
    if(sentence.at(i)==word)
    {
      ++count;
      interval=1;
    }
    else
      ++interval;
  }
  if (count != 0)
  {
    mean = (double)sentence.size()/count;

    double diff=1;
    for(unsigned int i=0;i<sentence.size();++i)
    {
      if(sentence.at(i)==word)
      {
        diffsum+=((diff-mean)*(diff-mean));
        diff=1;
      }
      else
        ++diff;
    }
    if (count != 0)
      variance = diffsum/count;
  }
}

void testWord::outputVariance(vector<string> & sentence, string & word)
{
  set(word);
  getVariance(sentence);
  if (count == 0)
  {
    cout << "Word is not in the sentence." << endl;
  }
  else
  {
    cout << "The mean interval is: ";
    printMean();
    cout << endl;
    cout << "The variance is: ";
    printVariance();
    cout << endl;
  }
}
