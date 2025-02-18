#include "iostream"
#include <string>
using namespace std;

class Product{
public:
    int id; 
    string name;
    float price;
    string category;

   Product(int i, string n, float p, string c) : id(i), name(n), price(p), category(c) {}

   void display()
   {
    cout<<"Name: "<<name<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"Category: "<<category<<endl;
    cout<<"------------------"<<endl;
   }
};

class Inventory{
   Product *p[10];
   int count = 0;

public:
  void AddProduct(Product* p1)
  {    p[count++] = p1;
  }

  void CheapestProducts()
  { for(int i=0; i<count; i++)
    {  for(int j=0; j<count; j++)
       {  if(i>j)
          { Product *temp = p[i];
            p[i] = p[j];
            p[j] = temp;
          }
       }
    }

    for(int i=0; i<count; i++)
    {
        p[i]->display();
    }
  }

  void search()
  { string n;
    int found = 0;
    cout<<"Enter name of the product: ";
    cin.ignore(); 
    getline(cin,n);

    for(int i=0; i<count; i++)
    {  if(n == p[i]->name)
       { found = 1;
         p[i]->display();
       }
    }

    if(!found) 
    { cout<<"Product not found\n";
    }else{
        cout<<"Searched completed successfully\n";
    }
  }
};

int main()
{  Inventory i;
    Product* p;
    int id;  string name;  float price; string category;
    int choise;
   
   do{
    cout<<"1-Add Product\n2-Search Product\n3-Display Cheapest Products\n4-Exit\nEnter your choise: ";
    cin>>choise;

    switch (choise)
    {   case 01:
        cout<<"Category (Electronics/Clothing/Groceries): ";
        cin>>category;
        cout<<"Name: ";
        cin.ignore(); 
        getline(cin,name);
        cout<<"Id: ";
        cin>>id;
        cout<<"Price: ";
        cin>>price;
        p = new Product(id, name, price,category);
        i.AddProduct(p);
        break;
       
        case 02:
        i.search();
        break;

        case 03:
        i.CheapestProducts();
        break;

        case 04:
        cout<<"Thanks\n";
        break;
    
        default:
        cout<<"Invalid choise\n";
        break;
    }
   }while(choise !=4);
}
