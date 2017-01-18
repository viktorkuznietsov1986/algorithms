#pragma once
class IBasicOperations
{
protected:
	virtual bool less(int i, int j) const = 0;
	virtual void exch(int i, int j) = 0;
};

