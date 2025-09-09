# COSC 3360 - Assignment 1

## Problem

Dr. Rincon and Cameron Emrie are refining the compression algorithm based on the symbols' positions proposed by Dr. Rincon in 2008. To do this, they plan to modify the original algorithm by representing symbol positions as a set of positive integers, either a) the location where each symbol appears in the original message, or b) the difference between the positions where each symbol appears. They also aim to test which variable-length coding algorithm—Elias Gamma or Elias Delta—is best for representing positive integers.
 
For this assignment, you will create a multithreaded program to compute the number of bits needed to represent the positions and the difference between positions for each symbol in the original message using Elias Gamma and Elias Delta encoding.
 
The program's input is a multiline input string with the following information:
One line with the original message.
n lines representing the unique symbols in the original message (the symbols are sorted in descending order based on their frequency (if two or more symbols have the same frequency, you will sort the symbols based on their lexicographical order))
 
Input example:

aaaabbcccaaacccbbbdddddeeedd
a
d
c
b
e
The expected output is:
 
Symbol: a, Frequency: 7
Message: aaaabbcccaaacccbbbdddddeeedd
Position(s): 1 2 3 4 10 11 12 
Difference between position(s): 1 1 1 1 6 1 1 
Number of bits to represent the position(s) (Elias Gamma): 33
Number of bits to represent the difference between position(s) (Elias Gamma): 11
Number of bits to represent the position(s) (Elias Delta): 38
Number of bits to represent the difference between position(s) (Elias Delta): 11

Symbol: d, Frequency: 7
Message: bbccccccbbbdddddeeedd
Position(s): 12 13 14 15 16 20 21 
Difference between position(s): 12 1 1 1 1 4 1 
Number of bits to represent the position(s) (Elias Gamma): 55
Number of bits to represent the difference between position(s) (Elias Gamma): 17
Number of bits to represent the position(s) (Elias Delta): 59
Number of bits to represent the difference between position(s) (Elias Delta): 18

Symbol: c, Frequency: 6
Message: bbccccccbbbeee
Position(s): 3 4 5 6 7 8 
Difference between position(s): 3 1 1 1 1 1 
Number of bits to represent the position(s) (Elias Gamma): 30
Number of bits to represent the difference between position(s) (Elias Gamma): 8
Number of bits to represent the position(s) (Elias Delta): 32
Number of bits to represent the difference between position(s) (Elias Delta): 9

Symbol: b, Frequency: 5
Message: bbbbbeee
Position(s): 1 2 3 4 5 
Difference between position(s): 1 1 1 1 1 
Number of bits to represent the position(s) (Elias Gamma): 17
Number of bits to represent the difference between position(s) (Elias Gamma): 5
Number of bits to represent the position(s) (Elias Delta): 19
Number of bits to represent the difference between position(s) (Elias Delta): 5

Symbol: e, Frequency: 3
Message: eee
Position(s): 1 2 3 
Difference between position(s): 1 1 1 
Number of bits to represent the position(s) (Elias Gamma): 7
Number of bits to represent the difference between position(s) (Elias Gamma): 3
Number of bits to represent the position(s) (Elias Delta): 9
Number of bits to represent the difference between position(s) (Elias Delta): 3

Bits used for the positions (Elias Gamma encoding): 142
Bits used for the difference between positions (Elias Gamma encoding): 44

Bits used for the positions (Elias Delta encoding): 157
Bits used for the difference between positions (Elias Delta encoding): 46
Process:
 
Your solution must execute the following steps:
 
Read the input lines from STDIN.
Create n POSIX threads (where n is the number of symbols in the original message). Each child thread executes the following tasks:
- Receives the original message and the memory location to store the results of the coding process.
- Creates a simplified message by removing the symbols assigned to the previous child threads from the original message.
- Determines the positions and the difference between positions of the assigned symbol in the simplified message.
- Calculates the number of bits used to represent the symbol's position and the difference between the symbol's positions using the Elias Gamma encoding.
- Calculates the number of bits used to represent the symbol's position and the difference between the symbol's positions using the Elias Delta encoding.
- Stores the assigned symbol's information in a memory location accessible by the main thread.
 
Print the information for each symbol into STDOUT.
Print the number of bits used to represent the positions and the difference between positions of the original message with Elias Gamma and Elias Delta encoding.
 
Notes:
The position values for the symbols must start from one (not from zero), given that with Elias Gamma and Elias Delta encoding, we can only represent positive integers starting from one.
You can safely assume that the input will always be in the proper format.
You must use the output statement format based on the example above.
You can define additional functions if needed.
You must take full advantage of multithreading.
You must present code that is readable and has comments explaining the logic of your solution. A 10% penalty will be applied to submissions that do not follow this guideline.
You cannot use global variables. A 100% penalty will be applied to submissions using global variables. 
Not using multiple POSIX threads (the pthread.h library) to implement your solution will result in a 100% penalty.
A penalty of 100% will be applied to solutions that do not compile.
A penalty of 100% will be applied to solutions that hardcode the output.
 
Assignment rubric:
 
Correct output: 10 points per test case (20 points total).
Correct implementation of the thread function: 30 points.
Taking full advantage of multithreading (no pthread_join or sleep in the same loop as pthread_create): 30 points.
Creating the correct number of threads: 10 points.
Having clean and commented code: 10 points.
Penalties:
Presenting a solution that does not compile: -100 points.
Not using POSIX threads: -100 points.
Hardcoding the output: -100 points.
Using global variables: -100 points.
Requested files
main.cpp