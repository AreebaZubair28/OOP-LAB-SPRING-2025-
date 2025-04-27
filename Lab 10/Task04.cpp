#include "iostream"
#include "string"
#include "fstream"
#include "sstream"
using namespace std;

class Vehicle{
private:
    ifstream file;
    string type, id, name, year, extraData;
    float sw;
    int capacity;

public:
    Vehicle(string fileName) {
        file.open(fileName);
        if(!file){
            cerr<<"Error: file can't be opened!\n";
            exit(1);
        }
    }

    void displayData() {
        cout<<"\nDisplaying Details:\n";
        cout<<"Id: "<<id<<endl;
        cout<<"Type: "<<type<<endl;
        if(type == "AutonomousCar") {
            cout<<"Software Version: "<<sw<<endl;
        }
        else if(type == "ElectricVehicle") {
            cout<<"Battery Capacity: "<<capacity<<endl;
        } 
    }

    void read() {   
        string line;
        if(file.is_open()) {
            while(getline(file,line)) {
                istringstream iss(line);
                getline(iss, type, ',');
                if(type == "AutonomousCar") {
                    getline(iss, id, ',');
                    getline(iss, name, ',');
                    getline(iss, year, ',');
                    getline(iss, extraData, ',');

                    size_t pos = extraData.find(":");
                    if(pos != string::npos) {
                        string s = extraData.substr(pos+1,pos+3);
                        sw = stof(s);
                    }
                    displayData();
                }
                else if(type == "ElectricVehicle") {
                    getline(iss, id, ',');
                    getline(iss, name, ',');
                    getline(iss, year, ',');
                    getline(iss, extraData, ',');

                    size_t pos = extraData.find(":");
                    if(pos != string::npos) {
                        string s = extraData.substr(pos+1,pos+3);
                        capacity = stoi(s);
                    }
                    displayData();
                }   
            }
            file.close();
        }else {
            cout <<"File is not opened!\n";
        }
    }

    ~Vehicle(){
        if(file.is_open()) {
            file.close();
            cout<<"\nFile has closed!\n";
        }else {
            cout <<"\nFile is already closed!\n";
        } 
    }
};

int main() {
    Vehicle v("vehicles.txt");
    v.read();
}
