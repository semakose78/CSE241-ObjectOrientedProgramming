//
// Sema Köse
// 141044002
// HW06
//

#include <iostream>

#include "GTUSetBase.h"
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GTUIterator.cpp"
#include "GTUMap.h"
#include "GTUMap.cpp"



namespace GTUSetNamespace{
    template <class T>
    std::shared_ptr<GTUSetBase<T> > setIntersection (const GTUSetBase<T>&, const GTUSetBase<T>&);
}

using namespace GTUSetNamespace;

int main() {
    GTUSet<int> mySet;
    mySet.insert(2); //test of insert()
    mySet.insert(5);
    mySet.insert(2); //throw exception
    mySet.insert(1);
    mySet.insert(7);
    mySet.insert(9);
    mySet.insert(6);

    cout<<"Printing elements in a set : "<<endl<<endl;
    GTUSetBase<int>::GTUIterator it = mySet.begin(); //test of begin()
    for(;;){
        if(it != mySet.end()){ //test of end()
            cout<<it.get()<<" ";
            ++it; //test of operator++()
        }else if(it == mySet.end()){ //test of operator==()
            cout<<it.get()<<" ";
            break;
        }
    }

    cout<<endl;
    cout<<endl<<"Size of the set is : "<<mySet.size(); //Test of the size() function

    cout<<endl;
    cout<<endl<<"Max size of the set is : "<<mySet.max_size(); //Test of the max_size() function

    cout<<endl;
    cout<<endl<<"Count of the 5's in the set is : "<<mySet.count(5); //Test of the count() function

    cout<<endl;
    cout<<endl<<"Count of the 11's in the set is : "<<mySet.count(11); //Test of the count() function

    cout<<endl<<endl<<"Erasing 3rd element of the set : "<<endl<<endl; //Test of the erase() function
    mySet.erase(3);

    cout<<"Printing new elements in the set : "<<endl<<endl;
    it = mySet.begin(); //test of begin()
    for(;;){
        if(it != mySet.end()){ //test of end()
            cout<<it.get()<<" ";
            ++it; //test of operator++()
        }else if(it == mySet.end()){ //test of operator==()
            cout<<it.get()<<" ";
            break;
        }
    }

    cout<<endl<<endl<<"Printing it reverse : "<<endl<<endl;

    GTUSetBase<int>::GTUIterator it2 = mySet.end();

    for(;;){
        if(it2 != mySet.begin()){ //test of operator!=()
            cout<<it2.get()<<" ";
            --it2; //test of operator--()
        }else if(it2 == mySet.begin()){
            cout<<it2.get()<<" ";
            break;
        }
    }

    cout<<endl<<endl<<"Addresses of some elements : "<<endl; //test of operator*()
    cout<<endl<<"5 at the ["<<*mySet.find(5)<<"]"<<endl; //test of find()
    cout<<endl<<"7 at the ["<<*mySet.find(7)<<"]"<<endl;
    cout<<endl<<"2 at the ["<<*mySet.find(2)<<"]"<<endl;
    cout<<endl<<"6 at the ["<<*mySet.find(6)<<"]"<<endl;

    cout<<endl<<"Clearing the set"<<endl<<endl;
    mySet.clear(); //Test of clear() function

    if(mySet.empty())//Test of empty() function
        cout<<"My set is empty"<<endl<<endl;
    else
        cout<<"My set is not empty"<<endl<<endl;


    cout<<"Adding new elements to set"<<endl<<endl;
    mySet.insert(11);
    mySet.insert(16);
    mySet.insert(22);
    mySet.insert(8);

    cout<<"Printing new elements in the set : "<<endl<<endl;
    it = mySet.begin(); //test of begin()
    //cout<<"address of first element is: "<<*it<<endl;
    for(;;){
        if(it != mySet.end()){ //test of end()
            cout<<it.get()<<" ";
            ++it; //test of operator++()
        }else if(it == mySet.end()){ //test of operator==()
            cout<<it.get()<<" ";
            break;
        }
    }
    cout<<endl;

    GTUMap<int,int> mmap;
    cout<<endl<< "My map :  " <<endl<<endl;

    mmap.insert(std::make_pair(3,4));
    mmap.insert(std::make_pair(4,5));
    mmap.insert(std::make_pair(5,6));
    //mmap.insert(std::make_pair(6,7));

   // mmap[7] = 3;
    //mmap[8] = 2;

    GTUSetBase<std::pair<int , int>>::GTUIterator it3 = mmap.begin();
    for(;;){
        if(it3 != mmap.end()){ //test of operator!=()
            cout<<"("<<it3.get().first<<", ";
            cout<<it3.get().second<<")"<<endl;
            ++it3; //test of operator--()
        }else if(it3 == mmap.end()){
            cout<<"("<<it3.get().first<<", ";
            cout<<it3.get().second<<")"<<endl;
            break;
        }
    }


    //Intersection test code

    cout<<endl<<"Test of intersection : "<<endl;
    cout<<endl<<"1st Set : "<<endl<<endl;
    it = mySet.begin(); //test of begin()
    for(;;){
        if(it != mySet.end()){ //test of end()
            cout<<it.get()<<" ";
            ++it; //test of operator++()
        }else if(it == mySet.end()){ //test of operator==()
            cout<<it.get()<<" ";
            break;
        }
    }

    GTUSet<int> my2Set;
    my2Set.insert(11);
    my2Set.insert(5);
    my2Set.insert(8);
    my2Set.insert(22);

    cout<<endl<<endl<<"2nd Set : "<<endl<<endl;
    it = my2Set.begin(); //test of begin()
    for(;;){
        if(it != my2Set.end()){ //test of end()
            cout<<it.get()<<" ";
            ++it; //test of operator++()
        }else if(it == my2Set.end()){ //test of operator==()
            cout<<it.get()<<" ";
            break;
        }
    }
    cout<<endl;

    shared_ptr<GTUSetBase<int> > newSet;
    newSet = setIntersection (mySet, my2Set);
    int size = newSet.get()->size();
    GTUSetBase<int>::GTUIterator iteratorIntersect = newSet.get()->begin();

    cout<<endl<<"Intersection of these 2 sets is : "<<endl<<endl;
    for(iteratorIntersect = newSet.get()->begin(); iteratorIntersect != newSet.get()->end();++iteratorIntersect)
        cout<<iteratorIntersect.get()<<" ";
    cout<<endl;


    return 0;
}
namespace GTUSetNamespace{
    template <class T>
    std::shared_ptr<GTUSetBase<T> > setIntersection (const GTUSetBase<T>& firstP, const GTUSetBase<T>& secondP){
        GTUSet<T> newSet;
        typename GTUSetBase<T >::GTUIterator it1 = firstP.begin();
        typename GTUSetBase<T >::GTUIterator it2 = secondP.begin();
        shared_ptr<GTUSet<T> > ptr;
        ptr.reset(new GTUSet<T>);
        int i=0;
        //start from the first element of the 1st set and compare it with 2nd set's all elements
        //repeat that for every element in first set
        for(it1=firstP.begin(); it1!=firstP.end(); ++it1){
            for(it2=secondP.begin(); it2!=secondP.end(); ++it2){
                if(it1.get() == it2.get()){
                    newSet.insert(it1.get());
                }
            }
            if(it2==secondP.end()){
                if(it1.get() == it2.get()){
                    newSet.insert(it1.get());
                }
            }
        }
        if(it1==firstP.end()){
            for(it2=secondP.begin(); it2!=secondP.end(); ++it2){
                if(it1.get() == it2.get()){
                    newSet.insert(it1.get());
                    ++i;
                }
            }
            if(it2==secondP.end()){
                if(it1.get() == it2.get()){
                    newSet.insert(it1.get());
                }
            }
        }
        ptr.get()[0] = newSet;
        return ptr;
    }
}
