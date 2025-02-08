#include "iostream"
#include "cstring"
#include "string"
using namespace std;

class GroceryStore{

    string Item[100];
    float Price[100];

public:
    GroceryStore()
    {   Item[100];
        Price[100];
    }

    void AddItems(int &num)
    {   cout<<"Item: ";
        cin>>Item[num];
        cout<<"Price: ";
        cin>>Price[num];
        num++;
        cout<<"Items added successfully!\n\n";
    }

    void UpdatePrices(int num)
    {   string item;
        float price;
        cout<<"Enter item whose price you wanna update: ";
        cin>>item;
        
        int found = 0;
        for(int i=0; i<num; i++)
        {  if(Item[i] == item)
           {  found = 1;
              cout<<"Enter the price: ";
              cin>>price;  
              Price[i] = price;
           }
        }
  
        if(!found)
        {   cout<<"Item is not found\n\n";
        }else{
            cout<<"Item updated successfully\n\n";
        }
    }

    void ViewInventory(int num)
    {  cout<<"\n--------------------------------------\n";
       for(int i=0; i<num; i++)
       {  cout<<"Item "<<i+1<<endl;
          cout<<"Item: "<<Item[i]<<endl;
          cout<<"Price: "<<Price[i]<<endl;
       }
       cout<<"\n--------------------------------------\n";
    }

    void GenerateReceipt(int numOfItems)
    {   if(numOfItems == 0)
        {   cout<<"No item is available in Inventory\n";
            return;
        }

        string items[100];
        float prices[100];
        int num, qty, found = 0;
        float sum = 0;

        cout<<"How many items did the customer buy? ";
        cin>>num;
        cout<<"Enter each item along with its price and quantity one by one\n";
        for(int i=0; i<num; i++)
        {  cout<<"Item "<<i+1<<endl;
           cout<<"Item: ";
           cin>>items[i];
           for(int j=0; j<numOfItems; j++)
           {   if(items[i] == Item[j])
               {  found = 1;
               }
           }
           if(!found)
           { cout<<"This Item is not Available\n";
             i--;
           }else{
             cout<<"Price: ";
             cin>>prices[i];
             cout<<"Quantity: ";
             cin>>qty;
             sum+=(prices[i]*qty);
             found = 0;
           }
        }
        
        cout<<"\n|<---------------------------->|\n";
        cout<<"|                              |\n";
        cout<<"|    ----------------------    |\n";
        cout<<"|    <- Customer Receipt ->    |\n";
        cout<<"|    ----------------------    |\n";
        cout<<"| Customer Id: 1001            |\n";
        cout<<"|                              |\n";
        cout<<"|     -------------------      |\n";
        cout<<"|     Items   "<<"|    Prices      |\n";
        for(int i=0; i<num; i++)
        {  cout<<"|     "<<items[i]<<"         "<<prices[i]<<"         |\n";
        }
        cout<<"|     -------------------      |\n";
        cout<<"|                              |\n";
        cout<<"| Total Price: "<<sum<<"             |"<<endl;
        cout<<"|                              |\n";
        cout<<"|<---------------------------->|\n\n";
    }
};

int main()
{   int num = 0;
    int choise;
    GroceryStore gs;
    
    do
    {   cout<<"1-Add Items\n2-Update Price\n3-View Inventory\n4-GenerateReceipt\n5-Exit\nEnter your choise: ";
        cin>>choise;

        switch(choise)
        {
            case 1:
              gs.AddItems(num);
              break;

            case 2:
              gs.UpdatePrices(num);
              break;
            
            case 3:
              gs.ViewInventory(num);
              break;

            case 4:
              gs.GenerateReceipt(num);
              break;

            case 5:
              cout<<"Thanks\n";
              break;

            default:
             cout<<"Invalid choise\n";
        }

    }while(choise != 5);
}
