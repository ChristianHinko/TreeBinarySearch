// Christian Hinkle


#include <iostream>
#include "CTHTreeBinarySearch.h"
#include "CTHTreeBinaryFunctionLibrary.h"
#include "CTHHeapMax.h"
#include "CTHMathFunctionLibrary.h"
#include <array>
#include "CTHStringFunctionLibrary.h"



void Problem1();
void Problem2();
void Problem3();


/**
 * Entry point of application
 */
int main()
{
	std::cout << "Problem1" << '\n';
	Problem1();
	std::cout << '\n';
	std::cout << "Problem2" << '\n';
	Problem2();
	std::cout << '\n';
	std::cout << "Problem3" << '\n';
	Problem3();

	return 0; // exit with success status
}


void Problem1()
{
	CTHTreeBinarySearch<int> BinaryTree;
	BinaryTree.Add(5);
	BinaryTree.Add(2);
	BinaryTree.Add(7);
	BinaryTree.Add(4);
	BinaryTree.Add(8);

	const int NumberOfNodes = CTHTreeBinaryFunctionLibrary::CountNumberOfNodesRecursive(BinaryTree);
	std::cout << "Number of nodes: " << NumberOfNodes << '\n';

	const int NumberOfLeaves = CTHTreeBinaryFunctionLibrary::CountNumberOfLeavesRecursive(BinaryTree);
	std::cout << "Number of leaves: " << NumberOfLeaves << '\n';

	const int Height = CTHTreeBinaryFunctionLibrary::GetHeightRecursive(BinaryTree);
	std::cout << "Height: " << Height << '\n';
}

void Problem2()
{
	std::array<long long, 20> RandomNumbers = CTHMathFunctionLibrary::RandomIntegersInRangeUnique<20>(1, 100);
	std::cout << "20 random numbers between 1 and 100 without duplications: ";
	CTHStringFunctionLibrary::PrintContainer(RandomNumbers.begin(), RandomNumbers.end(), std::cout);
	std::cout << '\n';

	std::cout << "Generating max heap tree." << '\n';
	CTHHeapMax<int> MaxHeap;
	for (const long long& RandomNumber : RandomNumbers)
	{
		MaxHeap.Add(RandomNumber);
	}

	std::cout << "Array elements of max heap: ";
	MaxHeap.PrintArray(std::cout);
	std::cout << '\n';
}

void Problem3()
{

}
