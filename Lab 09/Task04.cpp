#include "iostream"
#include "string"
#include "cstring"
using namespace std;

class Paymentmethod{
public:
  virtual void processPayment(double amount) = 0;
};

class CreditCard : public Paymentmethod{
    string cardNum;

public:
   CreditCard(string n) : cardNum(n) {}

   void processPayment(double amount)
   { string num;
     cout<<"Enter Card Number: ";    cin>>num;

     if( cardNum == num )
     { cout<<"Done!\n";
     }else{
        cout<<"Wrong Card Number!\n";
     }
   }
};

class DigitalWallet : public Paymentmethod{
    double balance;

public:
   DigitalWallet(double b) : balance(b) {}

   void processPayment(double amount)
   {  if(amount > balance)
      { cout<<"Balance can't be deducted!\n";
      }else{
        balance -= amount;
        cout<<"Balance deducted to: "<<balance<<endl;
      }
   }
};

int main()
{
    CreditCard c("010203");
    c.processPayment(1500);
    c.processPayment(1500);

    DigitalWallet d(500);
    d.processPayment(600);
    d.processPayment(400);
}
