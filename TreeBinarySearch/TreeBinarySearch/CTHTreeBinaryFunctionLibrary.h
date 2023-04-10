// Christian Hinkle

#pragma once

#include "algorithm"
#include "CTHNodeTreeBinary.h"



/**
 * A collection of helpful binarytree-related functions
 */
class CTHTreeBinaryFunctionLibrary
{
public:
	template <class T>
	using TTreeType = CTHTreeBinarySearch<T>;
	template <class T>
	using TNodeType = typename TTreeType<T>::TNodeType;


	/** Count the number of nodes in a given binary tree */
	template <class T>
	static int CountNumberOfNodesRecursive(const TTreeType<T>& InBinaryTree);
	/** Count the number of nodes under the given node */
	template <class T>
	static int CountNumberOfNodesRecursive(const TNodeType<T>* InBaseNode);

	/** Count the number of leaves in a given binary tree */
	template <class T>
	static int CountNumberOfLeavesRecursive(const TTreeType<T>& InBinaryTree);
	/** Count the number of leaves under the given node */
	template <class T>
	static int CountNumberOfLeavesRecursive(const TNodeType<T>* InBaseNode);

	/** Get the depth of the given binary tree */
	template <class T>
	static int GetHeightRecursive(const TTreeType<T>& InBinaryTree);
	/** Get the depth of the subtree under the given node */
	template <class T>
	static int GetHeightRecursive(const TNodeType<T>* InBaseNode, const int InLevel = 0);
};

template <class T>
int CTHTreeBinaryFunctionLibrary::CountNumberOfNodesRecursive(const TTreeType<T>& InBinaryTree)
{
	return CountNumberOfNodesRecursive<T>(InBinaryTree.Root.get());
}
template <class T>
int CTHTreeBinaryFunctionLibrary::CountNumberOfNodesRecursive(const TNodeType<T>* InBaseNode)
{
	if (InBaseNode == nullptr)
	{
		return 0;
	}

	// Count ourselves
	int Count = 1;

	// Count our children
	Count += CountNumberOfNodesRecursive<T>(InBaseNode->ChildLeft.get());
	Count += CountNumberOfNodesRecursive<T>(InBaseNode->ChildRight.get());

	// Return the count
	return Count;
}

template <class T>
int CTHTreeBinaryFunctionLibrary::CountNumberOfLeavesRecursive(const TTreeType<T>& InBinaryTree)
{
	return CountNumberOfLeavesRecursive<T>(InBinaryTree.Root.get());
}
template <class T>
int CTHTreeBinaryFunctionLibrary::CountNumberOfLeavesRecursive(const TNodeType<T>* InBaseNode)
{
	if (InBaseNode == nullptr)
	{
		return 0;
	}

	if (InBaseNode->ChildLeft == nullptr && InBaseNode->ChildRight == nullptr)
	{
		// We are a leaf (base case)
		return 1;
	}

	// Count our children's leaves
	int Count = 0;
	Count += CountNumberOfLeavesRecursive<T>(InBaseNode->ChildLeft.get());
	Count += CountNumberOfLeavesRecursive<T>(InBaseNode->ChildRight.get());

	// Return the count
	return Count;
}

template <class T>
int CTHTreeBinaryFunctionLibrary::GetHeightRecursive(const TTreeType<T>& InBinaryTree)
{
	return GetHeightRecursive<T>(InBinaryTree.Root.get());
}
template <class T>
int CTHTreeBinaryFunctionLibrary::GetHeightRecursive(const TNodeType<T>* InBaseNode, const int InLevel)
{
	if (InBaseNode == nullptr)
	{
		return InLevel;
	}

	const int HeightChildLeft = GetHeightRecursive<T>(InBaseNode->ChildLeft.get(), InLevel + 1);
	const int HeightChildRight = GetHeightRecursive<T>(InBaseNode->ChildRight.get(), InLevel + 1);

	// Return the deepest height of our children
	return std::max(HeightChildLeft, HeightChildRight);
}
