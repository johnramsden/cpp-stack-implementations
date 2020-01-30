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
        int top;
};


template<class T>
void
VecStack<T>::push(const T &val) {
    stack.push_back(val);
}

template<class T>
T
VecStack<T>::pop() {
    auto v = stack[stack.size()-1];
    stack.pop_back();
    return v;
}

template<class T>
bool
VecStack<T>::empty() {
    return stack.empty();
}

#endif //STACK_VECSTACK_H
