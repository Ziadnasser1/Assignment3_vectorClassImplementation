//
// Created by Ziad Nasser on 2022-12-08.
//

#ifndef ASSIGNMENT3OOP_YZVECTOR_H
#define ASSIGNMENT3OOP_YZVECTOR_H
#include <iostream>

using namespace std;

template <class T>
class YZVector{
private:
    int size, capacity;
    T* data;
public:
    YZVector(int cap = 2);
    YZVector(T* arr, int size);
    YZVector(const YZVector& vec);
    ~YZVector();

    YZVector &operator=(const T& other);

    typedef T* iterator;

    //Access operations
    T& operator[](int indx);

    //Modifying operations
    int push_back(T item);
    T pop_back();
    void erase(iterator it);
    void erase(iterator start, iterator end);
    void clear();
    void insert(iterator it, T item);

    //comparison operations
    bool operator==(const YZVector<T>& other);
    bool operator<(const YZVector<T>& other);


    //capacity operations
    int Size() const;
    int Capacity() const;
    bool empty() const;
    int resize(int newsize);



    //iterators
    iterator begin();
    iterator end();

    //friends
    friend  ostream& operator<<(ostream& out,YZVector<T>& vec);
};
#endif //ASSIGNMENT3OOP_YZVECTOR_H



//    class iterator {
//    private:
//        T* ptr;
//    public:
//        iterator(T* p = nullptr) : ptr(p) {}
//        T& operator*() { return *ptr; }
//        T* operator->() { return ptr; }
//        iterator& operator++() { ptr++; return *this; }
//        iterator operator++(int) { iterator temp = *this; ptr++; return temp; }
//        bool operator==(const iterator& rhs) { return ptr == rhs.ptr; }
//        bool operator!=(const iterator& rhs) { return ptr != rhs.ptr; }
//    };
