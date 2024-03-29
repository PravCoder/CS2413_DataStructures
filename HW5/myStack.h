#ifndef MY_STACK_H
#define MY_STACK_H

template <class Type>
class myStack {
public:
    myStack();
    myStack(const myStack<Type> &);
    const myStack<Type> &operator=(const myStack<Type> &);
    ~myStack();

    void push(const Type &);
    void pop();
    Type top() const;
    bool isEmpty() const;

private:
    struct node {
        Type item;
        node *next;
    };
    node *topOfMyStack;
};

template <class Type>
myStack<Type>::myStack() {
    topOfMyStack = nullptr;
}

template <class Type>
myStack<Type>::myStack(const myStack<Type> &copy) {
    topOfMyStack = nullptr;
    node *temp = copy.topOfMyStack;
    node *prev = nullptr;

    while (temp != nullptr) {
        node *newNode = new node;
        newNode->item = temp->item;
        newNode->next = nullptr;

        if (topOfMyStack == nullptr) {
            topOfMyStack = newNode;
        } else {
            prev->next = newNode;
        }

        prev = newNode;
        temp = temp->next;
    }
}

template <class Type>
const myStack<Type> &myStack<Type>::operator=(const myStack<Type> &rhs) {
    if (this != &rhs) {
        // Clear current stack
        while (!isEmpty()) {
            pop();
        }

        // Copy contents of rhs stack
        node *temp = rhs.topOfMyStack;
        node *prev = nullptr;

        while (temp != nullptr) {
            node *newNode = new node;
            newNode->item = temp->item;
            newNode->next = nullptr;

            if (topOfMyStack == nullptr) {
                topOfMyStack = newNode;
            } else {
                prev->next = newNode;
            }

            prev = newNode;
            temp = temp->next;
        }
    }

    return *this;
}

template <class Type>
myStack<Type>::~myStack() {
    while (!isEmpty()) {
        pop();
    }
}

template <class Type>
void myStack<Type>::push(const Type &insert) {
    node *newNode = new node;
    newNode->item = insert;
    newNode->next = topOfMyStack;
    topOfMyStack = newNode;
}

template <class Type>
void myStack<Type>::pop() {
    if (!isEmpty()) {
        node *temp = topOfMyStack;
        topOfMyStack = topOfMyStack->next;
        delete temp;
    }
}

template <class Type>
Type myStack<Type>::top() const {
    if (!isEmpty()) {
        return topOfMyStack->item;
    }
    throw "Stack is empty";
}

template <class Type>
bool myStack<Type>::isEmpty() const {
    return topOfMyStack == nullptr;
}

#endif // MY_STACK_H
