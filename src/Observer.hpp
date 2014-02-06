#ifndef OBSERVER_HPP
#define OBSERVER_HPP
template<class E>
class Observer
{
    public:
        virtual void update(E data, void (*function)())=0;
};
#endif
