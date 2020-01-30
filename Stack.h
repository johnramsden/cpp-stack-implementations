#ifndef STACK_STACK_H
#define STACK_STACK_H

template <class T>
class Stack {
public:
    virtual void push(const T& val) = 0;
    virtual T pop() = 0;
    virtual bool empty() = 0;
};

#endif //STACK_STACK_H
