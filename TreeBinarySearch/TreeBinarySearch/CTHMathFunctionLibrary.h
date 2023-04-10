// Christian Hinkle

#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include <array>
#include <vector>



/**
 * A collection of helpful math-related functions
 */
class CTHMathFunctionLibrary
{
public:
	template <class T>
	static T RandomIntegerInRange(const T& InA, const T& InB);

	template <std::size_t Count>
	static std::array<long long, Count> RandomIntegersInRangeUnique(const long long& InA, const long long& InB);

	/**  */
	template <class T>
	static T Clamp(const T& InValue, const T& InMin, const T& InMax);

	static unsigned int Power(const unsigned int InBase, const unsigned int InExponent);

	static std::vector<long long> Fibonacci(const long long& InNumber);
};

template <class T>
T CTHMathFunctionLibrary::RandomIntegerInRange(const T& InA, const T& InB)
{
	static std::random_device RandomDevice;
	static std::default_random_engine RandomEngine = std::default_random_engine(RandomDevice());
	static std::uniform_int_distribution<T> UniformDistribution = std::uniform_int_distribution<T>(InA, InB);

	const T Random = UniformDistribution(RandomEngine);
	const T Range = (InB - InA);

	return InA + (Random % Range);
}

template <std::size_t Count>
std::array<long long, Count> CTHMathFunctionLibrary::RandomIntegersInRangeUnique(const long long& InA, const long long& InB)
{
	const std::size_t RangeSize = std::abs((InB - InA) + 1);
	std::vector<long long> IntegersInRange;
	// Fill up the integers in the range
	{
		IntegersInRange.reserve(RangeSize);
		long long Number = InA;
		for (std::size_t i = 0; i < RangeSize; ++i, ++Number)
		{
			IntegersInRange.push_back(Number);
		}
	}

	// Shuffle the integers
	std::random_shuffle(IntegersInRange.begin(), IntegersInRange.end());

	// Take a subset of the integers in the range
	std::array<long long, Count> RandomIntegersInRange;
	std::copy(IntegersInRange.begin(), IntegersInRange.begin() + Count, RandomIntegersInRange.begin());
	return RandomIntegersInRange;
}

template <class T>
T CTHMathFunctionLibrary::Clamp(const T& InValue, const T& InMin, const T& InMax)
{
	return std::max(std::min(InValue, InMax), InMin);
}
