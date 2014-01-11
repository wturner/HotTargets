#include"Observer.hpp"
#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP
template<class E>
class Observable
{
    public:
        virtual void addObserver(Observer<E>* o)=0;
        virtual void notifyObservers()=0;
        virtual void removeObserver(Observer<E>* o)=0;
};
#endif
