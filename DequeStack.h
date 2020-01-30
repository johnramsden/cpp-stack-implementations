#ifndef STACK_DEQUESTACK_H
#define STACK_DEQUESTACK_H

#include <deque>
#include "Stack.h"

template <class T>
class DequeStack: public Stack<T> {
public:
    void push (const T& val);
    T pop ();
    bool empty();
private:
    std::deque<T> stack;
};

template<class T>
void
DequeStack<T>::push(const T &val) {
    stack.push_back(val);
}

template<class T>
T
DequeStack<T>::pop() {
    T v = stack.back();
    stack.pop_back();
    return v;
}

template<class T>
bool
DequeStack<T>::empty() {
    return stack.empty();
}

#endif //STACK_DEQUESTACK_H
