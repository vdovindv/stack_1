#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define defval 10
#include <cstdlib>
#include "Megaerror.h"

template <typename T>

class Stack {

private:
    T *data;
    int capacity;
    int size;
    //int sum;
public:
    Stack(int usercapacity);
    Stack();
    Stack(const Stack &prestack);
    int Ok();
    //int checksum();
    int printstack();
    int push(T stackelem);
    T pop();
    ~Stack();
};

template <typename T>

int Stack<T>::Ok()
{
    if(size < 0)
    {
        return -1;
    }
    if(capacity <= 0)
    {
        return -1;
    }
    if(size > capacity)
    {
        return -1;
    }
    return 0;
}

/*template <typename T>
int Stack<T>::checksum()
{
    return sum = &data + capacity + size;
}*/

template <typename T>
int Stack<T>::printstack()
{
    if(Ok())
    {
       std::string ermes = "Unable to print Stack";
       Megaerror err(2, __LINE__, ermes, __PRETTY_FUNCTION__, __FILE__, err);
       throw err;
    }
    for(int i = 0; i < size; i++)
        cout << "Element " << size - i << ": " << data[size - i - 1] << endl;
    cout << "Size:" << size << endl;
    cout << "Capacity:" << capacity << endl;
    return 0;
}

template <typename T>

Stack<T>::Stack(int usercapacity)
{
   capacity = usercapacity;
   size = 0;
   if(Ok())
   {
       std::string ermes = "Failure in stack constructing, check parameters of constructor";
       Megaerror err(1, __LINE__, ermes, __PRETTY_FUNCTION__, __FILE__, err);
       throw err;
   }
   data = new T[usercapacity];
   //checksum();
}

template <typename T>

Stack<T>::Stack(const Stack &prestack)
{
    capacity = prestack.capacity;
    size = prestack.size;
    data = new T[capacity];
    for(int i = 0; i < size; i++)
    {
        data[i] = prestack.data[i];
    }
}

template <typename T>

Stack<T>::Stack(): capacity(defval)
{
        data = new T[capacity];
        size = 0;
}

template <typename T>

Stack<T>::~Stack()
{
    delete [] data;
}

template <typename T>

int Stack<T>::push(T stackelem)
{
    if(Ok())
    {
        std::string ermes = "Can't push elements in stack more";
        Megaerror err(0, __LINE__, ermes, __PRETTY_FUNCTION__, __FILE__, err);
        throw err;
    }
    data[size] = stackelem;
    size++;
    return 0;
}

template <typename T>

T Stack<T>::pop()
{
    return(data[--size]);
}

#endif // STACK_H_INCLUDED
