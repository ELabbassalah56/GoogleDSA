#ifndef _DYNAMIC_ARRAY_HPP_
#define _DYNAMIC_ARRAY_HPP_
#include "dynamic-array.hpp.in"
#include <iostream>

template <typename T>
class dynamicArray
{
private:
T  *arr ;
int length; //User length thinks
int capacity; // Actual Size
        
public:
        dynamicArray(/* args */);
        dynamicArray(int capacity);
        int Size();
        bool isEmpty();
        T get(int index);
        void set(int index,T elem);
        void clear();
        void add(T elem);
        T removeAt(int rm_index); //remove element in certian index
        bool remove(dynamicArray obj); 
        int  indexOf(dynamicArray obj);
        bool contains(dynamicArray obj);
        void iteratorShow();
        T begin();
        T end();
        ~dynamicArray();
};

#endif 