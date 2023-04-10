// Christian Hinkle

#pragma once

#include <memory>


template <class T>
class CTHTreeBinarySearch;
class CTHTreeBinaryFunctionLibrary;



/**
 * Node of a binary tree
 */
template <class T>
struct CTHNodeTreeBinary
{
	friend class CTHTreeBinarySearch<T>;
	friend class CTHTreeBinaryFunctionLibrary; // weird

public:
	CTHNodeTreeBinary(const T& InValue);
	CTHNodeTreeBinary();

protected:
	T Value;

	std::shared_ptr<CTHNodeTreeBinary<T>> ChildLeft;
	std::shared_ptr<CTHNodeTreeBinary<T>> ChildRight;

	std::weak_ptr<CTHNodeTreeBinary<T>> Parent;
};


template <class T>
CTHNodeTreeBinary<T>::CTHNodeTreeBinary(const T& InValue)
	: Value(InValue)
	, ChildLeft(nullptr)
	, ChildRight(nullptr)
	, Parent(std::weak_ptr<CTHNodeTreeBinary<T>>())
{
}
template <class T>
CTHNodeTreeBinary<T>::CTHNodeTreeBinary()
	: CTHNodeTreeBinary(T())
{
}
