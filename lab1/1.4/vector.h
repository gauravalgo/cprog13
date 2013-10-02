#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
  private:
    int *data;
    unsigned int current_size;
    bool is_out_of_bounds(int index);
  public:
    // Vector& operator=(const Vector& input);
    // Vector& operator=(int *input);
    Vector( std::initializer_list<int> l );
    Vector(int size);
    Vector();
    Vector(const Vector& other);
    Vector operator= (std::initializer_list<int> l);
    int get_size();
    unsigned int get(const int index);
    unsigned int operator[] (const int index);

    void set(int index, int new_value);
};

#endif
