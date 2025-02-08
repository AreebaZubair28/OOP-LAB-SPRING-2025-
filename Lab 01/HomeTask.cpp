#include "iostream"
using namespace std;

void input(int arr[4][100], int r, int c)
{
    for(int i=0; i<r; i++)
    {   cout << "City "<< i+1 <<endl;
        for(int j=0; j<c; j++)
        {
           cout << "Air Quality Index of Day "<< j+1 <<": ";
           cin >> arr[i][j];
        }
    }
     cout<<"\n--------------------------------\n\n";
}

void average(int arr[4][100], int r, float c)
{  float avg[4];
   float num = 0, max = 0;

   for(int i=0; i<r ; i++)
   {
      for(int j=0; j<c ; j++)
      {
          num+=arr[i][j];
      }
      avg[i] = num/c;
      cout << "Average AQI of City " << i+1 << ": " << avg[i] << endl;
      num = 0;
   }
    cout <<"\n";

   for(int i =0 ; i<r ; i++)
   {   if(avg[i] > max)   
       {   max = avg[i];
           num = i+1;
       }
   }

   cout << "City with the lowest AQI: " << num << endl;
     cout<<"\n--------------------------------\n\n";
}

void criticalPollutionDays(int arr[4][100], int r, int c, int days[] , int day)
{   cout << "Days with AQI exceeded 150:\n";
    int found = 0;
    for(int i=0; i<r; i++)
      { cout << "City " << i+1<< ":" <<endl; 
        for(int j=0; j<c ; j++)
           {   if(arr[i][j] > 150)
               { 
                   cout <<"day "<<j+1 <<endl;
                   found++;
               }
           }
           days[i] = found;
           if(!found)
           {
              cout<<"No days found\n";
           }
           found=0;
      }
       cout<<"\n--------------------------------\n\n";
}

void visualDisplay(int arr[4][100], int r, int c)
{   for(int i=0; i<r; i++)
    {   cout << "City " << i+1 <<endl; 
        for(int j=0; j<c; j++)
        {  cout <<"Day "<<j+1<<": ";
           if(arr[i][j] > 50)
           {  int num = arr[i][j] / 50;
              for(int k=0 ; k<num ; k++)
              {
                cout <<"*";
              }
           }
           cout <<"\n";
        }
   }
    cout<<"\n--------------------------------\n\n";
}

void monthlyaverage(int arr[4][100], int r, float c, int high[4], int low[4])
{  float monthlyavg[4];
   float weeklyavg[4][4];
   float num = 0;
   int max=0, min=0;

   for(int i=0; i<r ; i++)
   {  for(int j=0; j<c ; j++)
      {  num+=arr[i][j];
         
         if(arr[i][j] > max)
         {  max = arr[i][j];
         }
         if(i==0 || arr[i][j] < min)
         {  min = arr[i][j];
         }
      }
      high[i] = max;   low[i] = min;
      monthlyavg[i] = num/c;
      cout << "Average AQI of City " << i+1 << ": " << monthlyavg[i] << endl;
      num = 0;
   }
   cout <<"\n";

   float firstweek[4];
   for(int i=0; i<4 ; i++)
   {  for(int  j=0; j<7; j++)
      {  num+=arr[i][j];
      }
      firstweek[i] = num/7;
      num=0;
   }
   float lastweek[4];
   for(int i=0; i<4 ; i++)
   {  for(int  j=21; j<28; j++)
      {  num+=arr[i][j];
      }
      lastweek[i] = num/7;
      num=0;
   }

  float avg[4];
  for(int i=0; i<4; i++)
  { if(firstweek[i] > lastweek[i])
    {
      avg[i] = firstweek[i] - lastweek[i];
    }else{
       avg[i] = lastweek[i] - firstweek[i] ;
    }
  }

  float improve = 0;
  for(int i =0 ; i<r ; i++)
   {   if(avg[i] > improve )   
       {   improve = avg[i];
           num = i+1;
       }
   }
   cout << "City with the most improved air quality: " << num << endl;
    cout<<"\n--------------------------------\n\n";
}

void weeklyaverage(int arr[4][100], int r, int c, float weeklyavg[4][4])
{  float num = 0;
    
   for(int i=0; i<4 ; i++)
   {  for(int  j=0; j<7; j++)
      {  num+=arr[i][j];
      }
      weeklyavg[i][0] = num/7;
      num=0;
   }

   for(int i=0; i<4 ; i++)
   {  for(int  j=7; j<14; j++)
      {  num+=arr[i][j];
      }
      weeklyavg[i][1] = num/7;
      num=0;
   }

   for(int i=0; i<4 ; i++)
   {  for(int  j=14; j<21; j++)
      {  num+=arr[i][j];
      }
      weeklyavg[i][2] = num/7;
      num=0;
   }

   for(int i=0; i<4 ; i++)
   {  for(int  j=21; j<28; j++)
      {  num+=arr[i][j];
      }
      weeklyavg[i][3] = num/7;
      num=0;
   }
}

void report(float weeklyavg[4][4], int pollutedDays[100], int highest[4], int lowest[4])
{   cout << "----->  Report of AQI  <-----\n\n------------------------------------\n\n";
    cout<<"WEEKLY AVERAGES:-\n";
    for(int i=0; i<4; i++)
    { cout<< "City "<<i+1<<":\n";
      for(int j=0; j<4; j++)
      { cout<<"Week "<<j+1<<": "<<weeklyavg[i][j]<<endl;
      }
      cout<<endl;
    }

    cout<<"------------------------------------\n\n";
    cout<<"CRITICAL POLLUTION DAYS:-\n";
    for(int i=0; i<4; i++)
    {  cout<< "City "<<i+1<<": ";
       cout<<pollutedDays[i]<<endl;
    }

    cout<<"\n------------------------------------\n\n";
    cout<<"HIGHEST & LOWEST AQL VALUES RECORED DURING MONTH:-\n\n";
    for(int i=0; i<4; i++)
    {  cout<< "City "<<i+1<<":\n";
       cout<<"Highest: "<<highest[i];
       cout<<"\nLowest: "<<lowest[i]<<endl;
    }
    cout<<"\n------------------------------------\n";
}

int main()
{   int arr[4][100];
    float weeklyavg[4][4];
    int pollutedDays[100];
    int highest[4];
    int lowest[4];

    input(arr,4,7);
    average(arr,4,7);
    criticalPollutionDays(arr,4,7,pollutedDays,4);
    visualDisplay(arr,4,7);
    input(arr,4,28);
    monthlyaverage(arr,4,28,highest,lowest);
    weeklyaverage(arr,4,28,weeklyavg);
    criticalPollutionDays(arr,4,28,pollutedDays,4);
    report(weeklyavg,pollutedDays,highest,lowest);
}
