//
// ========================================
// HW4: Implement a Singly List Class
// ========================================
// 
// In this assignment, we will implement 
// a singly linked list class based on 
// a node class. 
// 
// The Node class has been defined to you. 
// Do not modify it. 
// 
// The List class has been partly defined 
// for you. It has one private variable 
// "head" and several public functions. 
// The constructor and Print function have been 
// defined for you (do not modify them), and 
// your task is to implement other functions. 
// 
// You can add new member functions to the 
// List class but not new member variables. 
// In addition, you cannot use any existing 
// list-related library or function. 
// 
// 
#include <iostream>
using namespace std;

// The Node class has been defined for you. 
// Do not modify it. 
class Node {
private:
	int SID;
	float GPA;
	Node* p_next;  // pointer-attribute stores address of next node-obj in list
public:
	void Set_SID(int x);
	void Set_GPA(float y);
	int Get_SID();
	float Get_GPA();
	void Set_Pnext(Node* p);
	Node* Get_Pnext();
	Node();
};
void Node::Set_SID(int x) {
	SID = x;
}
void Node::Set_GPA(float y) {
	GPA = y;
}
int Node::Get_SID() {
	return SID;
}
float Node::Get_GPA() {
	return GPA;
}
void Node::Set_Pnext(Node* p) {
	p_next = p;
}
Node* Node::Get_Pnext() {
	return p_next;
}
Node::Node() {
	SID = -1;
	GPA = -1;
	p_next = NULL;
}


// The List class has been partly defined for you. 
// Complete its undefined member functions. 
class List {
private:
	Node* head;   // pointer-attribute that is the address of the head-node-obj
public:
	// List function is defined for you.
	List();

	// Print function is defined for you.
	void PrtSID();

	// Create function creates a singly linked 
	// list based on our inputs and assigns its 
	// head node's address to the "head" pointer. 
	// 
	// To be specific, when we run Create(), 
	// the program should wait for us to input 
	// the SID and GPA of an arbitrary number 
	// of students. After Create() is done,  
	// the linked list should have been created
	// and accessible through "head". 
	// 
	// The format of input should be as follows: 
	// 
	// sid_1 gpa_1 sid_2 gpa_2 sid_3 gpa_3 ...... 
	// 
	// Here, sid_i and gpa_i are SID and GPA of 
	// the i_th input student. A new node is always 
	// added to the head of the list. 
	// 
	// Note that this hw does not require you to 
	// check duplication of the input/inserted SID's 
	// for simplicity. But we should always assume 
	// SID is unique for each student.
	// 
	// Finally, the process should terminate when 
	// an invalid input is given. Note that it is 
	// assumed we always input a pair of valid 
	// sid and gpa for a new student, so there is 
	// no need to deal with the case of a valid sid 
	// followed by an invalid gpa. 
	// 
	// If you are still confused about this function, 
	// check how it is used in the main program. 
	void Create();

	// Lsize function returns the number 
	// of nodes in the list. Return 0 if 
	// the list is empty. 
	int Lsize();

	// Find function returns address of 
	// the node in the list whose SID = key. 
	// Return NULL if no match is found. 
	Node* Find(int key);

	// Insert function inserts a new node 
	// (whose address is stored at "p") 
	// as the idx_th node in the list. 
	// Return 1 if insertion is successful 
	// and return -1 if idx is out of range.
	// A valid range is [1, Lsize+1], 
	// where "1" means adding to head 
	// and "Lsize+1" means adding to tail. 
	int Insert(Node* p, int idx);

	// Remove function removes the idx_th 
	// node from the list. Return 1 if 
	// removal is successful and -1 if 
	// idx is out of range.
	// A valid range is [1, Lsize], 
	// where "1" means removing head 
	// and "Lsize" means removing tail. 
	int Remove(int idx);

	// Reverse function reserves the list. 
	// For example, if the current list has 
	// three nodes A->B->C, after running 
	// Reverse the order should be C->B->A. 
	// As another example, if we call the 
	// print function and get 246, after 
	// running Reverse we should get 642. 
	void Reverse();

	// Clear function removes all nodes from 
	// the list (so it becomes an empty list). 
	void Clear();
};

void List::Create() {
	int new_sid;  // store cur-student-id
	float new_gpa;  // store cur-student-gpa
	// while user is entering input about cur-student, until they enter null
	while (cin >> new_sid >> new_gpa) {
		Node* new_node = new Node;  // pointer for node dynamic memeory allocated
		new_node->Set_SID(new_sid);  // access methods of object using pointer using ->
		new_node->Set_GPA(new_gpa);

		new_node->Set_Pnext(head); // set next-node of cur-node equal to head to insert this node at head. 
		head = new_node;  // set new head as current-node
	}
}

int List::Lsize() {
	int total_nodes;   // check if head is initalized?
	if (head != NULL) {  
		total_nodes = 1;
	} else {  // if there is no head size is 0
		return 0;
	}

	Node* cur_node = head;  // pointer init to head-node-address
	// while cur-node-pointer next-node-address is not null meaning it exists, meaning it is not tail
	while (cur_node->Get_Pnext() != NULL) {
		cur_node = cur_node->Get_Pnext();  // set cur-node-pointer to its next-node-address
		total_nodes += 1;     // increment node we just visited
	}

	return total_nodes;
}

Node* List::Find(int key) {
	Node* cur_node = head;  // pointer init to head-node-address
	// while cur-node-pointer next-node-address is not null
	while (cur_node->Get_Pnext() != NULL) {
		if (cur_node->Get_SID() == key) {  // if cur-node-address-pointer-id is key return its address
			return cur_node;
		}
		cur_node = cur_node->Get_Pnext();  // set cur-node-pointer to address of its next-node
	}
	return NULL;  // if id is not found in nodes
}

int List::Insert(Node* p, int idx) {
	if (idx < 1 || idx > Lsize() + 1) {
        return -1;  // Invalid index
    }

    if (idx == 1) { // index is 1 insert at the head 
        
        p->Set_Pnext(head);  // pointer-node set its next-node-address to head-address
        head = p;
    } else {
        // Insert at a specific position
        Node* temp = head;  // init temp-node-pointer to head
		// iterate from head to just before the given index
        for (int i = 1; i < idx - 1; i++) {
            temp = temp->Get_Pnext();  // set temp-node-pointer to its next-node-pointer
        }

        p->Set_Pnext(temp->Get_Pnext());  // set given-pointer-p next node to address of temp-pointer's next-node
        temp->Set_Pnext(p);  // set temp-pointer next node to pointer-p
    }

    return 1; 
}

int List::Remove(int idx) {
    if (idx < 1 || idx > Lsize()) {
        return -1;  // Invalid index
    }

    if (idx == 1) {
        // Remove the head
        Node* temp = head;  // set temp-pointer to head-pointer
        head = head->Get_Pnext();  // set new head to next of head
        delete temp;   // remove dynamic memeory that was allocated.
    } else {
        // Remove a specific position
        Node* temp = head;  // set temp-pointer to head-pointer
		// iterate from head to just before deletion-index
        for (int i = 1; i < idx - 1; i++) {
            temp = temp->Get_Pnext();  // move temp to its next-node
        }

        Node* to_remove = temp->Get_Pnext();  // node that needs to removed is the next of temp, because we stopped just before it
        temp->Set_Pnext(to_remove->Get_Pnext());  // set next of temp to next of remove (skipping it), 
        delete to_remove;    // remove dynamic memeory that was allocated.
    }

    return 1;  // Removal successful
}

void List::Reverse() {
    Node* prev = NULL;   // prev-pointer
    Node* current = head;  // init cur-pointer to head
    Node* next = NULL;     // next-pointer is null

	// while cur-head is not reversed
    while (current != NULL) {
        next = current->Get_Pnext();  // next = cur.next
        current->Set_Pnext(prev);  // cur.set_next(prev)
        prev = current;  // prev-pointer is now cur
        current = next;  // cur-pointer is now next
    }

    head = prev;  // set head to the tail
} 

void List::Clear() {
	// while is not null
    while (head != NULL) {
        Node* temp = head;  // get head and store in temp-pointer
        head = head->Get_Pnext();  // set head to its next node, and delete the old head
        delete temp;
    }
}

// The constructor has been defined for you.
List::List() {
	head = NULL;
}
// The print function has been defined for you.
void List::PrtSID() {
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->Get_SID();
		temp = temp->Get_Pnext();
	}
}

int main()
{
	int mode, key, sid, idx;
	float gpa;

	// The first five inputs are for testing. 
	// "mode" determines which function to test. 
	// "key" is used to evaluate Find().
	// "sid" and "gpa" are used to evaluate Insert().
	// "idx" is used to evaluate Insert() and Remove().
	// 
	// After these inputs, the rest inputs are used 
	// to create the initial singly linked list. 
	cin >> mode >> key >> sid >> gpa >> idx; 

	// declare a singly linked list named "x"
	List x; 

	// input data to x.
	// After this, a list should be created 
	// and stored at address "head".
	x.Create();

	// Mode 0: test Create()
	if (mode == 0) {
		x.PrtSID();
	}
	// Mode 1: test Lsize()
	else if (mode == 1) {
		cout << x.Lsize();
	}
	// Mode 2: test Find()
	else if (mode == 2) {
		Node* temp = x.Find(key);
		if (temp == NULL) {
			cout << -1;
		}
		else {
			cout << temp->Get_GPA();
		}
	}
	// Mode 3: test Insert()
	else if (mode == 3) {
		Node* temp = new Node; 
		temp->Set_SID(key);
		temp->Set_GPA(3.5);
		x.Insert(temp, idx);
		x.PrtSID();
	}
	// Mode 4: test Remove()
	else if (mode == 4) {
		x.Remove(idx);
		x.PrtSID();
	}
	// Mode 5: test Reverse()
	else if (mode == 5) {
		x.Reverse();
		x.PrtSID();
	}
	// Mode 6: test Clear()
	else if (mode == 6) {
		x.Clear();
		cout << x.Lsize();
	}

	return 0;
}


