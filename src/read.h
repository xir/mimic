#ifndef read_h
#define read_h
#include<vector>
#include<string>
using namespace std;

int readCommandLine(int argc, char* argv[], vector<string> & words,
    unsigned int & numwords);
void usage();
vector<string> read(const char* filename);

#endif
