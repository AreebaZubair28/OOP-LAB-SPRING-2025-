#include "iostream"
using namespace std;

class Account{
    int accountNum;
    float balance;

public:
    Account(int num, float b) : accountNum(num), balance(b) {}

    void display()
    {
        cout<<"Account Number: "<<accountNum<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

class SavingAccount : public Account{
    float interestRate;

public:
    SavingAccount(int num, float b, float i) : Account(num,b) , interestRate(i) {}

    void display()
    {
        Account :: display();
        cout<<"Interest Rate: "<<interestRate<<endl;
    }
};

class CheckingAccount : public Account{
    float overDraftLimit;

public:
    CheckingAccount(int num, float b, float i) : Account(num,b) , overDraftLimit(i) {}

    void display()
    {
        Account :: display();
        cout<<"Over Draft Limit: "<<overDraftLimit<<endl;
    }
};

int main()
{  cout<<"Details of Saving Account\n";
   SavingAccount s(1020,1000,10);
   s.display();

   cout<<"\nDetails of Checking Account\n";
   CheckingAccount c(2030,500,50);
   c.display();
}
