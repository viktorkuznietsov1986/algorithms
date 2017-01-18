#pragma once
template <typename T>
class IPriorityQueue
{
public:
	virtual void insert(const T& item) = 0;
	virtual size_t size() const = 0;
	virtual bool isEmpty() const = 0;
};

