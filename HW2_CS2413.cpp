#include <iostream>
using namespace std;

int main() {  
    int x;
    void Operator(int* ptr)
    void Operator_1(int* ptr);
    void Operator_2(int*& ptr)

    Operator_1(&x);
    Operator_2(&x);
}

void Operator(int* ptr) {
    cout << *ptr;
}

void Operator_1(int* ptr) {
    cout << *ptr;
}

void Operator_2(int*& ptr) {
    cout << *ptr;
}