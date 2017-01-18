#pragma once
#include <vector>

class BitVector
{
public:
	BitVector(int N);
	~BitVector();

	void add(int x);
	void remove(int x);
	bool contains(int x) const;
	std::vector<int> getSortedIntArray() const;
	
	int size() const { return _size; }

private:
	int getMajorPos(int x) const { return x / sizeof(int); }
	int getMinorPos(int x) const { return x % sizeof(int); }

	bool isSet(int majorPos, int minorPos) const;
	void setBit(int majorPos, int minorPos);
	void clearBit(int majorPos, int minorPos);

	int createMask(int pos)	const { return 1 << pos; }


private:
	std::vector<int> _data;
	int _size;
};

