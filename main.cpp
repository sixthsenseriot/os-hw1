#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Input Example
/*aaaabbcccaaacccbbbdddddeeedd
a
d
c
b
e*/

// Expected Output
// Symbol: a, Frequency: 7
// Message: aaaabbcccaaacccbbbdddddeeedd
// Position(s): 1 2 3 4 10 11 12 
// Difference between position(s): 1 1 1 1 6 1 1 
// Number of bits to represent the position(s) (Elias Gamma): 33
// Number of bits to represent the difference between position(s) (Elias Gamma): 11
// Number of bits to represent the position(s) (Elias Delta): 38
// Number of bits to represent the difference between position(s) (Elias Delta): 11

// Symbol: d, Frequency: 7
// Message: bbccccccbbbdddddeeedd
// Position(s): 12 13 14 15 16 20 21 
// Difference between position(s): 12 1 1 1 1 4 1 
// Number of bits to represent the position(s) (Elias Gamma): 55
// Number of bits to represent the difference between position(s) (Elias Gamma): 17
// Number of bits to represent the position(s) (Elias Delta): 59
// Number of bits to represent the difference between position(s) (Elias Delta): 18

// Symbol: c, Frequency: 6
// Message: bbccccccbbbeee
// Position(s): 3 4 5 6 7 8 
// Difference between position(s): 3 1 1 1 1 1 
// Number of bits to represent the position(s) (Elias Gamma): 30
// Number of bits to represent the difference between position(s) (Elias Gamma): 8
// Number of bits to represent the position(s) (Elias Delta): 32
// Number of bits to represent the difference between position(s) (Elias Delta): 9

// Symbol: b, Frequency: 5
// Message: bbbbbeee
// Position(s): 1 2 3 4 5 
// Difference between position(s): 1 1 1 1 1 
// Number of bits to represent the position(s) (Elias Gamma): 17
// Number of bits to represent the difference between position(s) (Elias Gamma): 5
// Number of bits to represent the position(s) (Elias Delta): 19
// Number of bits to represent the difference between position(s) (Elias Delta): 5

// Symbol: e, Frequency: 3
// Message: eee
// Position(s): 1 2 3 
// Difference between position(s): 1 1 1 
// Number of bits to represent the position(s) (Elias Gamma): 7
// Number of bits to represent the difference between position(s) (Elias Gamma): 3
// Number of bits to represent the position(s) (Elias Delta): 9
// Number of bits to represent the difference between position(s) (Elias Delta): 3

// Bits used for the positions (Elias Gamma encoding): 142
// Bits used for the difference between positions (Elias Gamma encoding): 44

// Bits used for the positions (Elias Delta encoding): 157
// Bits used for the difference between positions (Elias Delta encoding): 46

void getFrequency(string message, char symbol) {
    
    int messageLength = message.length();
    int frequency = 0;
    
    for (int i = 0; i < messageLength; ++i) {
        if (message[i] == symbol) {
            frequency += 1;    
        }
    }
    cout << "Frequency: " << frequency << endl; 
}

int main() {
    string inputMessage;
    cout << "Please input a message: ";
    cin >> inputMessage;
    
    
    vector<char> symbols;
    string inputSymbol;
    
    cout << "Please input the unique symbols from the message: " << endl;
    while (getline(cin, inputSymbol)) {
        if  (!inputSymbol.empty()) {
            symbols.push_back(inputSymbol[0]);    
        }
    }
    
    // cout << "Original Message: " << inputMessage << endl;
    // cout << "Unique Symbols: " << endl;
    // for (char c : symbols) {
    //     cout << c << endl;    
    // }

    for (int i = 0; i < symbols.size(); ++i) {
        getFrequency(inputMessage, symbols[i]);
    }

    return 0;
}