#include "iostream"
#include "exception"
using namespace std;

class InvalidValueException : public exception {
public:
   const char* what() const noexcept {
    return "\nError: InvalidValueException - Age can't be negative or exceed 120";
   }
};

void validateAge(int age) {
    try {
        if(age < 0 || age > 120) {
            throw InvalidValueException();
        }
        cout << age <<" age is valid\n\n";
    } catch (InvalidValueException& e) {
        cout << e.what() << endl << endl;
    }
}

int main() {
    int age;
    cout << "Enter age: ";   cin>>age;
    validateAge(age);

return 0;
}
