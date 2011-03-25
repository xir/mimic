#include<fstream>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#ifndef read_h
#define read_h

int readCommandLine(int argc, char* argv[], vector<string> & words,
    unsigned int & numwords);
void usage();
vector<string> read(const char* filename);

#endif
