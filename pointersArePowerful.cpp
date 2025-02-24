#include <iostream>
using namespace std;

int main() {
    // Part 1: Working with a single integer and pointer
    int a = 10;          // Declare and initialize an integer
    int* p = &a;         // Declare a pointer and assign address of 'a'
    
    // Print address and value
    cout << "Address stored in p: " << p << endl;
    cout << "Value of a using p: " << *p << endl;
    
    // Change value using pointer
    *p = 20;
    cout << "New value of a: " << a << endl;
    
    cout << "\n------------------------\n\n";
    
    // Part 2: Working with array and pointer arithmetic
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;      // Point to first element of array
    
    // Print address of each element
    cout << "Addresses of array elements:\n";
    for(int i = 0; i < 5; i++) {
        cout << "Address of element " << i << ": " << (ptr + i) << endl;
    }
    
    cout << "\nValues using pointer arithmetic:\n";
    // Traverse array using pointer increment
    for(int i = 0; i < 5; i++) {
        cout << "Value at element " << i << ": " << *ptr << endl;
        ptr++;           // Move to next element
    }
    
    return 0;
}