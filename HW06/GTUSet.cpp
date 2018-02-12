//
// Sema Köse
// 141044002
// HW06
//
#include "GTUSet.h"
#include "GTUSetBase.h"
#include <iostream>


namespace GTUSetNamespace{
    template <class T>
bool GTUSet<T>::empty(){
    if(ptrSize == 0)
        return true;
    else
        return false;
}


template <class T>
int GTUSet<T>::size(){
    return ptrSize;
}

template <class T>
void GTUSet<T>::insert(const T& key) {
    int dummy = 0;
    try {
        for(int i=0; i<ptrSize; ++i){
            if(key == myPtr.get()[i]){
                dummy = 1;
                break;
            }
        }
        if(dummy==1){
            throw std::bad_exception();
        }else{
            myPtr.get()[ptrSize] = key;
            ++ptrSize;
        }
    }catch(bad_exception& e) {
        cout<<endl;
        cout<<e.what()<<endl;
        cout<<"Key is already exist!"<<endl;
        cout<<endl;
    }
}

template <class T>
void GTUSet<T>::erase(int pos){
    for(int i=pos-1; i<ptrSize; ++i){
        myPtr.get()[i]=myPtr.get()[i+1];
    }
    --ptrSize;
}

template <class T>
void GTUSet<T>::clear(){
    ptrSize = 0;
}

template <class T>
typename GTUSetBase<T>::GTUIterator GTUSet<T>::find(const T& key){
    int pos = 0;
    for(int i=0; i<ptrSize; ++i){
        if(myPtr.get()[i]==key){
            pos = i+1;
            typename GTUSetBase<T>::GTUIterator myIter(myPtr.get()+i);
            myIter.setIndex(i+1);
            return myIter;
        }
    }
    cout<<"Couldn't found the key!"<<endl;
    exit(0);
}

template <class T>
int GTUSet<T>::count(const T &key) {
    int count = 0;
    for(int i=0; i<ptrSize; ++i){
        if(myPtr.get()[i]==key){
            ++count;
        }

    }
    return count;
}

template <class T>
int GTUSet<T>::max_size() {
    return (size()+10);
}
}

