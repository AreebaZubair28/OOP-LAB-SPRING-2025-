#include "iostream"
#include "exception"
#include "cmath"
#include <type_traits>
using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - Input must be non-negative!\n";
    }
};
    
class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - Non-numeric type detected!\n";
    }
};

// Template only enabled for arithmetic types
template <typename T>
typename enable_if<is_arithmetic<T>::value, double>::type
safeSqrt(T num) {
    if (num < 0) {
        throw NegativeNumberException();
    }
    return std::sqrt(static_cast<double>(num));
}

// Overload for non-numeric types to throw immediately
template <typename T>
typename enable_if<!is_arithmetic<T>::value, double>::type
safeSqrt(T) {
    throw InvalidTypeException();
}

int main() {
    try {
        cout << "sqrt(9): " << safeSqrt(9) << endl << endl;
        safeSqrt(-4); 
    } catch (const NegativeNumberException& e) {
        cout << "sqrt(-4): " <<  e.what() << endl;
    }

    try {
        safeSqrt("hello");
    } catch (const InvalidTypeException& e) {
        cout << "sqrt(\"hello\"): "  << e.what() << endl;
    }

return 0;
}
