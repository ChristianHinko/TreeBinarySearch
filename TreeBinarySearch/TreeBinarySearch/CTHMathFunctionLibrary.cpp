// Christian Hinkle


#include "CTHMathFunctionLibrary.h"

#include <cstdlib>
#include <vector>



unsigned int CTHMathFunctionLibrary::Power(const unsigned int InBase, const unsigned int InExponent)
{
	if (InExponent == 0)
	{
		return 1;
	}

	unsigned int Result = InBase;
	for (unsigned int CurrentExponent = 1; CurrentExponent < InExponent; ++CurrentExponent)
	{
		Result *= InBase;
	}

	return Result;
}

std::vector<long long> CTHMathFunctionLibrary::Fibonacci(const long long& InNumber)
{
	std::vector<long long> Sequence;

	// Iterative Fibonacci
	{
		int Sum = 0;
		int Previous = 1;
		int Current = 0;
		for (int i = 0; i < InNumber; ++i)
		{
			Sequence.push_back(Sum);
			Current = Sum + Previous;
			Sum = Previous;
			Previous = Current;
		}
	}

	return Sequence;
}
