// Author: Thalia Ysassi
// Date: 2/26/25
// Function: Replicate an ALU with C++. Includes error messages for invalid cases. 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void findOperation(const string& operation, ifstream& fin);
void computeBinOperation(const string& operation, uint32_t& num1, uint32_t& num2);
void computeNotOperation(uint32_t& num1);
void computeShiftOperation(const string& operation, uint32_t& num1, uint32_t& numShift);

int main () {
string operation;
ifstream fin("pp1_input.txt");

while (!fin.eof()) {
    // read file input
    fin >> operation;
    findOperation(operation, fin);
}
    return 0;
}

void findOperation(const string& operation, ifstream& fin) {
    uint32_t num1 = 0;
    uint32_t num2 = 0;
    uint32_t numShift = 0;

    if (operation == "ADD" || operation == "SUB" || operation == "AND" ||operation == "OR" 
        || operation == "XOR" || operation == "EQ" || operation == "LT" || operation == "GT") {
        fin >> std::hex >> num1 >> std::hex >> num2;
        cout << " num1 = " << num1 << " and num2 is = " << num2;
        computeBinOperation(operation, num1, num2);

    } else if (operation == "NOT") {
        fin >> std::hex >> num1;
        computeNotOperation(num1);

    } else if (operation == "LSL" || operation == "LSR") {
        fin >> std::hex >> num1;
        
        if (fin.peek() == '-') {
            cout << "Negative Shift Count" << endl;
        } else {
            fin >> std::hex >> numShift;
            if (numShift > 31) {
                cout << "Shift Value Exceeds Bit Size" << endl;
            } else {
                computeShiftOperation(operation, num1, numShift);
            }
        }
        
    } else {
        cout << "Unsupported Operation" << endl;
    }
}

void computeBinOperation(const string& operation, uint32_t& num1, uint32_t& num2) {
    uint32_t finalNum;
    bool numResult = true;

    if (operation == "ADD") {
        finalNum = num1 + num2;
    } else if (operation == "SUB") {
        finalNum = num1 - num2;
    } else if (operation == "AND") {
        finalNum = num1 & num2;
    } else if (operation == "OR") {
        finalNum = num1 | num2;
    } else if (operation == "XOR") {
        finalNum = num1 ^ num2;
    } else if (operation == "EQ") {
        numResult = false;
        if (num1 == num2) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    } else if (operation == "LT") {
        numResult = false;
        if (num1 < num2) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    } else if (operation == "GT") {
        numResult = false;
        if (num1 > num2) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    if (numResult) {
        cout << "0x" << std::hex << finalNum << endl;
    }
}

void computeNotOperation(uint32_t& num1) {
    cout << "0x" << std::hex << ~num1 << endl;
}

void computeShiftOperation(const string& operation, uint32_t& num1, uint32_t& numShift) {
    uint32_t finalNum = 0;
    if (operation == "LSL") {
        finalNum = num1 << numShift;
    } else {
        finalNum = num1 >> numShift;
    }
    cout << "0x" << std::hex << finalNum << endl;
}
