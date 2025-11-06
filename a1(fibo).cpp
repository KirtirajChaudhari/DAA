//-------------------------------------------------------------
//Fibonacci Sequence using Recursive and Non-Recursive Method:-
//-------------------------------------------------------------

#include <iostream>
using namespace std;

int fib(int n) // recursive function
{
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;

    // Iterative Method
    cout<<"\nIterative Fibonacci Series:\n";
    int a = 0, b = 1, c;
    for(int i = 0; i < n; i++)
    {
        cout<<a<<" ";
        c = a + b;
        a = b;
        b = c;
    }

    // Recursive Method
    cout<<"\n\nRecursive Fibonacci Series:\n";
    for(int i = 0; i < n; i++)
    {
        cout<<fib(i)<<" ";
    }

    return 0;
}
