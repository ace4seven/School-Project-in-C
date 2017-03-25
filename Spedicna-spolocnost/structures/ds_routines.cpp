#include <stdexcept>

#include "ds_routines.h"

namespace structures {
	DSRoutines::DSRoutines()
	{
	}


	bool DSRoutines::rangeCheck(const int index, const size_t size)
	{
		return DSRoutines::rangeCheck(index, 0, size);
	}

	bool DSRoutines::rangeCheck(const int index, const int baseIndex, const size_t size)
	{
		return index >= baseIndex && index < baseIndex + static_cast<int>(size);
	}

	void DSRoutines::rangeCheckExcept(const int index, const size_t size, const std::string exceptionMessage)
	{
		DSRoutines::rangeCheckExcept(index, 0, size, exceptionMessage);
	}

	void DSRoutines::rangeCheckExcept(const int index, const int baseIndex, const size_t size, const std::string exceptionMessage)
	{
		if (!DSRoutines::rangeCheck(index, baseIndex, size))
		{
			throw std::out_of_range(exceptionMessage);
		}
	}

	double DSRoutines::getInfinity()
	{
		return std::numeric_limits<double>::infinity();
	}
}