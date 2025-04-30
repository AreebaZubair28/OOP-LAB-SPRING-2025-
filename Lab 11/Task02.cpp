#include "iostream"
#include "exception"
using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept {
        return "Stack is Full!\n";
    }
};
    
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept {
        return "Stack is empty!\n";
    }
};

template <typename T>
class Stack {
    T capacity;

public:
    Stack(T c) : capacity(c) {}

    void puch() {
        try {
            if(capacity > 100) {
                throw StackOverflowException();
            }
            cout<<"Puch - Capacity of Stack: "<< capacity << endl;
        } catch(StackOverflowException& e) {
            cout << "Pushing to a full Stack: StackOverflowException - " << e.what() ;
        }  
    }

    void pop() {
        try {
            if(capacity <= 0) {
                throw StackUnderflowException();
            }
            cout<<"Pop - Capacity of Stack: "<< capacity << endl;
        } catch(StackUnderflowException& e) {
            cout << "Popping from an empty Stack: StackUnderflowException - " << e.what() ;
        }
    }
};

int main() {
    Stack<int> s1(12);
    cout<<endl;
    s1.puch(); s1.pop();
    
    Stack<int> s2(120);
    cout<<endl;
    s2.puch();

    Stack<int> s3(0);
    cout<<endl;
    s3.pop();
    cout<<endl;

return 0;
}
