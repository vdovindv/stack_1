#include <iostream>
#include <cassert>

#define defval 2

using namespace std;

class Stack {

private:
    int* stackptr; //pointer on the first element of stack
    int capacity; //capacity of stack
    int size; //number of elements in stack
public:
    Stack(int a);// constructor
    Stack();//default constructor
    void push(int a);
    int pop();
    ~Stack();//destructor
};

Stack::Stack(int a)
{
   capacity = a;
   stackptr = new int[a];
   size = 0;
}

Stack::Stack(): capacity(defval)
{
        stackptr = new int[capacity];
        size = 0;
}

Stack::~Stack()
{
    delete []stackptr;
}

void Stack::push(int a)
{
    assert(size < capacity);
    stackptr[size++] = a;
}

int Stack::pop()
{
    assert(size > 0);
    return(stackptr[--size]);
}

int main()
{
    int i, a, n, b = 10;
    Stack test;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a;
        test.push(a);
    }
    for(i = 1; i <= n; i++)
    {
        cout<< "This element was on the top " << test.pop() << endl;
    }
    test.~Stack();
    return 0;
}

