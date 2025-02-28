// Author: Thalia Ysassi
// Date: 2/26/25
// Function: Replicate an ALU with C++. Includes error messages for invalid cases. 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Function Prototypes
void validOperation(const string& operation, const vector<string>& numbers, uint32_t& num1, uint32_t& num2);
void getnumbers(const string& operation, const vector<string>& numbers, uint32_t& num1, uint32_t& num2);
void computeOperation(const string& operation, uint32_t& num1, uint32_t& num2);

int main () {
ifstream fin("pp1_input.txt");  // input file
vector<string> fileLines;  // stores each individual line
uint32_t num1 = 0;  // stores first valid number
uint32_t num2 = 0;  // stores second valid number

if (!fin.eof()) {
    string line;  // stores individual line before stored into fileLines
    // read file input
    while (getline(fin, line)) {
        fileLines.push_back(line);
    }
}
    fin.close();

    cout << "--- RESULTS ---" << endl;
    for (int i = 0; i < fileLines.size(); i++) {
        stringstream ss(fileLines[i]);  // Current line in file
        string operation;  // stores the valid operation
        string number;  // stores the next number in fileLine
        vector<string> numbers;  // stores the string of numbers
        ss >> operation;

        while (ss >> number) {
            numbers.push_back(number);
        }

        // prints original operation and results
        cout << fileLines[i] << " : ";
        validOperation(operation, numbers, num1, num2);  // checks if operation is valid
    }

    return 0;
}


//// Helper Functions Definitions ////
void validOperation(const string& operation, const vector<string>& numbers, uint32_t& num1, uint32_t& num2) {
    bool valid = false;  // Used to check if operation is valid
    if (operation == "ADD" || operation == "SUB" || operation == "AND" ||operation == "OR" 
        || operation == "XOR" || operation == "EQ" || operation == "LT" || operation == "GT" 
        || operation == "NOT" || operation == "LSL" || operation == "LSR") {
        valid = true;
    } else {
        cout << "Unsupported Operation" << endl;
    }
    if (valid) {
        getnumbers(operation, numbers, num1, num2);  // Gets numbers if operation is valid
    }
}

void getnumbers(const string& operation, const vector<string>& numbers, uint32_t& num1, uint32_t& num2) {
    stringstream ss;
    bool valid = true;  // Used to check if all numbers are valid
    if (operation == "ADD" || operation == "SUB" || operation == "AND" ||operation == "OR" 
        || operation == "XOR" || operation == "EQ" || operation == "LT" || operation == "GT" 
        || operation == "LSL" || operation == "LSR") {
            if (numbers.size() == 2) {  // 2 numbers for binary or 1 number and 1 numShift for LSL & LSR
                ss << numbers [0];
                ss >> hex >> num1;
                ss.clear();

                if (numbers[1][0] == '-') {
                    valid = false;
                    cout << "Negative Shift Count" << endl;
                } else {
                    ss << numbers[1];
                    ss >> hex >> num2;
                    if (operation == "LSL" || operation == "LSR") {
                        if (num2 > 31) {  // Checks if the bitsize is in range
                            valid = false;
                            cout << "Shift Value Exceeds Bit Size" << endl;
                        }
                    }
                }

            } else {
                cout << "Invalid Number Count" << endl;
                valid = false;
            }
     } else if (operation == "NOT") {
        if (numbers.size() == 1) {
            ss << numbers[0];
            ss >> hex >> num1;
        } else {
            valid = false;
            cout << "Invalid number Count" << endl;
        }

    }
    if (valid) {
        computeOperation(operation, num1, num2);  // If all numbers are valid, compute the final operation
    }
}

void computeOperation(const string& operation, uint32_t& num1, uint32_t& num2) {
    uint32_t finalNum;  // stores the final result
    bool numResult = true;  // Checks if operation or expression with a final number

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
    } else if (operation == "NOT") {
        finalNum = ~num1;
    
    } else if (operation == "LSL") {
        finalNum = num1 << num2;

    } else {  // operation is LSR
        finalNum = num1 >> num2;
    }

    if (numResult) {
        cout << "0x" << hex << finalNum << endl;  // prints the final num if it is a binary/logic shift operation
    }
}