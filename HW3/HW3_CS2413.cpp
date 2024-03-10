//
// ========================================
// HW3: Implement a Vector Class
// ========================================
// 
// In this assignment, we will implement 
// a vector class based on array, pointer 
// and dynamic memory allocation. 
// 
// The class has two private member 
// variables and some member functions. 
// Their designs are explained below. 
// 
// You can add new member functions 
// but not new member variables. In 
// addition, you cannot use any existing 
// vector-related library or function. 
// 
// 


#include <iostream>
using namespace std;

// 
// ======= Task =======
// Design and implement all member 
// functions of the MyVector class. 
// 
class MyVector {

public:

	// The "vsize" function returns the size 
	// of the current vector.  
	int vsize();

	// The "empty" function returns 1 if the 
	// current vector has no element and 0 otherwise. 
	int empty();

	// The "at" function returns the idx_th element 
	// of the vector. It also returns -1 if "idx" 
	// is outside the range of the current vector.
	int at(int idx);

	// The "resize" function resizes the current 
	// vector into a vector of size n. Note there 
	// are two scenarios (in lecture slides) which 
	// may need to be addressed separately. 
	void resize(int n);

	// The "push_back" function adds a new element 
	// "x" to the end of the current vector. Note 
	// the vector size increases after addition. 
	void push_back(int x);

	// The "pop_back" function removes the last 
	// element from the current vector, but does 
	// nothing if the current vector is empty. 
	// Note the vector size decreases after pop. 
	void pop_back();

	// The "insert" function inserts a new element 
	// "x" as the idx_th element in the current vector.
	// It also does nothing if "idx" is outside the 
	// range of the current vector. 
	void insert(int idx, int x);

	// The "erase" function removes the idx_th element 
	// from the vector. It also does nothing if the 
	// current vector is empty or if "idx" is outside 
	// the range of the current vector. 
	void erase(int idx);

	// The constructor should initialize 
	// pointer "p" to NULL and "size" to 0. 
	MyVector();

private:

	int* p; // This pointer holds the vector (or,essentially, 
	// address of an array that holds the vector elements.)
	// Do remember to update it after some vector operations.

	int size; // This integer holds the size of the current 
	// vector. Do remember to update it after some 
	// vector operations. 
};

// MY CODE
MyVector::MyVector() {	// constructor
	p = NULL;
	size = 0;
}

int MyVector::vsize() {  // return the number of elements in vector. 
    return size; 
}

int MyVector::empty() {  // return 1-true if vector is empty, 0-false if it is not empty. 
	if (size == 0) {
		return 1;
	} else {
		return 0;
	}
}

int MyVector::at(int idx) {
	if (idx < 0 || idx >= size) {
		return -1;
	} else {
		return p[idx];
	}
}

void MyVector::resize(int n) {
	int* newP = new int[n];  // create new pointer with size of new-resize
	// if size of original arr is less than new-size
	if (size < n) {
		for (int i=0; i<size; i++) {
			newP[i] = p[i];
		}
		for (int j=size; j<n; j++) {
			newP[j] = 0;
		}
	} 

	// if size of orignal is greater than n
	if (size > n) {
		for (int i=0; i<n; i++) {
			newP[i] = p[i];
		}
	}

	size = n;   // update new size of array
	delete[] p;  // delete old pointer to prevent memory leak, array-pointer
	p = newP;  // update pointer-field of vector-obj with new-array-pointer
}

void MyVector::push_back(int x) {
	int* newP = new int[size+1];   // create new pointer for new array, with size 1 more
	for (int i=0; i<size; i++) {	// iterate from start to end of size of old-array
		newP[i] = p[i];				// set new pointer-cur-indx-element equals old-pointer-indx-elemebt
	}
	
	newP[size] = x;	// add new-element end of new-arrm the old-size is equal to the index of last element in new-arr
	size += 1;		// increment size of cur-arr because we added element

	delete[] p;  // delete old pointer to prevent memory leak
	p = newP;  // update pointer-field of vector-obj with new-array-pointer
}

void MyVector::pop_back() {
	if (size > 0) {  // if array is not empty
		int* newP = new int[size-1];	// create new pointer for new-arr with size 1 less than original
		for (int i=0; i<size-1; i++) {  // iterate from 0 to 1 less than original array, to leave out the last-element (deleting it)
			newP[i] = p[i];				// set new-pointer-indx = old-pointer-indx-element
		}

		size -= 1;
		delete[] p;  // delete old pointer to prevent memory leak
		p = newP;  // update pointer-field of vector-obj with new-array-pointer
	}
}

void MyVector::insert(int idx, int x) {
	if (idx >= 0 && idx < size) {
		int* newP = new int[size+1];  // create new-pointer-arr of 1 more size because we are adding element

		for (int i=0; i<size; i++) {  // copy all of the elements in old-arr to new-arr-pointer
			newP[i] = p[i];
		}

		newP[idx] = x;  // insert element into new-pointer-idx

		for (int j=idx; j<size; j++) {
			newP[j+1] = p[j];
		}

		size += 1;
		delete[] p;  // delete old pointer to prevent memory leak
		p = newP;  // update pointer-field of vector-obj with new-array-pointer
	}
}
void MyVector::erase(int idx) {
	// if the indx is valid
	if (idx >= 0 && idx < size && size > 0) {
		int* newP = new int[size-1];  // create new-pointer to new-array

		// iterate from start to 
		for (int i=0; i<idx; i++) {
			newP[i] = p[i];
		}
		for (int j=idx+1; j<size; j++) {
			newP[j-1] = p[j];
		}

		size--;
		delete[] p;
		p = newP;
	} 

	
}


// The main function has been completed for you. 
// It is used to test your implmentation. 
// You should not modify it (unless there is typo).
int main()
{
	MyVector x;

	int mode;
	int new_size, idx, data;
	int temp;

	cin >> mode; // This decides which function to test. 
	cin >> new_size >> idx >> data;

	// Mode 0: test push_back(), vsize() and at()
	if (mode == 0) {

		while (cin >> temp) {
			x.push_back(temp);
		}

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	// Mode 1: test resize()
	else if (mode == 1)
	{
		while (cin >> temp) {
			x.push_back(temp);
		}

		x.resize(new_size);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	// Mode 2: test pop_back()
	else if (mode == 2) {

		while (cin >> temp) {
			x.push_back(temp);
		}

		x.pop_back();

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	// Mode 3: test insert()
	else if (mode == 3) {

		while (cin >> temp) {
			x.push_back(temp);
		}

		x.insert(idx, data);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	// Mode 4: test erase()
	else if (mode == 4) {

		while (cin >> temp) {
			x.push_back(temp);
		}

		x.erase(idx);

		cout << x.vsize() << '\n';

		for (int i = 0; i < x.vsize(); i++) {
			cout << x.at(i) << '\n';
		}
	}
	else {
		cout << "Wrong Mode Input!";
	}

	return 0;
}
