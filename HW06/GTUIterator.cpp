//
// Sema Köse
// 141044002
// HW06
//
#include "GTUSet.h"
namespace GTUSetNamespace{
template <class T>
typename GTUSetBase<T>::GTUIterator GTUSetBase<T>::GTUIterator::operator++() {
    GTUIterator it = *this;
    ++ptr;
    return it;
}

template <class T>
typename GTUSetBase<T>::GTUIterator GTUSetBase<T>::GTUIterator::operator++(int) {
    GTUIterator it = *this;
    ++it;
    return *this;
}

template <class T>
typename GTUSetBase<T>::GTUIterator GTUSetBase<T>::GTUIterator::operator--() {
    GTUIterator it = *this;
    --ptr;
    return it;
}

template <class T>
typename GTUSetBase<T>::GTUIterator GTUSetBase<T>::GTUIterator::operator--(int) {
    GTUIterator it = *this;
    --it;
    return *this;
}

template <class T>
void  GTUSetBase<T>::GTUIterator::operator=(const GTUIterator &oth) {
    ptr = oth.ptr;
}

template <class T>
bool  GTUSetBase<T>::GTUIterator::operator==(const GTUIterator &oth) {
    return(ptr == oth.ptr);
}

template <class T>
bool  GTUSetBase<T>::GTUIterator::operator!=(const GTUIterator &oth) {
    return(ptr != oth.ptr);
}

template <class T>
int GTUSetBase<T>::GTUIterator::operator*() {
    /*index = *ptr;
    return(&index);*/
    return(index);
}

template <class T>
T GTUSetBase<T>::GTUIterator::operator->() {
    return &(*ptr);
}
}




