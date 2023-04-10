// Christian Hinkle

#pragma once

#include <queue>
#include <ostream>
#include "CTHStringFunctionLibrary.h"
#include "CTHPriorityQueueFunctionLibrary.h"



/**
 * Max heap tree
 */
template <class T>
class CTHHeapMax
{
protected:
	/** Tree in the form of an array. */
	std::priority_queue<T, std::vector<T>, std::less<T>> Array;

public:
	CTHHeapMax();

	/** Add a value to the tree. */
	void Add(const T& InValue);

	/** Pop the max value from the tree. */
	T Pop();

	/** Output the max heap tree to a given stream. */
	void PrintArray(std::ostream& InOutOutputStream) const;
};


template <class T>
CTHHeapMax<T>::CTHHeapMax()
	: Array()
{
}


template <class T>
void CTHHeapMax<T>::Add(const T& InValue)
{
	Array.push(InValue);
}

template <class T>
T CTHHeapMax<T>::Pop()
{
	T Top = Array.top();
	Array.pop();
	return Top;
}

template <class T>
void CTHHeapMax<T>::PrintArray(std::ostream& InOutOutputStream) const
{
	const std::vector<T>& InternalArray = CTHPriorityQueueFunctionLibrary::GetInternalContainer<T, std::vector<T>, std::less<T>>(Array);
	CTHStringFunctionLibrary::PrintContainer(InternalArray.begin(), InternalArray.end(), InOutOutputStream);
}
