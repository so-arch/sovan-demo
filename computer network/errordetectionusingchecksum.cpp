#include <bits/stdc++.h>

using namespace std;

void decToBinary(int n,string &binaryNumber)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--){
        binaryNumber+= to_string(binaryNum[j]);
    }
}

void receiver(string &number){
     int remainder = number.length() % 3;
     if (remainder != 0) {
        number.append(3 - remainder, '0');
    }

    for (int i = 0; i < number.length(); i=i+3) {
        int num = 0;
        for (int j = 0; j < 3; j++) {
            num = num + (number[i + j] - '0') * pow(2, 2 - j);
        }
        cout << num <<" ";
    }
}
int main() {
    string binaryNumber;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;
    int len=binaryNumber.length();

    int remainder = binaryNumber.length() % 3;
    if (remainder != 0) {
        binaryNumber.append(3 - remainder, '0');
    }

    int sum = 0;
    for (int i = 0; i < binaryNumber.length(); i=i+3) {
        int num = 0;
        for (int j = 0; j < 3; j++) {
            num = num + (binaryNumber[i + j] - '0') * pow(2, 2 - j);
        }
        sum += num;
        
    }
    cout << "Total sum: " << sum << endl;
    decToBinary(sum,binaryNumber);
    cout << binaryNumber<<endl;
    cout << "val: "<<sum<<endl;
    cout << binaryNumber.substr(0,len)<<endl;
    string num=binaryNumber.substr(0,len);
    receiver(num);
    return 0;
}
