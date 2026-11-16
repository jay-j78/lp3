#include <iostream>
using namespace std;

// Function to find Fibonacci number using Recursion
int fibonacciRecursive(int n) {

    // Base condition:
    // If n is 0 or 1, return n itself
    if (n <= 1)
        return n;

    // Recursive call:
    // Add the previous two Fibonacci numbers
    return fibonacciRecursive(n - 1) +
           fibonacciRecursive(n - 2);
}

// Function to print Fibonacci series using Iteration (Loop)
void fibonacciIterative(int n) {

    // Initialize the first two Fibonacci numbers
    int a = 0, b = 1, c;

    cout << "Fibonacci Series: ";

    // Repeat the loop for n terms
    for (int i = 0; i < n; i++) {

        // Print the current Fibonacci number
        cout << a << " ";

        // Calculate the next Fibonacci number
        c = a + b;

        // Update the values for the next iteration
        a = b;
        b = c;
    }

    cout << endl;
}

int main() {

    int n;

    // Get the number of terms from the user
    cout << "Enter number of terms: ";
    cin >> n;

    // Call the iterative function
    fibonacciIterative(n);

    // Print Fibonacci series using recursion
    cout << "\nRecursive Fibonacci Series: ";

    // Call recursive function for each term
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }

    return 0;
}


/*Enter number of terms: 7

Fibonacci Series: 0 1 1 2 3 5 8

Recursive Fibonacci Series: 0 1 1 2 3 5 8*/