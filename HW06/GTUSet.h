//
// Sema Köse
// 141044002
// HW06
//
#include "GTUSetBase.h"

#ifndef HW06_GTUSET_H
#define HW06_GTUSET_H


#include <memory>

namespace GTUSetNamespace{
    template<class T>
class GTUSet: public GTUSetBase<T>{
public:
    GTUSet() {myPtr.reset(new T);};
    bool empty();
    int size();
    int max_size();
    void insert(const T& key);
    void erase(int pos);
    void clear();
    typename GTUSetBase<T>::GTUIterator find(const T& key);
    int count(const T& key);

    typename GTUSetBase<T>::GTUIterator begin() const{
        typename GTUSetBase<T>::GTUIterator myIter(myPtr.get()); //return first element's address
        return myIter;
    }

    typename GTUSetBase<T>::GTUIterator end() const{
        typename GTUSetBase<T>::GTUIterator myIter(myPtr.get() + ptrSize -1); //return last element's address
        return myIter;
    }

protected:
    int ptrSize = 0;
    shared_ptr<T> myPtr;
};
}



#endif //HW06_GTUSET_H
