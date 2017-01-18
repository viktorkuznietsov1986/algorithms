#pragma once

#include <memory>
#include "IPriorityQueue.h"
#include "IBasicOperations.h"

template <typename T>
class IMaxPQ : public IPriorityQueue<T>
{
public:
	virtual std::shared_ptr<T> max() const = 0;
	virtual std::shared_ptr<T> delMax() = 0;
};

