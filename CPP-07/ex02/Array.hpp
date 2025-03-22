#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
private:
	T* _array;
	size_t _size;
public:
	Array() : _array(0), _size(0) {}

	Array(unsigned int n) : _array(new T[n]), _size(n) {};

	Array(const Array& other): _size(other._size) {
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	};

	~Array() {
		delete[] _array;
	};

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] _array;
			_size = other._size;
			_array = new T[_size];
			for (size_t i = 0; i < _size; i++) {
				_array[i] = other._array[i];
			}
		}
		return *this;
	};

	T& operator[](int n) {
		if (n < 0 || n >= (int)_size)
			throw WrongIdxExeption();
		else
			return _array[n];
	}

	T& operator[](int n) const {
		if (n < 0 || n >= (int)_size)
			throw WrongIdxExeption();
		else
			return _array[n];
	}

	size_t size() const {
		return _size;
	}

	class WrongIdxExeption : public std::exception {
		public:
				virtual const char *what()const throw() {
					return "Error out of range";
				};
	};
};