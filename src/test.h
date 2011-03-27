#ifndef test_h
#define test_h
class testWord
{
  public:
    void set(string);
    void getVariance(vector<string> &);
    void printCount(){cout << count;}
    void printMean(){cout << mean;}
    void printVariance(){cout << variance;}
    void outputVariance(vector<string> & sentence, string & word);

  private:
    string word;
    unsigned int count;
    double mean;
    double variance;
    double diffsum;
};
#endif
