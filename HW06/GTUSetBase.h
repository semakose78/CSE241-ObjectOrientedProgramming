//
// Sema Köse
// 141044002
// HW06
//
#include <iostream>
using namespace std;

#ifndef HW06_GTUSETBASE_H
#define HW06_GTUSETBASE_H


namespace GTUSetNamespace{
    template <class T> class GTUSetBase {
public:
    virtual bool empty()= 0; //Test whether container is empty
    virtual int size() = 0; //Return container size
    virtual int max_size() = 0; //Return maximum size
    virtual void insert(const T& key) = 0; //Insert element, throws exception std::bad_pafram if the element is already in the set
    virtual void erase(int pos) = 0; //Erase element
    virtual void clear() = 0; //Clear all content
    virtual int count(const T& key) = 0; //Count elements with a specific value


    class GTUIterator: public std::iterator<std::forward_iterator_tag, T>{
    public:
        GTUIterator(T* pointer): ptr(pointer){};

        GTUIterator operator++();
        GTUIterator operator++(int);
        GTUIterator operator--();
        GTUIterator operator--(int);
        int operator*();
        T operator->();
        void operator=(const GTUIterator& oth);
        bool operator==(const GTUIterator& oth);
        bool operator!=(const GTUIterator& oth);
        T get(){return *ptr;};
        void setIndex(int inx){index = inx;};

    private:
        T* ptr;
        int index = 0;

    };
    virtual GTUSetBase<T>::GTUIterator find(const T& key) = 0; //Get iterator to element
    virtual GTUSetBase<T>::GTUIterator begin() const = 0; //Return iterator to beginning
    virtual GTUSetBase<T>::GTUIterator end() const = 0; //Return iterator to end
};
}



#endif //HW06_GTUSETBASE_H
