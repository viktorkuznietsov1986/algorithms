#pragma once
#include "vcruntime_exception.h"

#include <string>

class DenseGraphHasEdgeException :
	public std::exception
{
public:
	DenseGraphHasEdgeException(int from, int to);
	virtual ~DenseGraphHasEdgeException() throw();

	virtual const char* what() const;

private:
	std::string _msg;
};

