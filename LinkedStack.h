#ifndef STACK_LINKEDSTACK_H
#define STACK_LINKEDSTACK_H

#include <list>

template <class T>
class LinkedStack {
    public:
    void push (const T& val);
    T pop ();
    bool empty();
    private:
        std::list<T> stack;
};

template<class T>
void
LinkedStack<T>::push(const T &val) {
    stack.push_back(val);
}

template<class T>
T
LinkedStack<T>::pop() {
    T v = stack.back();
    stack.pop_back();
    return v;
}

template<class T>
bool
LinkedStack<T>::empty() {
    return stack.empty();
}

#endif //STACK_LINKEDSTACK_H
