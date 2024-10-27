#ifndef STACK_H
#define STACK_H

template <class T>
class Stack 
{
private:
    T* data;
    int capacity;
    int topIndex;
    void resize();

public:
    Stack();
    ~Stack();
    void push(T value);
    void pop();
    T top();
    bool isEmpty();
};

#include "stack.cpp"

#endif
