#include "memory_routines.h"

namespace structures {
	byte & MemoryRoutines::byteSet(byte & B)
	{
		return B = MAX_BYTE;
	}

	byte & MemoryRoutines::byteReset(byte & B)
	{
		return B = 0;
	}

	byte & MemoryRoutines::byteXOR(byte & B)
	{
		return B = ~B;
	}

	byte & MemoryRoutines::byteSHL(byte & B)
	{
		return B = B << 1;
	}

	byte & MemoryRoutines::byteSHR(byte & B)
	{
		return B = B >> 1;
	}

	bool MemoryRoutines::byteNthBitGet(byte & B, int n)
	{
		byte tHelp = B;
		tHelp = tHelp >> n;
		tHelp = tHelp & 0;
		if (tHelp == 1)
		{
			return true;
		}
		return false;
	}

	byte & MemoryRoutines::byteNthBitTo0(byte & B, int n)
	{
		byte tHelp = 1;
		tHelp = ~(tHelp << n);
		B = B & tHelp;
		return B;

	}

	byte & MemoryRoutines::byteNthBitTo1(byte & B, int n)
	{
		byte tHelp = 1;
		tHelp = tHelp << n;
		B = B | tHelp;
		return B;
	}

	byte & MemoryRoutines::byteNthBitToggle(byte & B, int n)
	{
		if (byteNthBitGet(B, n))
		{
			byteNthBitTo0(B, n);
		}
		else
		{
			byteNthBitTo1(B, n);
		}
		return B;

	}

	MemoryRoutines::MemoryRoutines()
	{
	}

}
