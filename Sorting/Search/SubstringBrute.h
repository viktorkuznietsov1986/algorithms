#pragma once

#include <string>
#include <list>

class SubstringBrute
{
public:
	SubstringBrute(const std::string& pattern);
	~SubstringBrute();

	int search(const std::string& txt) const;
	std::list<int> searchAll(const std::string& txt) const;
	int count(const std::string& txt) const;

private:
	int search(const std::string& txt, int startPos) const;

private:
	std::string pat;
};

