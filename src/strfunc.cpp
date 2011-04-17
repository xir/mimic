/* Converts a string to lowercase */

#include<string>
#include "strfunc.h"

void strLower(std::string & str)
{
  for(unsigned int i=0;i<str.length();++i)
    str.at(i) = tolower(str.at(i));
}
