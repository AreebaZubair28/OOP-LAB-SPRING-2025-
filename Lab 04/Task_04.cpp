#include "iostream"
using namespace std;

class Book{
    string title;
    float price;
    float discountPercentage;
    int *stock = new int;
 
 public:
    Book(string t, float price,float discountPercentage, int s)
    {   title = t;
        this->price = price;
        this->discountPercentage = discountPercentage;
        *stock = s;
    }
 
    void ApplyDiscount(int quantity)
    {  float TotalPrice = this->price * (1 - this->discountPercentage / 100.0);
       
       if(quantity>=10)
       {  TotalPrice *= 0.5;
       }
       
       cout<<"Total Price of "<<quantity<<" Book: "<<TotalPrice*quantity<<endl;
    }

    bool Purchase(int s)
    {   if(s>*stock)
        {   cout<<"Not Enough Stock Avalable\n";
            return false;
        }
        *stock -= s;
        cout<<s<<" books has been purchased\n";
        cout<<"Remaining Stock: "<<*stock<<endl;
        return true;
    }

    void updateBookDetails(float price, float discountPercentage, int s)
    {  this->price = price;
       this->discountPercentage = discountPercentage;
       *stock = s;
    }
 
    void Display()
    {   cout<<"------Book Details------\n";
        cout<<"Title: "<<title<<endl;
        cout<<"Base Price: "<<this->price<<endl;
        cout<<"Discount: "<<this->discountPercentage<<endl;
        cout<<"Stock: "<<*stock<<endl;
    }
 };

int main()
{  Book b("Rock Paper Scissor", 1000, 15, 15);
   cout<<"Purchasing Books..................\n";
   bool i = b.Purchase(8);
   if(i)
   {   b.ApplyDiscount(8);
   }
   cout<<endl;
   b.Display();
   cout<<endl;
 
   cout<<"Purchasing Books..................\n";
   i = b.Purchase(10);
   if(i)
   {   b.ApplyDiscount(10);
   }
   cout<<endl;
   b.Display();
   cout<<endl;
}
