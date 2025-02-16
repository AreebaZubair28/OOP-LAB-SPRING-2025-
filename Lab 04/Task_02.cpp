#include "iostream"
using namespace std;

class Book{
    string title;
    float price;
    int *stock = new int;
 
 public:
    Book(string t, float p, int s)
    {   title = t;
        price = p;
        *stock = s;
    }
 
    void ApplyDiscount(int p)
    {  float TotalPrice; 
       if(p>5 && p<10)
       {  TotalPrice = (price*p)-((price*p)*0.05);
       }
       else if(p>10)
       {  TotalPrice = (price*p)-((price*p)*0.1);
       }else{
          TotalPrice = price*p;
       }

       cout<<"Total Price: "<<TotalPrice<<endl;
    }

    bool Purchase(int s)
    {   if(*stock<5)
        {   StockMechanism();
            return 0;
        }
        if(s>*stock)
        {  cout<<"We are only available with "<<*stock<<" books.\nSo purchasing "<<s<<" is not possible.\n";
           return false;
        }else{
         *stock -= s;
          cout<<s<<" books has been purchased\n";
          return true;
        }
    }

    void StockMechanism()
    {  if(*stock < 5)
        { cout<<"Warning! Low Stock\nstock: "<<*stock<<endl;
        }else{
          cout<<"Current Stock: "<<*stock<<endl<<endl;
        }
    }

    void updateBookDetails()
    {  cout<<"Price: ";    cin>>price;
       cout<<"Stock: ";    cin>>*stock;
       if(*stock < 5)
       {  cout<<"Warning! Low Stock\n";
       }
    }
 
    void Display()
    {   cout<<"------Book Details------\n";
        cout<<"Name: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock: "<<*stock<<endl;
    }
 };

 int main()
{  bool num;

   Book b("Rock",1000,30);
   b.Display();
   cout<<endl;

   cout<<"Updating Book Details..................\n";
   b.updateBookDetails();
   cout<<"Updated Successfully\n";
   cout<<endl;

   cout<<"Purchasing Books..................\n";
   num =  b.Purchase(12);
   if(num)
   {  b.ApplyDiscount(12);
   }else{
    b.ApplyDiscount(0);
    b.StockMechanism();
   }

   cout<<endl;

   cout<<"Purchasing Books..................\n";
   num = b.Purchase(20);
   if(num)
   {  b.ApplyDiscount(20);
   }else{
    b.ApplyDiscount(0);
    b.StockMechanism();
   }
   cout<<endl;

   cout<<"Purchasing Books..................\n";
   num = b.Purchase(6);
   if(num)
   {  b.ApplyDiscount(6);
   }else{
    b.ApplyDiscount(0);
    b.StockMechanism();
   }
   cout<<endl;

   b.Display();
}
