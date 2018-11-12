// WordCount.cpp
// Written by Richert Wang for CS 32, F18.

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount()
{
  
}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
  int count = 0;
  for (unsigned i =0;i< CAPACITY;i++)
    {
      for(unsigned j = 0; j< table[i].size();j++)
	{
	  count += static_cast<int>((table[i].at(j)).second);
	}
    }
  return count;
}

int WordCount::getNumUniqueWords() const {
  int count = 0;
  for(unsigned i=0;i<CAPACITY;i++)
    {
      for(unsigned j=0;j<table[i].size();j++)
	{
	  count++;
	}
    }
  return count;
}

int WordCount::getWordCount(std::string word) const {
  std::string search = stripWord(word);
  size_t index = hash(search);
  for(unsigned j=0;j<table[index].size();j++)
    {
      if(((table[index].at(j)).first).compare(search)==0)
	{
	  return static_cast<int>((table[index].at(j)).second);
	}
    }
  return 0;
}


int WordCount::incrWordCount(std::string word) {
  std::string search = stripWord(word);
  size_t index = hash(search);
  int nIndex = 0;
  if(search.compare("")!=0)
    {
      if(getWordCount(search) != 0)
	{
	  for(unsigned j=0;j<table[index].size();j++)
	    {
	      if(((table[index].at(j)).first).compare(search) == 0)
		{
		  nIndex = j;
		}
	    }
	  (table[index].at(nIndex)).second++;
	  return (table[index].at(nIndex)).second;
	}
      else
	{
	  std::pair<std::string,size_t> ins;
	  ins.first = search;
	  ins.second = 1;
	  table[index].push_back(ins);
	  return 1;
	}
    }
  return 0;
}
      


bool WordCount::isWordChar(char c) {
  return isalpha(c);
}


std::string WordCount::stripWord(std::string word) {
  std::string res = "";
  for(unsigned i=0;i<word.length();i++)
    {
      if(isalpha(word[i]))
	{
	  res+=word[i];
	}
      else if(word[i] == '/' || word[i] == '-')
	{
	  if(i>=1 && i<word.length()-1)
	    {
	      res+=word[i];
	    }
	  else
	    {
	      return "";
	    }
	}
      else
	{
	  return "";
	}
      
    }
  return res;
}
