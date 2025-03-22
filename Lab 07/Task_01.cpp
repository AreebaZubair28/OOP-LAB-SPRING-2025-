#include "iostream"
using namespace std;

class Account
{   int accountNumber;
    float balance;
    string accountHoldername;
    string accountType;
    float wm = 0, dm = 0;

public:
    Account(int num, float b, string name) : accountNumber(num), balance(b), accountHoldername(name) {}

    void setBalance(float b)      { balance -= b; }
    void setWM(float w)           { wm = w;       }

    int getAccountNumber()        { return accountNumber; }
    float getBalance()            { return balance; }
    float getWM()                 { return wm; }
    float getDM()                 { return dm; }
    string getAccountHolderName() { return accountHoldername; }
    string getAccountType()       { return accountType; }
    

    void deposit(float amount)
    {   balance += amount;
        cout << "Depositing..........." << amount << endl;
        cout << "Current Balance: " << balance << endl;
        dm = amount;
    }

    void withdraw(float amount)
    {   if (amount <= balance)
        {   balance -= amount;
            cout << "Withdrawing........." << amount << endl;
            cout << "Remaing Balance: " << balance << endl;
            wm = amount;
        }else
        {   cout << "Insufficient balance\n";
        }
    }

    float calculateInterest();

    void print()
    {   cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
        cout << "Withdrew Amount: " << wm << endl;
        cout << "Deposited Amount: " << dm << endl;
    }
};

class SavingAccount : public Account
{   float interestRate;
    float minimumBalance;

public:
    SavingAccount(int num, float b, string name, float rate, float minB) : Account(num, b, name), interestRate(rate), minimumBalance(minB) {}

    float calculateInterest()
    {   return (getBalance() * interestRate ) / 100.0;
    }

    void withdraw(float amount)
    {   if(amount <= getBalance())
        {   if((getBalance() - amount) >= minimumBalance)
            {   setBalance(amount);
                cout << "Withdrawing amount of " << amount << endl;
                cout << "Remaing Balance: " << getBalance() << endl;
                setWM(amount);
            }else{
                cout<<"Minimum balance exceeded\n";
            }
        }
        else
        {   cout << "Insufficient balance\n";
        }
    }

    void print()
    {   cout<<"-----------------------------------------------------"<<endl;
        cout << "Saving Account Statement for " << getAccountHolderName() << endl;
        Account ::print();
        cout<<"Interest Calculated: "<<calculateInterest()<<endl;
        cout<<"Interst Rate: "<<interestRate<<endl;
        cout<<"Minimum Balance: "<<minimumBalance<<endl;
        cout<<"-----------------------------------------------------\n"<<endl;
    }
};

class CheckingAccount : public Account{
    double overdraftLimit;

public:
    CheckingAccount(int num, float b, string name, double limit) : Account(num, b, name), overdraftLimit(limit) {}

    void withdraw(float amount)
    {   if (amount <= (getBalance()+overdraftLimit))
        {   setBalance(amount);
            cout << "Withdrawing amount of " << amount << endl;
            cout << "Remaing Balance: " << getBalance() << endl;
            setWM(amount);
        }else
        {   cout << "Overdraft limit exceeded!\n";
        }
    }

    void print()
    {   cout<<"-----------------------------------------------------"<<endl;
        cout << "Checking Account Statement for " << getAccountHolderName() << endl;
        Account ::print();
        cout << "Overdraft limit: Rs. " << overdraftLimit << endl;
        cout<<"-----------------------------------------------------\n"<<endl;
    }
};

class FixedDepositAccount : public Account{
    int maturityDate;
    float fixedInterestRate;

public:
    FixedDepositAccount(int num, float b, string name, int date, float rate) : Account(num, b, name), maturityDate(date), fixedInterestRate(rate) {}

    float calculateInterest()
    {   return (getBalance() * fixedInterestRate ) / 100.0;
    }

    void withdraw(float amount)
    {   int CurrentYear;
        cout<<"Current Year: ";    cin>>CurrentYear;

        if (maturityDate <= CurrentYear)
        {   if (amount <= getBalance())
            {   setBalance(amount);
                cout << "Withdrawing........." << amount << endl;
                cout << "Remaing Balance: " << getBalance() << endl;
                setWM(amount);
            }else{
                cout << "Insufficient balance\n";
            }
        }else{
            cout << "Amount can't be withdrew before maturity date\n";
        }
    }

    void print()
    {   cout<<"-----------------------------------------------------"<<endl;
        cout << "Fix Deposit Account Statement for " << getAccountHolderName() << endl;
        Account ::print();
        cout<<"Interest Calculated: "<<calculateInterest()<<endl;
        cout<<"Fix Interst Rate: "<<fixedInterestRate<<endl;
        cout << "Maturity Year:" <<maturityDate<< endl;
        cout<<"-----------------------------------------------------\n"<<endl;
    }
};

int main()
{
    SavingAccount sa(1001,1000.000,"Areeba",.05,100);
    CheckingAccount ca(1002,1500.000,"Aqsa",500.000);
    FixedDepositAccount fa(1003,2000.000,"Fatima",2025,0.75);

    sa.withdraw(500.00);
    sa.print();

    ca.withdraw(2000.00);
    ca.print();

    fa.withdraw(2000);
    fa.print();
}
