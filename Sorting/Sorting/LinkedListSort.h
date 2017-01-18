#pragma once
#include <list>
#include <string>

typedef std::list<std::string>::iterator list_iterator;

class LinkedListSort
{
public:
	static void sort(std::list<std::string>& lst);

private:
	static void sort(std::list<std::string>& lst, list_iterator& start, list_iterator& end, int w);
	static int getChar(list_iterator& it, int w);
};

