#include "iostream"
#include "exception"
using namespace std;

class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "InsufficientFundsException - Deficit: $";
    }
};

template <typename T>
class BankAccount {
    T balance;
public:
   BankAccount(T b) : balance(b) {}

   void withdraw(T amount) {
      try {
        if(amount > balance) {
            throw InsufficientFundsException();
        }else{
            balance -= amount;
            cout << "Amount: $" << amount << " has been withdrew successfully\n";
            cout << "Remainig balance: " << balance << endl;
        }
      } catch (const exception& e) {
        cout << "Balance: $" << balance << endl;
        cout << "Withdraw $" << amount << ": " << e.what() << amount - balance << endl;
      }
   }    
};

int main() {
    BankAccount<double> b1(500);
    b1.withdraw(300);

    cout << endl;

    BankAccount<double> b2(500);
    b2.withdraw(700);
}
