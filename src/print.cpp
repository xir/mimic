#include<iostream>
#include "print.h"
using namespace std;

void print(const vector<string> & v)
{
  for(unsigned int i=0;i<v.size() ;++i)
  {
    cout<<v.at(i);
    if(i!=v.size()-1)
      cout<<" ";
  }
  cout<<endl;
}

void print(list<string> & l)
{
  for (list<string>::iterator iit = l.begin(); iit != l.end(); ++iit)
    cout << *iit << " ";
}
