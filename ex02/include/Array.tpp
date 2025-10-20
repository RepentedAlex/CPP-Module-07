#include "Array.hpp"

#include <exception>

template <typename T>
Array<T>::Array() : array_(NULL), size_(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]), size_(n) {
}

template <typename T>
Array<T>::Array(const Array<T>& original) : array_(NULL), size_(0) {
	*this = original;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& original) {
	if (this != &original) {
		if (this->array) {
			delete[] this->array_;
		}
		this->size_ = original.size_;
		this->array_ = new T[this->size_];
		for (size_t i = 0 ; i < this->size_ ; i++) {
			this->array_[i] = original.array_[i];
		}
	}
	return (*this);
}

template <typename T>
const T&	Array<T>::operator[](size_t index) const {
	if (index >= this->size_) {
		throw std::exception();
	}
	return (this->array_[index]);
}

template <typename T>
T&	Array<T>::operator[](size_t index) {
	if (index >= this->size_) {
		throw std::exception();
	}
	return (this->array_[index]);
}

template <typename T>
size_t	Array<T>::size() const {
	return (this->size_);
}

template <typename T>
Array<T>::~Array() {
	if (this->array_ != NULL) {
		delete[] this->array_;
	}
}
