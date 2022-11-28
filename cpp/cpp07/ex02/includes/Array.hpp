#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T	*_array;
		unsigned int	_size;
	public:

	Array<T>() : _array(NULL), _size(0) {}
	Array<T>(unsigned int n) : _array(new T[n]), _size(n) {}
	Array<T>(Array const &src) : _array(new T[src._size]), _size(src._size)
	{
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = src._array[i];
	}
	Array &operator=(Array const &src)
	{
		if (this != &src)
		{
			delete [] _array;
			_array = new T[src._size];
			_size = src._size;
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		return (*this);
	}
	T &operator[](unsigned int i) const
	{
		if (i >= _size)
			throw std::exception();
		return _array[i];
	}
	unsigned int size() const
	{
		return (_size);
	}
	~Array() { delete [] _array; }
};

#endif
