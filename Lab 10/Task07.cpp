#include "iostream"
#include "fstream"
using namespace std;

int main() {

    ofstream outFile("sensor_log.txt");
    if(!outFile) {
        cerr << "File can't be opend!\n";
        exit(1);
    }

    outFile.write("Sensor 1: 25.5 C\n", 16);
    streampos pos = outFile.tellp();
    cout << "Position After writing about sensor 1: " << pos << endl;

    outFile.write("\nSensor 2: 98.1 %RH\n", 18);
    pos = outFile.tellp();
    cout << "Position After writing about sensor 2: " << pos << endl;

    outFile.close();
}
