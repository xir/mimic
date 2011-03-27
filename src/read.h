#ifndef read_h
#define read_h
#include<vector>
#include<string>
//using namespace std;

int readCommandLine(int argc, char* argv[], std::vector<std::string> &words,
    unsigned int & numwords);
void usage();
std::vector<std::string> read(std::string filename = "Example.txt");
#endif
