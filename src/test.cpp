#include<string>
#include<vector>
#include<iostream>
using namespace std;

#include "test.h"

void testWord::set(string word)
{
  this->word=word;
  count=0;
  diffsum=0;
  variance=0;
}

void testWord::countOccurences(vector<string> & sentence)
{
  unsigned int diff=1;
  for(unsigned int i=0;i<sentence.size();++i)
  {
    if(sentence.at(i)==word)
    {
      ++count;
      diff=1;
    }
    else
    {
      ++diff;
    }
  }
  mean = (double)sentence.size()/count;
}

void testWord::getVariance(vector<string> & sentence)
{
  double diff=1;
  for(unsigned int i=0;i<sentence.size();++i)
  {
    if(sentence.at(i)==word)
    {
      diffsum+=((diff-mean)*(diff-mean));
      diff=1;
    }
    else
    {
      ++diff;
    }
  }
  variance = diffsum/count;
}
