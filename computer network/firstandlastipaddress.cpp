
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {

    vector<int> octets; 
    int subnetmask = 0;

    for (int i = 1; i <= 4; i++) {
        cout << "Enter the " << i << "th OCTET: ";
        int n;
        cin >> n;
        octets.push_back(n);
    } 
    
    cout << "\nEnter subnet mask value: ";
    cin >> subnetmask;

    bitset<8> lastoctet(octets[3]);

    cout << "Input in Binary: ";
    for (int i = 0; i < 4; i++) {
        bitset<8> octet(octets[i]);
        cout << octet << " "; 
    }
    cout << endl;

    int masked = 32 - subnetmask; 
    for (int i = 0; i < masked; i++) {
        lastoctet.reset(i); 
    }

    cout << "First IP Address: ";
    for (int i = 0; i < 3; i++) {
        bitset<8> octet(octets[i]);
        cout << octet << " ";
    }
    cout << lastoctet << endl;

    for (int i = 0; i < masked; i++) {
        lastoctet.set(i);
    }

    cout << "Last IP Address: ";
    for (int i = 0; i < 3; i++) {
        bitset<8> octet(octets[i]);
        cout << octet << " ";
    }
    cout << lastoctet << endl;

    return 0;
}
