#include "stack.h"
#include <stdexcept>

template <class T>
Stack<T>::Stack() 
{
    capacity = 10;
    data = new T[capacity];
    topIndex = -1;
}

template <class T>
Stack<T>::~Stack() 
{
    delete[] data;
}

template <class T>
void Stack<T>::resize() 
{
    capacity *= 2;
    T* newData = new T[capacity];
    for(int i = 0; i <= topIndex; i++) 
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template <class T>
void Stack<T>::push(T value) 
{
    if(topIndex + 1 >= capacity) 
    {
        resize();
    }
    data[++topIndex] = value;
}

template <class T>
void Stack<T>::pop() 
{
    if(isEmpty()) 
    {
        throw std::out_of_range("Stack is empty");
    }
    topIndex--;
}

template <class T>
T Stack<T>::top() 
{
    if(isEmpty()) 
    {
        throw std::out_of_range("Stack is empty");
    }
    return data[topIndex];
}

template <class T>
bool Stack<T>::isEmpty() 
{
    return topIndex == -1;
}
