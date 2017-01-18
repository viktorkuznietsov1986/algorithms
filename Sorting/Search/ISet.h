#pragma once
template <typename Key>
class ISet
{
public:
	virtual void add(Key key) = 0;
	virtual void Delete(Key key) = 0;
	virtual bool contains(Key key) const = 0;
	virtual size_t size() const = 0;
	inline bool isEmpty() const { return size() == 0; }
};

