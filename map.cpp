#include<cstdlib>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
  map<int, vector<int> > lookup;
  vector<int> w;
  w.push_back(7);
  w.push_back(6);
  lookup[7]=w;
  cout << lookup[7].at(1);
}

