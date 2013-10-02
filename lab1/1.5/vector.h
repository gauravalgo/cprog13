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
