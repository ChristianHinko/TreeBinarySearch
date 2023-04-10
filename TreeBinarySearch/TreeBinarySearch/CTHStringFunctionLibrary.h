// Christian Hinkle

#pragma once

#include <iterator>
#include <string>
#include <sstream>
#include <ostream>



/**
 * A collection of helpful string-related functions
 */
class CTHStringFunctionLibrary
{
public:
	/**
	 * Build a string out of a container with elements separated by a delimiter
	 */
	template <typename T>
	static std::string ContainerToString(const T& InBeginIterator, const T& InEndIterator, const std::string& InOpeningDelimiter = std::string("{ "), const std::string& InClosingDelimiter = std::string(" }"), const std::string& InValueDelimiter = std::string(", "));
	template <typename T>
	static void PrintContainer(const T& InBeginIterator, const T& InEndIterator, std::ostream& InOutOutputStream, const std::string& InOpeningDelimiter = std::string("{ "), const std::string& InClosingDelimiter = std::string(" }"), const std::string& InValueDelimiter = std::string(", "));

	/**
	 * Attempt to convert an arbitrary type to a string
	 */
	template <typename T>
	static std::string ToString(const T& InValue);
};

template <typename T>
std::string CTHStringFunctionLibrary::ContainerToString(const T& InBeginIterator, const T& InEndIterator, const std::string& InOpeningDelimiter, const std::string& InClosingDelimiter, const std::string& InValueDelimiter)
{
	std::stringstream StringStream;
	PrintContainer(InBeginIterator, InEndIterator, StringStream, InOpeningDelimiter, InClosingDelimiter, InValueDelimiter);
	return StringStream.str();
}

template <typename T>
void CTHStringFunctionLibrary::PrintContainer(const T& InBeginIterator, const T& InEndIterator, std::ostream& InOutOutputStream, const std::string& InOpeningDelimiter, const std::string& InClosingDelimiter, const std::string& InValueDelimiter)
{
	InOutOutputStream << InOpeningDelimiter;

	// Output all values to the stream
	for (T iter = InBeginIterator; iter != InEndIterator; ++iter)
	{
		InOutOutputStream << *iter;

		// Add the delimiter if we are not the last value
		if (std::next(iter, 1) != InEndIterator)
		{
			InOutOutputStream << InValueDelimiter;
		}
	}

	InOutOutputStream << InClosingDelimiter;
}

template <typename T>
std::string CTHStringFunctionLibrary::ToString(const T& InValue)
{
	std::ostringstream stream;
	stream << InValue;
	return stream.str();
}
