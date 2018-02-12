//
// Sema Köse
// 141044002
// HW06
//

#include "GTUSet.h"
#include "GTUMap.h"

namespace GTUSetNamespace{
template <class K, class V>
V& GTUMap<K,V>::operator[](const K& k) {
    bool dummy = false;
    int i=0;
    for(i=0; i<GTUSet<std::pair<K, V> >::size(); ++i){
        if(GTUSet<std::pair<K, V> >::myPtr.get()[i].first == k){
            dummy = true;
            break;
        }
    }
    if(dummy == true)
        return (GTUSet<std::pair<K, V> >::myPtr.get()[i].second);
    else{
        GTUSet<std::pair<K, V> >::myPtr.get()[i].first = k;
        increaseSize();
        return (GTUSet<std::pair<K, V> >::myPtr.get()[i].second);
    }

}
}
