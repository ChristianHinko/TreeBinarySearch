// Christian Hinkle

#pragma once

#include <ostream>
#include <memory>
#include "CTHNodeTreeBinary.h"



/**
 * Binary expression tree
 */
template <class T>
class CTHTreeBinaryExpression
{
	friend class CTHTreeBinaryFunctionLibrary; // weird

public:
	typedef CTHNodeTreeBinary<T> TNodeType;

protected:
	/** Root node of the tree */
	std::shared_ptr<TNodeType> Root;

public:
	CTHTreeBinaryExpression();
};


template <class T>
CTHTreeBinaryExpression<T>::CTHTreeBinaryExpression()
	: Root(nullptr)
{
}
