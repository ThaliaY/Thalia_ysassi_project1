# Thalia_Ysassi_Project1 Report
CS 219 Programming Assignment 1 (Spring 2025)

# How to Run Program | Makefile Commands
make main: executable function \
make clean: removes executable 

# How the Code Works
My code is split into a main function with three helper functions. The three helper functions are linked together and require a valye in the current function to be true before the next function is called. This makes it quicker to move onto the next operation as soon as possible, as it doesn't call the next function if the operands or operations are invalid. 

This program utilizes vector strings to be able to parse and split up each line of code by its operations and operands. Main reads the file into a vector string, and then for each line, the operation is seperated and each operand is added to a new string. The operation is then put into the helper function validOperation() to check if it is supported. If it is, the getNumbers() helper function is called, which uses stringstream to check the size of a operand string. If it matches the amount needed by the operation, the string is broken up to be assigned to num1 and num2 and the computeOperation() function is called. This calculates the final value/result of the operation and prints it into the terminal.

I broke the code up in this way because it allows me to only have to call validOperation() in the main file, as the other functions depend on it being true to continue. This method also allows me to add the error messages to each relavent function, and it immediately goes to the next line of the file instead of completing the rest of the operation.

# Logic and Functionality 

1. ADD - Adds two numbers
2. SUB - Subtracts two numbers
3. AND - Compares two numbers, results in a 1 for every identical bit
4. OR - Compares two numbers, results in a 1 for every bit equal to 1
5. XOR - Compares two numbers, results in a 1 if only one bit is equal to 1
6. NOT - flips each bit from 0 to 1, or 1 to 0
7. LSL - shifts one number left by the second number of times
8. LSR -shifts one number right by the second number of times
9. EQ  - checks if the number are equal, return "True" if so or "False" if not
10. LT - checks if the first number is less than the second number, checks if the operands are equal, return "True" if so or "False" if not
11. GT - checks if the first number is greater than the second number, checks if the operands are equal, return "True" if so or "False" if not

# Test Cases
1. ADD - 0x1234 0x8765 \
Num1 = 0x1234 \
Num2 = 0x8765 \
Final Result = 0x9999

2. SUB - 0x32 0x14 \
Num1 = 0x32 \
Num2 = 0x14 \
Final Number = 0x1e

3. AND - 0xD 0x9 \
Num1 = 0xD \
Num2 = 0x9 \
Final Number = 0x9

4. OR - 0xAFF011
Num1 = 0xAFF011 \
Num2 = None \
Final Result =  Invalid Number Count

5. XOR - 0x15 0xF \
Num1 = 0x15 \
Num2 = 0xF \
Final Result =  0x1a
6. NOT - 0xFFFFFFFFF \
Num1 = 0xFFFFFFFFF \
Final Number = 0x0
7. LSL -  0xFFFFFFFF 0x2 \
Num1 =  0xFFFFFFFF \
Number of Shifts = 0x2 \
Final Result = 0xfffffffc
8. LSR - 0xAAA558 -0x1 \
Num1 = 0xAAA558 \
Num2 = -0x1 (Invalid Result)\
Final Result = Negative Shift Count
9. EQ  - 0xA 0xA
Num1 = 0xA \
Num2 = 0xA \
Final Number = True \
10. LT - 0xA 0xF \
Num1 = 0xA 
Num2 = 0xF \
Final Result = True
11. GT - 0xA \
Num1 = 0xA \
Num2 = 0xF \
Final Result = False

# Invalid Cases in File
Unsupported Operation
* Invalid 0xC 0x5 : "Invalid" is not a operation in ALU
* 5 0x20000 0x9 : "5 is not a operation in a ALU"

Shift Value Exceeds Bit Size 
* LSL 0x40 0x21 : 0x21 converts to 33 in decimal, which exceed the bit size

Negative Shift Count 
* LSR 0xAAA558 -0x1 : -0x1 is a negative hex number and is invalid

Invalid Operand Count 
* OR 0xAFF011 : One number is provided when the OR operation requires two 
* EQ 0xA :  One number is provided when the EQ operation requires two
* AND 0xA 0xF 0x1 : Three numbers are provided when the AND operation requires two

# Input Text
```
ADD 0x1234 0x8765
SUB 0x32 0x14
AND 0xD 0x9
OR 0xAFF011
XOR 0x15 0xF
NOT 0xFFFFFFFFF
LSR 0xAAA558 -0x1
LSL 0x40 0x21
Invalid 0xC 0x5
EQ 0xA 0xA
LT 0xA 0xF
GT 0xF 0xA
EQ 0xA
AND 0xA 0xF 0x1
ADD 0x1 0xFFFFFFFF
SUB 0xFFFFFFFF 0x20
5 0x20000 0x9
ADD 0x72DF9901 0x2E0B484A
LSL 0xFFFFFFFF 0x2
GT 0xA 0xF
```