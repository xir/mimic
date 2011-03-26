#ifndef test_h
#define test_h
class testWord
{
  public:
    void set(string);
    void countOccurences(vector<string> &);
    void getVariance(vector<string> &);

    void printCount(){cout << count;}
    void printMean(){cout << mean;}
    void printVariance(){cout << variance;}

  private:
    string word;
    unsigned int count;
    double mean;
    double variance;
    double diffsum;

};
#endif
