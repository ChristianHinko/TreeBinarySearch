// Christian Hinkle

#pragma once

#include <queue>
#include <vector>



/**
 * A collection of helpful priority_queue-related functions
 */
class CTHPriorityQueueFunctionLibrary
{
public:
	/** Get reference to the internal container of a given priority queue */
	template <class _Ty, class _Container = std::vector<_Ty>, class _Pr = std::less<typename _Container::value_type>>
	static _Container& GetInternalContainer(std::priority_queue<_Ty, _Container, _Pr>& InPriorityQueue);

	/** Const version of GetInternalContainer() */
	template <class _Ty, class _Container = std::vector<_Ty>, class _Pr = std::less<typename _Container::value_type>>
	static const _Container& GetInternalContainer(const std::priority_queue<_Ty, _Container, _Pr>& InPriorityQueue);
};


template <class _Ty, class _Container, class _Pr>
_Container& CTHPriorityQueueFunctionLibrary::GetInternalContainer(std::priority_queue<_Ty, _Container, _Pr>& InPriorityQueue)
{
	class GICpriority_queue : public std::priority_queue<_Ty, _Container, _Pr>
	{
	public:
		static _Container& GetInternalContainer(std::priority_queue<_Ty, _Container, _Pr>& InPriorityQueue)
		{
			_Container std::priority_queue<_Ty, _Container, _Pr>::* ContainerMember = &GICpriority_queue::c;
			_Container& Container = InPriorityQueue.*ContainerMember;
			return Container;
		}
	};

	return GICpriority_queue::GetInternalContainer(InPriorityQueue);
}
template <class _Ty, class _Container, class _Pr>
const _Container& CTHPriorityQueueFunctionLibrary::GetInternalContainer(const std::priority_queue<_Ty, _Container, _Pr>& InPriorityQueue)
{
	class GICpriority_queue : public std::priority_queue<_Ty, _Container, _Pr>
	{
	public:
		static const _Container& GetInternalContainer(const std::priority_queue<_Ty, _Container, _Pr>& InPriorityQueue)
		{
			const _Container std::priority_queue<_Ty, _Container, _Pr>::* ContainerMember = &GICpriority_queue::c;
			const _Container& Container = InPriorityQueue.*ContainerMember;
			return Container;
		}
	};

	return GICpriority_queue::GetInternalContainer(InPriorityQueue);
}
