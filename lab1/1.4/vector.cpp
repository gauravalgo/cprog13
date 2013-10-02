#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include "vector.h"

Vector::Vector(int size)
{
  current_size = size;
  data = new int[current_size];
  for(int i = 0; i < current_size; i++) {
    data[i] = 0;
  }
}

Vector::Vector() {
  std::cout << "default constructor" << std::endl;
}

Vector::Vector( const Vector& other ) :
  current_size(other.current_size),
  data( other.data )
{
}

Vector::Vector( std::initializer_list<int> l)
{
  current_size = l.size();
  data = new int[current_size];
  std::initializer_list<int>::iterator it;  // same as: const int* it
  int i = 0;
  for ( it=l.begin(); it!=l.end(); ++it) {
    set(i,*it);
    i++;
  }
}

// Vector& Vector::operator= ( std::initializer_list<int> l)
// {
//   std::cout << "initializer list" << std::endl;
//   return *this;
// }

int Vector::get_size( void )
{
  return current_size;
}

unsigned int Vector::get( const int index ) {
  if (Vector::is_out_of_bounds(index))
    throw std::runtime_error("Out of bounds");
  return data[index];
}

unsigned int Vector::operator[] (const int index) {
  return get(index);
}

// Vector& Vector::operator= ( int *input ) {
//   data = input;
//   current_size = 3;
//   return *this;
// }


void Vector::set(int index, int new_value) {
  if (Vector::is_out_of_bounds(index))
    throw std::runtime_error("Out of bounds");
  data[index] = new_value;

}

bool Vector::is_out_of_bounds(int index) {
  if (current_size <= index) {
    return true;
  }
  return false;
}

