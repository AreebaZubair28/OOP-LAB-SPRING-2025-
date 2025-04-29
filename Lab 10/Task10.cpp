#include "iostream"
#include "fstream"
using namespace std;

int main() {
    ifstream inFile("data_records.txt", ios::binary);
    if(!inFile) {
        cerr << "Can't open!\n";
        exit(1);
    }

    // Calculating offsets
    /*
    Windows Line Endings (\r\n)
        In Windows, each line ends with \r\n (2 bytes), not just \n (1 byte).
        Example record: "Record 1\r\n"
        Length = 8 (text) + 2 (\r\n) = 10 bytes.

        To reach the third record, skip:
        Record 1: 10 bytes
        Record 2: 10 bytes

        Total offset = 10 + 10 = 20 bytes.
    */
 
    streampos offset = 20;
    inFile.seekg(offset, ios::beg);

    string record;
    getline(inFile, record);
    cout << "\nThird recorde: " << record << endl << endl;

    inFile.close();
}
