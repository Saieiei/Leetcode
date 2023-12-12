#include <iostream>
using namespace std;

void decimalToBinary(int decimalNumber) {
 
    if (decimalNumber == 0) {
        cout << "Binary: 0" << endl;
        return;
    }

    
    int binaryResult = 0;
    int position = 1;

    while (decimalNumber > 0) {
        
        int remainder = decimalNumber % 2;
        binaryResult = remainder * position + binaryResult;
        position = position*10;
        decimalNumber =decimalNumber/2;
    }

    cout << "Binary: " << binaryResult << endl;
}

int main() {
   
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;
    decimalToBinary(decimalNumber);
}
