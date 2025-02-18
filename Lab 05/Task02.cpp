#include "iostream"
#include "string"
using namespace std;

class Patient{
public:
    int id;
    string name;
    int *testResults;
    int num;

    Patient(int id, string n, int arr[], int size)
    {   num = size;
        this-> id = id;
        name = n;
        testResults = new int[size];
        for(int i=0; i<size; i++)
        {
            testResults[i] = arr[i];
        }
    }
 
    Patient(const Patient& p)
    {
        id = p.id;
        name = p.name;
        num = p.num;
        testResults = new int[num];
        for(int i=0; i<num; i++)
        {
            testResults[i] = p.testResults[i];
        }
    }

    void display()
    {
        cout<<"name: "<<name<<endl;
        cout<<"Id: "<<id<<endl;
        cout<<"Test Results: "<<endl;
        for(int i=0; i<num; i++)
        {
            cout<<"Test "<<i+1<<": "<<testResults[i]<<endl;
        }
    }

    ~Patient() {
        delete[] testResults;
    }
};

int main()
{    int arr[] = {100,90,80};

    Patient p1(1001,"Areeba",arr,3);
    cout << "Original Patient Record:\n";
    p1.display();

    Patient p2 = p1;
    cout << "Duplicate Patient Record for Analysis:\n";
    p2.display();

    return 0;
}
