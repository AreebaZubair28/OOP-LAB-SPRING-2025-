# include"iostream"
using namespace std;

class Currency{
protected:
  float amount;
  string currencyCode;
  string currencySymbol;
  float exchaneRate; // Exchange rate to base currency (USD)

public:
  Currency(float a, string code, string symbol, float rate) : amount(a), currencyCode(code), currencySymbol(symbol), exchaneRate(rate) {}

  virtual float converToBase()
  { return amount / exchaneRate;  
  }

  void convertTo(Currency& targetCurrency)
  { float baseAmount = converToBase();
    float targetAmount = baseAmount * targetCurrency.exchaneRate;
    targetCurrency.amount = targetAmount;
  }

  virtual void displayCrrency()
  { cout<<currencySymbol<<" "<<amount<<" "<<currencyCode<<endl;
  }
};

class Rupee : public Currency{
public: 
    Rupee(float a, string code, string symbol, float rate) : Currency(a,code,symbol,rate) {}
};    

class Dollar : public Currency{
public: 
    Dollar(float a, string code, string symbol, float rate) : Currency(a,code,symbol,rate) {}
};

class Euro : public Currency{
public: 
    Euro(float a, string code, string symbol, float rate) : Currency(a,code,symbol,rate)  {}
};

int main()
{
    Rupee rupee(4000,"PKR","Rs",278.0);
    Euro euro(0.00,"EUR","€",0.91);
    Dollar dollar(0.00,"USD","$",1.0);

    cout << "Before conversion:" << endl;
    rupee.displayCrrency();
    euro.displayCrrency();
    dollar.displayCrrency();

    // Convert PKR to Euro using base currency USD
    rupee.convertTo(euro);
    rupee.convertTo(dollar);

    cout << "\nAfter conversion:" << endl;
    euro.displayCrrency();
    dollar.displayCrrency();
}
