//
// ========================================
// Assignment 1: C++ Programming 
// ========================================
// 
// In this assignment, we will implement 
// a Student class and a University class. 
// 
// The Student class has two private member  
// variables and five member functions (not 
// counting the constructor). Their designs 
// are explained in the template below.
// 
// The University class has one private member 
// variable and four member functions. Their 
// designs are explained in the template below.
// 
// In the template, you will see two types of 
// sections: "Task" and "Test". A "Task" section 
// is where you need to implement something, 
// and a "Test" section is testing your implementation 
// (you don't need to do anything in this section). 
// 
// For all print functions, only print the value 
// and do not add any additional character 
// such as space or change line. For example, 
// if you are asked to print the value of x, 
// write "cout << x;" instead of "cout << x << endl;"
//
//



// ======= Task 1 =======
// Complete the header files
// ......
// ......
// ......
// === End of Task 1 ====


// ======= Task 2 =======
// Design and implement all member functions of the 
// following two classes: Student and University.
// All member functions must be implemented outside 
// the class definitions. 
// 

#include <iostream>
using namespace std;

// Student class implementation
class Student {
public:
    void set_SID(int x);  // It assigns x to SID.
    void prt_SID();       // It prints SID.
    void set_GPA(float y); // It assigns y to GPA.
    void prt_GPA();       // It prints GPA.
    void reset();         // It resets SID and GPA to -1.
    float get_GPA();      // It returns GPA.
    Student();            // Constructor. It initializes both SID and GPA to -1.

private:
    int SID;   // It holds a student's ID.
    float GPA; // It holds a student's GPA.
};

// University class implementation
class University {
public:
    void set_Stu(Student x[]); // It assigns x to Sooner.
    float GPA_Mean();          // It prints the mean GPA of the five students held by Sooner[5].
    float GPA_Max();           // It prints the max GPA of these five students.
    float GPA_Min();           // It prints the min GPA of these five students.
    University();              // Constructor. Initialize all student SID and GPA to -1.

private:
    Student Sooner[5]; // It holds the records of five students.
};

// Student class member function implementations

// Set the student ID given an integer
void Student::set_SID(int x) {
    SID = x;
}
// Print the student ID attribute of student-obj
void Student::prt_SID() {
    cout << SID;
}
// set GPA-attribute of student-obj
void Student::set_GPA(float y) {
    GPA = y;
}
// print GPA attribute of student-obj
void Student::prt_GPA() {
    cout << GPA;
}
// reset student-id and gpa attributes to negative one
void Student::reset() {
    SID = -1;
    GPA = -1;
}
// return the gpa attribute of student-obj
float Student::get_GPA() {
    return GPA;
}
// Student-class constructor, same as reset()-method
Student::Student() {
    SID = -1;
    GPA = -1;
}

// University class member function implementations
// given an array of student-objs assigns each element to sooner-attribute-arr
void University::set_Stu(Student x[]) {
    for (int i = 0; i < 5; i++) {
        Sooner[i] = x[i];
    }
}

float University::GPA_Mean() {
    float total_sum = 0.0;  // stores total sum
    for (int i = 0; i < 5; i++) {      // iterate through number of students
        float cur_gpa = Sooner[i].get_GPA(); // get teh gpa of current-student-obj in sonner-array
        total_sum += cur_gpa;  // add gpa to total sum
    }
    total_sum /= 5;  // compute average with nummber of students
    cout << total_sum;
    return total_sum;
}

float University::GPA_Max() {
    float largest = -1;  // initialze largest gpa to -1 
    for (int i = 0; i < 5; i++) {       // iterate number of students
        float cur_gpa = Sooner[i].get_GPA();    // get the gpa of current-student-obj in sonner-array
        if (cur_gpa > largest) {  // if gpa of cur-student-obj is greater than cur-largest gpa, replace it
            largest = cur_gpa;
        }
    }
    cout << largest;
    return largest;
}

float University::GPA_Min() {
    float smallest = 100; // initialze smallest gpa to to a large number
    for (int i = 0; i < 5; i++) {       // iterate number of students
        float cur_gpa = Sooner[i].get_GPA();  // get the gpa of current-student-obj in sonner-array
        if (cur_gpa < smallest) {   // if gpa of cur-student-obj is less than than cur-largest gpa, replace it
            smallest = cur_gpa;
        }
    }
    cout << smallest;
    return smallest;
}

University::University() {
    for (int i = 0; i < 5; i++) {
        Sooner[i].reset();
    }
}

int main() {
    Student x[5];
    University OU;

    // ======= Test 1 =======
	// This tests your constructor function, 
	// print function and header files. 
    for (int i = 0; i < 5; i++) {
		x[i].prt_SID(); cout << ' ';
		x[i].prt_GPA(); cout << endl;
	}
    // === End of Test 1 ====

    // ======= Task 3 =======
	// Write a program that takes the SID 
	// and GPA of five students as input 
	// and assigns them to x[5]. 
	// 
	// Formt of the inputs should be (with space)
	// SID1 GPA1 SID2 GPA2 SID3 GPA3 SID4 GPA4 SID5 GPA5
	// ......
	// ......
	// ......
    int sid;
    float gpa[5];
    for (int i = 0; i < 5; i++) {
        cin >> sid >> gpa[i];
        x[i].set_SID(sid);
        x[i].set_GPA(gpa[i]);
    }
    // === End of Task 3 ====

    // ======= Test 2 =======
	// This tests your set function
    for (int i = 0; i < 5; i++) {
		x[i].prt_SID(); cout << ' ';
		x[i].prt_GPA(); cout << endl;
	}
    // === End of Test 2 ====

    // ======= Test 3 =======
	// This tests your University class. 
    OU.set_Stu(x);
	OU.GPA_Mean(); cout << ' ';
	OU.GPA_Max();  cout << ' ';
	OU.GPA_Min();  cout << endl;
    // === End of Test 3 ====

    // ======= Test 4 =======
    // This tests your reset function.
    for (int i = 0; i < 5; i++) {
		x[i].reset();
		x[i].prt_SID();	cout << ' ';
		x[i].prt_GPA();	cout << endl;
	}
    // === End of Test 4 ====

    return 0;
}