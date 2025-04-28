#include "iostream"
#include "fstream"
using namespace std;

class InventoryItem {
public:
    int itemId;
    char itemName[20];
};

int main() {
    // ------------ Writing ---------------- //
    InventoryItem item1 = {1001, "Skin Product"};
    ofstream outFile("inventory.dat", ios :: binary);
    outFile.write((char*)&item1, sizeof(item1));
    outFile.close();

    // ------------ Reading ---------------- //
    InventoryItem item2;
    ifstream inFile("inventory.dat", ios :: binary);
    inFile.read((char*)&item2, sizeof(item2));
    inFile.close();

    cout << "Item Id: " << item2.itemId << endl;
    cout << "Item Name: " << item2.itemName << endl;
}
