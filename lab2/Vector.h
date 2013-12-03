#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <initializer_list>
#include "stdexcept"
#include <algorithm>
//Vector.h

template <class T>
class Vector{
public:
	T *v;
	size_t curSize;
	size_t bufSize;

	Vector();
	explicit Vector(const size_t s);
	Vector(const Vector & ref);
	~Vector();
	Vector (Vector && ref);
	Vector (const std::initializer_list<T> list);
	Vector (size_t s, T def);
	static bool comp (const T & a, const T & b);
	void alloc_more();
	void push_back(T);
	void insert(size_t index, T);
	void erase(size_t index);
	void clear();
	void sort(bool order);
	void unique_sort(bool order);
	bool exists(const T &)const;
	size_t size() const;
	T get(int index) const;
	T & operator[] (int index);
	const T & operator[] (int index) const;
	Vector & operator=(const Vector & ref);
	Vector & operator=(Vector && ref);
	Vector & operator=(const std::initializer_list<T>& list);
	void print();
};
#endif