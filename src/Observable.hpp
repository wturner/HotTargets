#include"Observer.hpp"
#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP
template<class E>
class Observable
{
    public:
        virtual void add_observer(Observer<E>* o)=0;
        virtual void notify_observers()=0;
        virtual void remove_observer(Observer<E>* o)=0;
};
#endif
