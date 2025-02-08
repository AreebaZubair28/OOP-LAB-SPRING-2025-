#include "iostream"
using namespace std;

int input1(string arr[])
{   int num;
    cout << "Enter number of the participants for Event 1(not more than 5): ";
    cin >> num;
    
    if(num>5)  
    {   cout << "Participants exceeded. Enter less than or eqaul to 5: ";
        cin >> num;
    }

    for (int i = 0; i < num ; i++)
    {     cout << "Name of Participant " << i+1 <<": ";
          cin >> arr[i];
    }

  return num;
}

int input2(string arr[])
{   int num;
    cout << "Enter number of the participants for Event 2(not more than 5): ";
    cin >> num;
    
    if(num>5)  
    {   cout << "Participants exceeded. Enter less than or eqaul to 5: ";
        cin >> num;
    }

    for (int i = 0; i < num ; i++)
    {     cout << "Name of Participant " << i+1 <<": ";
          cin >> arr[i];
    }

  return num;
}

void attendanceChecker(string arr1[], string arr2[], int num1, int num2)
{    int count = 0;
     cout<<"\n--------------------------------\n\n";
     for(int i=0 ; i<num1 ; i++)
     {
          for(int j=0 ; j<num2 ; j++)
          {
            if(arr1[i] == arr2[j])   
            { cout <<"Participant " << arr1[i] << " has registered for both events.\n";
              count++;
            }
          }
     }
     if(count == 0 ) 
     cout << "No participant registered for both events.\n";
}

void donations(string arr1[], string arr2[], int num1, int num2)
{   int donation1 = 0, donation2= 0;
    cout<<"\n--------------------------------\n\n";
    for(int i=0 ; i<num1 ; i++)
    {
        donation1+=10;
    }

    for(int i=0 ; i<num2 ; i++)
    {
        donation2+=10;
    }

    int totalDonation = donation1 + donation2;

    cout << "Total Donation: $" << totalDonation << endl;
}

void reverse(string arr1[], string arr2[], int num1, int num2)
{   cout<<"\n--------------------------------\n\n";
    cout <<"Displaying the names in reverse order:\n";
    cout <<"Event 1\n";

    for(int i=num1-1; i>=0 ;i--)
    {
        cout << arr1[i] << endl;
    }

    cout <<"Event 2\n";
    for(int i=num2-1; i>=0 ;i--)
    {
        cout << arr2[i]<< endl;
    }
}

void barChart(string arr1[], string arr2[], int num1, int num2)
{   cout<<"\n--------------------------------\n\n";
    cout << "Event 1: ";
    for(int i=0 ; i<num1; i++)
    {
       cout<<"*";
    }
    cout << endl;

    cout << "Event 2: ";
    for(int i=0 ; i<num2; i++)
    {
       cout<<"*";
    }
}

int main(){
    string arr1[100];
    string arr2[100];

    int len1 = input1(arr1);
    int len2 = input2(arr2);
    attendanceChecker(arr1, arr2, len1, len2);
    donations(arr1, arr2, len1, len2);
    reverse(arr1, arr2, len1, len2);
    barChart(arr1, arr2, len1, len2);
}
