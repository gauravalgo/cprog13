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

};
#endif
//initializer without argument
template <class T>
Vector<T>::Vector(){

	curSize = (size_t) 0;
	bufSize = (size_t) 10;
	v = new T[bufSize];
}
//init with size
template <class T>
Vector<T>::Vector(const size_t s){
	if(s < 0){
		throw std::out_of_range ("index out of range!");
	}
	curSize = s;
	if (curSize < 2){
		bufSize = 5;
	}
	else{
		bufSize = curSize*4;
	}
	v = new T[bufSize];
	for (int i = 0; i < (int) curSize; ++i)
	{
		v[i] = T();
	}
}
//destructor
template <class T>
Vector<T>::~Vector(){
	delete[] v;
}
template <class T>
bool Vector<T>::comp(const T & a, const T & b) {
	return b < a;
}
//copy constructor
template <class T>
Vector<T>::Vector(const Vector & ref){
	curSize = ref.size();
	bufSize = ref.bufSize;
	v = new T[bufSize];
	for (int i = 0; i < (int) curSize; ++i)
	{
		v[i] = ref[i];
	}
}
//used for init with def value
template <class T>
Vector<T>::Vector(size_t s, T def){
	curSize = s;
	bufSize = s*4;
	v = new T[bufSize];
	for (int i = 0; i < (int) curSize; ++i)
	{
		v[i] = def;
	}
}
//used if we need to increase the needed space
template <class T>
void Vector<T>::alloc_more(){
	if(curSize == 0){
		curSize = 1;
	}
	size_t tmpBuf = curSize*2;
	T* tmp = new T[tmpBuf];
	for (int i = 0; i < (int) curSize; i++)
	{
		tmp[i] = v[i];
	}
	delete[] v;
	v = tmp;
	bufSize = tmpBuf;
}
//push_back, insert element at end 
template <class T>
void Vector<T>::push_back(T elem){
	if((int)(bufSize -curSize) ==  0 ){
		alloc_more();
	}
	v[curSize] = elem;
	curSize++;
}

template <class T>
void Vector<T>::insert(size_t index, T elem){
	if (index > curSize || index < 0){
		throw std::out_of_range ("index out of range!");
	}
	else if(index == curSize){
		push_back(elem);
		return;
	}
	if(curSize == bufSize){
		alloc_more();
	}
	for (int i = (int) curSize-1; i >= (int) index; i--)
	{
		v[i+1] = v[i];
	}
	v[index] = elem;
	curSize++;
}
template <class T>
void Vector<T>::erase(size_t index){
	if (index >= curSize || index < 0){
		throw std::out_of_range ("index out of range!");
	}
	for (int i = (int) index; i < (int) curSize-1; i++)
	{
		v[i] = v[i+1];
	}
	curSize--;
}
template <class T>
void Vector<T>::clear(){
	curSize = 0;
}
//sort the vector in ascending or descending order
template <class T>
void Vector<T>::sort(bool order){
	if(order){
		std::sort(v, v+curSize);
	}
	else{
		std::sort(v, v+curSize, comp);
	}
}
template <class T>
void Vector<T>::unique_sort(bool order){
	sort(order);
	T* tmp = std::unique (v, v+curSize);
	curSize = tmp-v;
}
template <class T>
bool Vector<T>::exists(const T & elem) const{
	T* tmp = std::find(v, v+curSize, elem);
	return (tmp != v+curSize);
}
template <class T>
Vector<T>::Vector (const std::initializer_list<T> list){
	curSize = list.size();
	bufSize = curSize*4;
	delete[] v;
	v = new T[bufSize];
	int i = 0;
	for(auto elem : list){
		v[i] = elem;
		i++;
	}
}
//return size of the array
template <class T>
size_t Vector<T>::size() const{
	return curSize;
}
// get element with given index
template <class T>
T Vector<T>::get(int index) const{
	if(index < 0 || index >= (int) curSize){
		throw std::out_of_range ("index out of range!");
	}
	return v[index];
}
template <class T>
Vector<T>::Vector(Vector&& ref){
	v = ref.v;
	curSize = ref.size();
	bufSize = ref.bufSize;
	ref.v = NULL;
	ref.curSize = 0;
	ref.bufSize = 0;
}
//operator[] overload for picking out/assigning specific elements
template <class T>
T & Vector<T>::operator[] (int index){
	if(index < 0 || index >= (int) curSize){
		throw std::out_of_range ("index out of range!");
	}
	return v[index];
}
//operator[] overload const version 
template <class T>
const T & Vector<T>::operator[] (int index)const{
	if(index < 0 || index >= (int) curSize){
		throw std::out_of_range ("index out of range!");
	}
	return v[index];
}
//operator= overload for copying 
template <class T>
Vector<T> & Vector<T>::operator=(const Vector & ref){
	if (this != & ref){
		curSize = ref.size();
		bufSize = ref.bufSize;
		delete[] v;
		v = new T[bufSize];
		for (int i = 0; i < (int) curSize; ++i){
			v[i] = ref[i];
		}
	}
	return *this;
}
//move 
template <class T>
Vector<T> & Vector<T>::operator=(Vector && ref)
{
	if (this != &ref)
	{
		delete[] v;
		curSize = ref.size();
		bufSize = ref.bufSize;
		for (int i = 0; i < (int) curSize; ++i){
			v[i] = ref[i];
		}
		ref.v = NULL;
		ref.curSize = 0;
		ref.bufSize = 0;
	}
	return *this;
}

	//operator= overload for init with list
template <class T>
Vector<T> & Vector<T>::operator=(const std::initializer_list<T>& list) {
	curSize = list.size();
	bufSize = curSize*4;
	delete[] v;
	v = new T[bufSize];
	int i = 0;
	for(auto elem : list){
		v[i] = elem;
		i++;
	}
	return *this;
}