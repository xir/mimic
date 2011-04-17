#ifndef gen_h
#define gen_h

#include<list>
#include<string>
#include<vector>
#include<map>

void genKey(std::list<std::string> & key, std::list<std::string> & startkey,
    std::vector<std::string> & words, const unsigned int numwords);
void genWordOrder(std::map <std::list<std::string>,
    std::vector<std::string> > & wordorder,
    const std::vector<std::string> & words, std::list<std::string> & key,
    const unsigned int numwords);
void genOutput(std::list<std::string> & startkey,
    std::map <std::list<std::string>,
    std::vector<std::string> > & wordorder,
    std::vector<std::string> & sentence);

#endif
