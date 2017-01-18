#pragma once
#include <string>
#include <vector>

const std::string BINARY = "01";
const std::string DECIMAL = "0123456789";
const std::string LOWERCASE = "abcdefghijklmnopqrstuvwxyz";
const std::string UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const std::string BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class Alphabet
{
public:
	Alphabet(const std::string& s);
	~Alphabet();

	char toChar(int index) const;
	int toIndex(char c) const;
	int R() const { return r; }
	int lgR() const { return lgr; }
	bool contains(char c) const { return toIndex(c) > -1; }
	std::vector<int> toIndices(const std::string& s) const;
	std::string toChars(const std::vector<int>& indices) const;

private:
	int r;
	int lgr;
	std::string index;
	std::vector<int> reverseIndex;
};

