/// @file Array.hpp
/// @brief

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template <typename T>
class	Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array& original);
	Array&	operator=(const Array& original);
	~Array();

	const T&		operator[](size_t index) const;
	T&				operator[](size_t index);
	size_t			size() const;

private:
	T*				array_;
	unsigned int	size_;
};

#include "Array.tpp"

#endif // !ARRAY_HPP
