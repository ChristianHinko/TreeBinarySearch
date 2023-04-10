// Christian Hinkle

#pragma once

#include <ostream>
#include <memory>
#include "CTHNodeTreeBinary.h"



/**
 * Binary search tree
 */
template <class T>
class CTHTreeBinarySearch
{
	friend class CTHTreeBinaryFunctionLibrary; // weird

public:
	typedef CTHNodeTreeBinary<T> TNodeType;

protected:
	/** Root node of the tree */
	std::shared_ptr<TNodeType> Root;

public:
	CTHTreeBinarySearch();

	/** Add node with a value to the tree. */
	void Add(const T& InValue);

	/** Remove node by value from the tree. */
	bool Remove(const T& InValue);

	/** Output the binary tree to a given stream. */
	void PrintTree(std::ostream& InOutOutputStream) const;

protected:
	/** Add node to the tree. */
	void Add(std::shared_ptr<TNodeType> InNode);

	/** Remove node from the tree. */
	bool Remove(std::shared_ptr<TNodeType> InNode);

	static std::shared_ptr<TNodeType> GetDeepestNode(std::shared_ptr<TNodeType> InBaseNode, const T& InValue);

	static std::shared_ptr<TNodeType>& GetAppropriateChildNodePointerRef(TNodeType* InParentNode, const T& InValue);

	/** Traverse the current node pointer down and return whether we advanced a level or not. */
	static bool TraverseDown(std::shared_ptr<TNodeType>& InOutNodeCurrent, const T& InValue);

	static std::shared_ptr<TNodeType> FindNode(std::shared_ptr<TNodeType> InBaseNode, const T& InValue);
};


template <class T>
CTHTreeBinarySearch<T>::CTHTreeBinarySearch()
	: Root(nullptr)
{
}


template <class T>
void CTHTreeBinarySearch<T>::Add(const T& InValue)
{
	Add(std::make_shared<TNodeType>(TNodeType(InValue)));
}
template <class T>
void CTHTreeBinarySearch<T>::Add(std::shared_ptr<TNodeType> InNode)
{
	if (Root == nullptr)
	{
		// Add the node to the empty tree
		Root = InNode;
		return;
	}

	InNode->Parent = GetDeepestNode(Root, InNode->Value);
	GetAppropriateChildNodePointerRef(InNode->Parent.lock().get(), InNode->Value) = InNode;
}

template <class T>
bool CTHTreeBinarySearch<T>::Remove(const T& InValue)
{
	return Remove(FindNode(Root, InValue));
}
template <class T>
bool CTHTreeBinarySearch<T>::Remove(std::shared_ptr<TNodeType> InNode)
{
	if (InNode == nullptr)
	{
		return false;
	}

	// Remove our children
	Remove(InNode->ChildLeft);
	Remove(InNode->ChildRight);

	// Have our parent stop referencing us
	if (std::shared_ptr<TNodeType> Parent = InNode->Parent.lock())
	{
		if (Parent->ChildLeft == InNode)
		{
			Parent->ChildLeft = nullptr;
		}
		if (Parent->ChildRight == InNode)
		{
			Parent->ChildRight = nullptr;
		}
	}

	return true;
}

template <class T>
void CTHTreeBinarySearch<T>::PrintTree(std::ostream& InOutOutputStream) const
{

}

template <class T>
std::shared_ptr<typename CTHTreeBinarySearch<T>::TNodeType> CTHTreeBinarySearch<T>::GetDeepestNode(std::shared_ptr<TNodeType> InBaseNode, const T& InValue)
{
	std::shared_ptr<TNodeType> Rover = InBaseNode;
	while (true)
	{
		std::shared_ptr<TNodeType> Next = Rover;
		if (TraverseDown(Next, InValue) == false)
		{
			// We are the deepest
			break;
		}
		if (Next == nullptr)
		{
			// We are the deepest
			break;
		}

		Rover = Next;

		if (Next->Value == InValue)
		{
			// We are the InValue
			break;
		}
	}

	return Rover;
}

template <class T>
std::shared_ptr<typename CTHTreeBinarySearch<T>::TNodeType>& CTHTreeBinarySearch<T>::GetAppropriateChildNodePointerRef(TNodeType* InParentNode, const T& InValue)
{
	if (InValue < InParentNode->Value)
	{
		return InParentNode->ChildLeft;
	}

	if (InValue > InParentNode->Value)
	{
		return InParentNode->ChildRight;
	}
}

template <class T>
bool CTHTreeBinarySearch<T>::TraverseDown(std::shared_ptr<TNodeType>& InOutNodeCurrent, const T& InValue)
{
	if (InValue < InOutNodeCurrent->Value)
	{
		InOutNodeCurrent = InOutNodeCurrent->ChildLeft;
		return true;
	}

	if (InValue > InOutNodeCurrent->Value)
	{
		InOutNodeCurrent = InOutNodeCurrent->ChildRight;
		return true;
	}

	return false;
}

template <class T>
std::shared_ptr<typename CTHTreeBinarySearch<T>::TNodeType> CTHTreeBinarySearch<T>::FindNode(std::shared_ptr<TNodeType> InBaseNode, const T& InValue)
{
	std::shared_ptr<TNodeType> Node = GetDeepestNode(InBaseNode, InValue);
	if (Node->Value == InValue)
	{
		return Node;
	}

	return nullptr;
}
