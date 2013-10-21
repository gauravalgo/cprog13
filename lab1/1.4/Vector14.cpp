#include "Vector.h"

//initializer without argument
Vector::Vector(){
	v = new unsigned int[0];
	size = (size_t) 0;
}
//init with size
Vector::Vector(const size_t s){
	if(s < 0){
		throw std::out_of_range ("index out of range!");
	}
	v = new unsigned int[s];
	size = s;
	for (int i = 0; i < (int) size; ++i)
	{
		v[i] = 0;
	}
}
//destructor
Vector::~Vector(){
	delete[] v;
}
//copy constructor
Vector::Vector(const Vector & ref){
	size = ref.get_size();
	v = new unsigned int[size];
	for (int i = 0; i < (int )size; ++i)
	{
		v[i] = ref.get(i);
	}
}
//return size of the array
size_t Vector::get_size() const{
	return size;
}
// get element with given index
unsigned int Vector::get(int index) const{
	if(index < 0 || index > (int) size-1){
		throw std::out_of_range ("index out of range!");
	}
	return v[index];
}
Vector::Vector(Vector&& ref){
	v = ref.v;
	size = ref.get_size();
	ref.v = NULL;
	ref.size = 0;
}
//operator[] overload for picking out/assigning specific elements
unsigned int & Vector::operator[] (int index){
	if(index < 0 || index > (int) size-1){
		throw std::out_of_range ("index out of range!");
	}
	return v[index];
}
//operator[] overload const version 
const unsigned int & Vector::operator[] (int index)const{
	if(index < 0 || index > (int) size-1){
		throw std::out_of_range ("index out of range!");
	}
	return v[index];
}
//operator= overload for copying 
Vector & Vector::operator=(const Vector & ref){
	if (this != & ref){
		size = ref.get_size();
		delete[] v;
		v = new unsigned int[size];
		for (int i = 0; i < (int) size; ++i){
			v[i] = ref[i];
		}
	}
	return *this;
}
//operator= overload for init with list
Vector & Vector::operator=(const std::initializer_list<int>& list) {
	size_t len = list.size();
	delete[] v;
	v = new unsigned int[len];
	int i = 0;
	for(auto elem : list){
		v[i] = elem;
		i++;
	}
	return *this;
}	
Vector & Vector::operator=(Vector && ref)
{
	if (this != &ref)
	{
		delete[] v;
		size = ref.get_size();
		for (int i = 0; i < (int) size; ++i){
			v[i] = ref[i];
		}
		ref.v = NULL;
		ref.size = 0;
	}
	return *this;
}