#include <iostream>
using namespace std;

int main() {  

    int x = 5;
    int *ptr = &x;
    
    (*ptr)++;
    cout << x;  // 5
    cout << *ptr; // 6

    cout << x;
    

}



// #include <iostream>
// using namespace std;

// int main() {  

//     // declare function
//     void add(int a);
//     void add2(int &a);

//     int x = 5;
//     add(x);   // value
//     cout << x << "\n";  

//     add2(x);  // reference
//     cout << x << "\n";  

// }

// // pass by value
// void add(int a) {
//     a++;
// }
// // pass by reference/address/location using & next to argument
// void add2(int &a) {
//     a++;
// }