//
// Created by Ziad Nasser on 2022-12-08.
//

#include "YZVector.h"

template<class T>
YZVector<T>::YZVector(int cap) {
    size = 0;
    capacity = cap;
    data = new T[capacity];

}

template<class T>
YZVector<T>::~YZVector() {
    delete[] data;
    data = nullptr;
}

template<class T>
T &YZVector<T>::operator[](int indx) {
    if(indx > size-1){
        cout << "An error has occured, index out of range." << endl;
        exit(-1);
    }
    return data[indx];
}

template<class T>
int YZVector<T>::push_back(T item) {
    if(size < capacity){
        data[size++] = item;
        return size;
    }
    else{
        T* newdata = new T[capacity*2];
        capacity *= 2;

        for(int i = 0; i < size; i++){
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        newdata = nullptr;
        data[size++] = item;
        return size;
    }
}

template<class T>
int YZVector<T>::Size() const {
    return size;
}

template<class T>
int YZVector<T>::Capacity() const {
    return capacity;
}

template<class T>
bool YZVector<T>::empty() const {
    return size == 0;
}

template<class T>
int YZVector<T>::resize(int newsize) {
    if(newsize > capacity){
        T* newdata = new T[newsize];
        for(int i = 0; i < size; i++){
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        newdata = nullptr;
        size = newsize;
        capacity = newsize;
        return size;
    }
    else{
        size = newsize;
        return size;
    }
}


template<class T>
T YZVector<T>::pop_back() {
    if(size == 0){
        cout << "An error has occured, vector is empty." << endl;
        exit(-1);
    }
    else{
        size--;
        return data[size];
    }
}

template<class T>
typename YZVector<T>::iterator YZVector<T>::begin() {
    return iterator(data);
}

template<class T>
typename YZVector<T>::iterator YZVector<T>::end() {
    return iterator(data + size);
}

template<class T>
void YZVector<T>::erase(YZVector::iterator it) {
    if(it == end()){
        cout << "An error has occured, iterator is out of range." << endl;
        exit(-1);
    }
    else{
        for(int i = 0; i < size; i++){
            if(data + i == it){
                for(int j = i; j < size; j++){
                    data[j] = data[j+1];
                }
                size--;
                break;
            }
        }
    }

}

template<class T>
void YZVector<T>::erase(YZVector::iterator start, YZVector::iterator end) {
    if(start == end){
        cout << "An error has occured, iterators are out of range." << endl;
        exit(-1);
    }
    else if(start > end){
        cout << "An error has occured, start iterator is greater than end iterator." << endl;
        exit(-1);
    }
    else{
        int startindex = 0;
        int endindex = 0;
        for(int i = 0; i < size; i++){
            if(data + i == start){
                startindex = i;
            }
            if(data + i == end){
                endindex = i;
            }
        }
        for(int i = startindex; i < endindex; i++){
            for(int j = i+1; j < size; j++){
                data[j] = data[j+1];
            }
            size--;
        }
    }
}

template<class T>
void YZVector<T>::clear() {
    size = 0;
}

template<class T>
void YZVector<T>::insert(YZVector::iterator it, T item) {
    if(it == end()){
        cout << "An error has occured, iterator is out of range." << endl;
        exit(-1);
    }
    else{
        for(int i = 0; i < size; i++){
            if(data + i == it){
                if(size < capacity){
                    for(int j = size; j > i; j--){
                        data[j] = data[j-1];
                    }
                    data[i] = item;
                    size++;
                    break;
                }
                else{
                    T* newdata = new T[capacity*2];
                    capacity *= 2;

                    for(int j = 0; j < i; j++){
                        newdata[j] = data[j];
                    }
                    newdata[i] = item;
                    for(int j = i+1; j < size; j++){
                        newdata[j] = data[j-1];
                    }
                    delete[] data;
                    data = newdata;
                    newdata = nullptr;
                    size++;
                    break;
                }
            }
        }
    }

}

template<class T>
bool YZVector<T>::operator==(const YZVector<T> &other) {
    if(size != other.size){
        return false;
    }
    else{
        for(int i = 0; i < size; i++){
            if(data[i] != other.data[i]){
                return false;
            }
        }
        return true;
    }
}

template<class T>
bool YZVector<T>::operator<(const YZVector<T> &other) {
    if(size < other.size){
        return true;
    }
    else if(size > other.size){
        return false;
    }
    else{
        for(int i = 0; i < size; i++){
            if(data[i] < other.data[i]){
                return true;
            }
            else if(data[i] > other.data[i]){
                return false;
            }
        }
        return false;
    }
}



template<class T>
YZVector<T>::YZVector(const YZVector &vec) {
    size = vec.size;
    capacity = vec.capacity;
    data = new T[capacity];
    for(int i = 0; i < size; i++){
        data[i] = vec.data[i];
    }
}

template<class T>
YZVector<T>::YZVector(T *arr, int size) {
    this->size = size;
    capacity = size;
    data = new T[capacity];
    for(int i = 0; i < size; i++){
        data[i] = arr[i];
    }
}

template<class T>
YZVector<T> &YZVector<T>::operator=(const T &other) {
    if(this != &other){
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for(int i = 0; i < other.size; i++){
            data[i] = other.data[i];
        }
    }
    else{
        cout << "Cannot delete self" << endl;
    }
}

template <class T>
ostream &operator<<(ostream &out, YZVector<T> &vec) {
    for(int i = 0; i < vec.size; i++){
        out << vec.data[i] << " ";
    }
    return out;
}
