//
// Sema Köse
// 141044002
// HW06
//

#ifndef HW06_GTUMAP_H
#define HW06_GTUMAP_H


#include "GTUSet.h"

#include <iostream>
using namespace std;
namespace GTUSetNamespace{
	template <class K, class V>
class GTUMap: public GTUSet<std::pair<K, V> > {
public:
    V& operator[] (const K& k);
    void increaseSize(){++GTUSet<std::pair<K, V> >::ptrSize;}; //for adding new element to map
};




}
#endif //HW06_GTUMAP_H