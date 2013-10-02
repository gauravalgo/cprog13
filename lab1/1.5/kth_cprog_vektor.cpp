#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <initializer_list>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

template<class T> class Vector
{
  private:
    T *data;
    size_t current_size;
    size_t current_max_size;
    // bool is_out_of_bounds(int index);
  public:
    // Vector& operator=(const Vector& input);
    Vector<T>& operator=(const Vector<T>&);
    Vector<T>& operator=(const std::initializer_list<T>);

    // T &operator[](int i);
    Vector();
    explicit Vector(size_t, T);
    Vector(size_t);
    Vector<T>( const std::initializer_list<T>);
    Vector(const Vector& other);
    size_t size() const;
    T& get(const int index) const;
    T& operator[] (const int index) const;

    void push_back(const T in);
    void insert(int where, T in);
    
    void sort(bool type);
    void unique_sort(bool type);

    bool exists(const T & in);
    void erase(int i);
    void clear();

    void set(int index, int new_value);
};

#endif
#ifndef VECTOR_H
#include "vector.h"
#include <initializer_list>
#endif

template<class T> Vector<T>::Vector(size_t size)
{
  // std::cout << "Constructor (size):" << std::endl;
  current_size = size;
  current_max_size = 10 * size;
  data = new T[current_max_size];
  for(int i = 0; i < current_size; i++) {
    data[i] = 0;
  }
}

template<class T> Vector<T>::Vector(size_t size, T defValue) {
  current_size = size;
  current_max_size = size*10;
  data = new T[current_max_size];
  for (int i = 0; i < current_size; i++) {
    data[i] = defValue;
  }
}

template<class T> Vector<T>::Vector() {
  // std::cout << "Constructor default:" << std::endl;
  current_size = 0;
  current_max_size = 10;
  data = new T[current_max_size];
  for(int i = 0; i < current_size; i++) {
    data[i] = 0;
  }
  // std::cout << "default constructor" << std::endl;
}

template<class T> Vector<T>::Vector( const Vector<T>& other ) :
  current_size(other.current_size),
  data( other.data ),
  current_max_size(other.current_max_size)
{
  // std::cout << "Constructor copy:" << std::endl;
}
template<class T> Vector<T>::Vector( const std::initializer_list<T> l) {
  current_size = l.size();
  data = new T[current_size];
  typename std::initializer_list<T>::iterator it;  // same as: const int* it
  int i = 0;
  
  for ( it=l.begin(); it!=l.end(); ++it) {
    // set(i,*it);
    // i++;
    data[i] = *it;
    i++;
  }
}

template<class T> Vector<T> &Vector<T>::operator=(const std::initializer_list<T> l)
{
  current_size = l.size();
  data = new T[current_size];

  typename std::initializer_list<T>::iterator it;
  int i = 0;

  for (it=l.begin(); it!=l.end(); ++it) {
    data[i] = *it;
    i++;
  }
  std::cout << "initializer list" << std::endl;
  return *this;
}

// template<class T> void Vector<T>::operator[](int i) {
// }

template<class T> Vector<T> &Vector<T>::operator=(const Vector<T>& rhs) {
  std::cout << "operator=" << std::endl;
  return *this;
}

template<class T> size_t Vector<T>::size() const
{
  return current_size;
}

template<class T> T& Vector<T>::operator[] (const int index) const {
  if (index < 0 || index >= current_size) {
  // if (Vector::is_out_of_bounds(index) ){
    // std::cout << "is out of bounds" << std::endl;
    throw std::out_of_range("Out of bounds");
    // throw std::runtime_error("Out of bounds");
  }
  // std::cout << "was out of bounds" << std::endl;
  return get(index);
}

template<class T> T& Vector<T>::get( const int index ) const {
  if (index < 0 || index >= current_size) {
  // if (Vector::is_out_of_bounds(index)) {
    throw std::out_of_range("Out of bounds");
    // throw std::runtime_error("Out of bounds");
  }
  return data[index];
}

template<class T> void Vector<T>::insert(int index, T new_value) {
  if (index < 0 || index >= current_size) {
  // if (Vector::is_out_of_bounds(index)) {
    throw std::out_of_range("Out of bounds");
  }
  
  current_size += 1;

  for( int i = current_size; i > index; i-- ) {
    // std::cout << data[i-1] << ", " << new_value << std::endl;
    data[i] = data[i-1];
  }

  data[index] = new_value;

  // std::cout << data[0] << ", " << data[1] << std::endl;
}

// template<class T> bool Vector<T>::is_out_of_bounds(int index){
//   if (index < 0 || index >= current_size) {
//     // std::cout << index << ", " << current_size << std::endl;
//     return true;
//   }
//   return false;
// }

template<class T> void Vector<T>::push_back(const T in) {
  data[current_size] = in;
  current_size += 1;
}

template<class T> void Vector<T>::sort(bool asc) {
  if(asc) {
    // std::cout << "true" << std::endl;
    std::sort(data, data + current_size, std::less<T>());
  } else {
    // std::cout << "false" << std::endl;
    std::sort(data, data + current_size, std::greater<T>());
  }
  // std::cout << data[0] << data[1] << std::endl;
}

template<class T> void Vector<T>::unique_sort(bool asc) {
  sort(asc);
  T* tmp = data; 
  
  // int new_size = std::distance(data, std::unique(data, data + current_size));
  // current_size = new_size;
  
  T* ptr = std::unique(data, data+current_size);
  current_size = ptr-data;
}

template<class T> bool Vector<T>::exists(const T & in) {
  T* res = std::find(data, data + current_size, in);
  return (res != data+current_size);
}

template<class T> void Vector<T>::erase(int index) {
  for (int i= index; i < current_size; i++) {
    data[i] = data[i+1];
  }
  current_size -= 1;
}

template<class T> void Vector<T>::clear() {
  current_size = 0;
}

template class Vector<int>;
template class Vector<double>;
template class Vector<char>;
