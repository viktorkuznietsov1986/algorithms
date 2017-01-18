#pragma once
#include <memory>

template <typename Key, typename Value>
class ISymbolTable
{
public:
	virtual void put(Key key, Value val) = 0;
	virtual std::shared_ptr<Value> get(Key key) = 0;
	virtual void Delete(Key key) = 0;
	virtual bool contains(Key key) const = 0;
	virtual bool isEmpty() const = 0;
	virtual size_t size() const = 0;
};

