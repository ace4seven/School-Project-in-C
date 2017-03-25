#include "vector.h"
#include "../ds_routines.h"
#include <cstdlib>
#include <cstring>

namespace structures {

	Vector::Vector(size_t size) :
		memory_(calloc(size, 1)),
		size_(size)
	{
	}

	Vector::Vector(const Vector& other) :
		Vector(other.size_)
	{
		memcpy(memory_, other.memory_, other.size_);
	}

	Vector::~Vector()
	{
		free(memory_);
		memory_ = NULL;
		size_ = 0;
	}

	Structure* Vector::clone() const
	{
		return new Vector(*this);
	}

	size_t Vector::size() const
	{
		return size_;
	}

	Structure & Vector::operator=(const Structure & other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Vector&>(other);
		}
		return *this;
	}

	Vector& Vector::operator=(const Vector& other)
	{
		if (this != &other)
		{
			this->size_ = other.size_;
			this->memory_ = realloc(this->memory_, this->size_);
			memcpy(memory_, other.memory_, other.size_);
		}
		return *this;
	}

	bool Vector::operator==(const Vector& other) const
	{
		return this->size_ == other.size_ && memcmp(this->memory_, other.memory_, this->size_) == 0;
	}

	byte& Vector::operator[](const int index)
	{
		DSRoutines::rangeCheckExcept(index, this->size_, "Index out of range");
		return *((reinterpret_cast<byte *>(memory_)) + index);
	}

	byte Vector::operator[](const int index) const
	{
		DSRoutines::rangeCheckExcept(index, this->size_, "Index out of range");
		return *((reinterpret_cast<byte *>(memory_)) + index);
	}

	byte& Vector::readBytes(const int index, const int count, byte& dest)
	{
		DSRoutines::rangeCheckExcept(index, size_, "Index out of range READBYTES");
		DSRoutines::rangeCheckExcept(index + count, size_ + 1, "Index out of range READBYTES");
		if (&dest >= getBytePointer(index) && &dest < getBytePointer(index + count))
		{
			memmove(&dest, getBytePointer(index), count);
		}
		else
		{
			memcpy(&dest, getBytePointer(index), count);
		}
		return dest;
	}

	void Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
	{
		if (length > 0)
		{
			DSRoutines::rangeCheckExcept(srcStartIndex, src.size_, "Index out of range COPY 1");
			DSRoutines::rangeCheckExcept(destStartIndex, dest.size_, "Index out of range COPY 3");

			if (src.memory_ != dest.memory_)
				memcpy(reinterpret_cast<byte*>(dest.memory_) + destStartIndex, reinterpret_cast<byte*>(src.memory_) + srcStartIndex, length);
			else
				memmove(reinterpret_cast<byte*>(dest.memory_) + destStartIndex, reinterpret_cast<byte*>(src.memory_) + srcStartIndex, length);
		}
	}

	byte* Vector::getBytePointer(const int index) const
	{
		DSRoutines::rangeCheckExcept(index, this->size_, "Index out of range");
		return ((reinterpret_cast<byte *>(memory_)) + index);
	}

}