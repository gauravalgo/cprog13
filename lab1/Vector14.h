#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <initializer_list>
#include "stdexcept"
//Vector.h
/*
move konstruktor
move operator
tester
*/

class Vector{


public:
	unsigned int *v;
	size_t size;

	Vector();
	explicit Vector(const size_t s);
	Vector(const Vector & ref);
	~Vector();
	Vector (Vector&& ref);
	size_t get_size() const;
	unsigned int get(int index) const;
	unsigned int & operator[] (int index);
	const unsigned int & operator[] (int index) const;
	
	Vector & operator=(const Vector & ref);
	Vector & operator=(Vector && ref);
	Vector & operator=(const std::initializer_list<int>& list);

};
#endif