#ifndef STACK_VECSTACK_H
#define STACK_VECSTACK_H

#include <vector>

template <class T>
class VecStack {
    public:
        void push (const T& val);
        T pop ();
        bool empty();
    private:
        std::vector<T> stack;
        int todelete = 0;
};


template<class T>
void
VecStack<T>::push(const T &val) {
    stack.erase(stack.end()-todelete, stack.end());
    todelete = 0;
    stack.push_back(val);
}

template<class T>
T
VecStack<T>::pop() {
    todelete++;
    return *(stack.end()-todelete);
}

template<class T>
bool
VecStack<T>::empty() {
    return (stack.size() == todelete);
}

#endif //STACK_VECSTACK_H
