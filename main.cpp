#include <iostream>
#include "stack.h"
#include "Megaerror.h"

using namespace std;

int main()
{
    try
    {
    int i, n, c;
    cout << "Please load a number of stack elements:";
    cin >> n;
    cout << endl;
    Stack<int> test(n);
    for(i = 0; i < n; i++)
    {
        cout << "Load an element:" ;
        cin >> c;
        test.push(c);
    }
    cout << "You've loaded all elements" << endl;
    Stack<int> test1(test);
    test.printstack();
    }
    catch(Megaerror err)
    {
        err.printMegaerror();
    }
    return 0;
}
