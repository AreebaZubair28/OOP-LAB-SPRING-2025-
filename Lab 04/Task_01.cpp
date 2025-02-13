#include "iostream"
using namespace std;

class Book{
   string title;
   float price;
   int *stock = new int;

public:
   Book()
   {   title = "Unknown";
       price = 0.0;
       *stock = 30;
   }

   void updateBookDetails()
   {   cout<<"Name: ";     cin>>title;
       cout<<"Price: ";    cin>>price;
       cout<<"Stock: ";    cin>>*stock;
       if(*stock < 5)
       {  cout<<"Warning! Low Stock\n";
       }
   }

   void Purchase(int s)
   {  if(s<*stock)
      {*stock -= s;
      cout<<s<<" books has been purchased\n";
      }else{
        if(*stock == 0)
        {  cout<<"No Stock is available\n";
        }else{
           cout<<"Not enough stock, so "<<*stock<<" books are purchased\n";
           *stock = 0;
        }
      }
      if(*stock < 5)
      { cout<<"Warning! Low Stock\nstock: "<<*stock<<endl;
      }else{
        cout<<"Current Stock: "<<*stock<<endl<<endl;
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
{  Book b;
   b.Display();
   cout<<endl;

   cout<<"Updating Book Details..................\n";
   b.updateBookDetails();
   cout<<"Updated Successfully\n";
   cout<<endl;

   cout<<"Purchasing Books..................\n";
   b.Purchase(12);
   cout<<endl;

   cout<<"Purchasing Books..................\n";
   b.Purchase(20);
   cout<<endl;

   cout<<"Purchasing Books..................\n";
   b.Purchase(2);
   cout<<endl;

   b.Display();
}
