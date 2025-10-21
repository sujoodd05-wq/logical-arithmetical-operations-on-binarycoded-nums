

#include "Bits.h"
#include <iostream>
using namespace std;

int main()
{
    // Test constructor with integer input
    Bits b1(12);  
    cout << "b1 (12): " << b1 << endl;

    // Test copy constructor
    Bits b2 = b1;
    cout << "b2 (copy of b1): " << b2 << endl;

    // Test assignment operator with integer
    Bits b3;
    b3 = 11;  
    cout << "b3 (11): " << b3 << endl;
    Bits sumResult = b1 + b3;
    cout << "b1+b3= " << sumResult << endl;
    int hdis = b1 - b3;
    cout << "b1-b3= " << hdis << endl;
    Bits and1 = b1 & b3;
    cout << "b1&b3= " << and1 << endl;
    Bits or1 = b1 | b3;
    cout << "b1|b3= " << or1 << endl;
    Bits r1 = b1 ^ b3;
    cout << "b1^b3= " << r1 << endl;
    Bits not1 = !b1 ;
    cout << "!b1= " << not1 << endl;
    Bits not2 = !b3;
    cout << "!b3= " << not2 << endl;
    // Test conversion to string
    char* str = toString(b1);
    cout << "b1 as string: " << str << endl;
    delete[] str;  // Free allocated memory

    // Test conversion to decimal
    int decimalValue = toDecimal(b1);
    cout << "b1 as decimal: " << decimalValue << endl;

    // Test shift left (<<) by 2 positions
    Bits shiftLeftResult = b1 << 2;
    cout << "b1 << 2: " << shiftLeftResult << endl;
    // Test shift right (>>) by 1 position
    Bits shiftRightResult = b1 >> 1;
    cout << "b1 >> 1: " << shiftRightResult << endl;
    Bits c = b1 << b3;
    cout << "b1<<b3= " << c << endl;
    Bits c1 = b1 >> b3;
    cout << "b1>>b3= " << c1 << endl;
    Bits c2 = b3 >> b1;
    cout << "b3>>b1= " << c2 << endl;
    // Test input operator (>>)
    Bits b4;
    cout << "Enter a decimal number: ";
    cin >> b4;
    cout << "b4 (from input): " << b4 << endl;

    return 0;
}


