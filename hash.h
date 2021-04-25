#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
struct Hash
{
  Hash() : hashVec(100,std::make_pair("0",nullptr)){}

  void insert(const std::string& str)
  {
	int pos = HashFunc(str);
	if(hashVec[pos].first == "0")
	{
	  hashVec[pos].first = str;
	}
	else
	{
	  if(hashVec[pos].second == nullptr)
	  {
		hashVec[pos].second = new OrderedList;
	  }
	  hashVec[pos].second->insert(str);
	}
  }
  void print()
  {
	for(int i =0;i<hashVec.size();i++)
	{
	  if(hashVec[i].first != "0")
	  {
		std::cout<<hashVec[i].first;
		if(hashVec[i].second != nullptr)
		{
		  hashVec[i].second->print();
		}
		std::cout<<std::endl;
	  }
	}
  }

  void find(const std::string& str)
  {
	int i = HashFunc(str);
	if(hashVec[i].first != "0")
	{
	  if(hashVec[i].first == str)
	  {
		std::cout<<"Found, 0 collisions"<<std::endl;
	  }
	  else
	  {
		int counter = hashVec[i].second->find(str);
		if(counter == 0)
		{
		  std::cout<<"Not found"<<std::endl;
		}
		else
		{
		  std::cout<<"Found, "<<counter<<" collisions"<<std::endl;
		}
	  }
	}
	else
	{
	  std::cout<< "Not found"<<std::endl;
	}
  }
  ~Hash()
  {
	for(int i =0;i<100;i++)
	{
	  if(hashVec[i].second !=nullptr)
	  {
		delete hashVec[i].second;
	  }
	}
  }

private:
  int HashFunc(const std::string& str)
  {
	int sumOfCodes = 0;
	if(str.size() != 0)
	{
	  if(str.size()>2)
	  {
		sumOfCodes += str[0] + str[1];
	  }
	}
	return sumOfCodes % 97;
  }
  struct OrderedList
  {

	std::list<std::string> list;
	void insert(const std::string& str)
	{
	  list.push_back(str);
	  list.sort();
	}

	void print()
	{
	  for(auto i : list)
	  {
		std::cout<<i<<",";
	  }
	}
	bool find(const std::string& str)
	{
	  int left = 1;
	  int right = list.size();
	  int mid = 0;
	  int counter = 0;
	  while(!(left>=right))
	  {
		mid = left + (right-left)/2;
		counter++;
		if(this->at(mid) == str)
		{
		  std::cout<<"found "<<counter<<std::endl;
		  return true;
		}
		if(this->at(mid)>str)
		{
		  right = mid;
		}
		else
		{
		  left = mid+1;
		}
	  }

	  std::cout<<"not found "<<counter<<std::endl;
	  return false;

	}
	std::string at(int it)
	{
	  auto value = list.begin();
	  for(int i=0;i<it;i++)
	  {
		value++;
	  }
	  return *value;
	}
  };
  std::vector<std::pair<std::string,OrderedList*>> hashVec;
};
#endif // HASH_H
