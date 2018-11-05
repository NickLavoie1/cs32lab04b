#include <iostream>
#include <vector>
#include "WordCount.h"
#include "tddFuncs.h"

using namespace std;

int main()
{
  vector<string> vec;
  string one = "hi";
  string two = "gREetings";
  string six = "x-d";
  string three = "-x";
  string four = "as14s";
  string five = "Hi";
  vec.push_back(one);
  vec.push_back(two);
  vec.push_back(three);
  vec.push_back(four);
  vec.push_back(five);
  vec.push_back(five);
  vec.push_back(six);

  WordCount test;
  for(int i=0;i<vec.size();i++)
    {
      test.incrWordCount(vec[i]);
    }
  cout << "Word count = " << test.getTotalWords() << endl;
  cout << "Unique word count = " << test.getNumUniqueWords() << endl;
  return 0;
}
