# hamming-code
Hamming code (Error correcting codes) implementation for Principles of Cybersecurity course (COMP3632) at HKUST.

## a3a.cpp
a3a.cpp is a program that will automatically generate the correct parity bits
for any input string. The input string will be the first argument of the program.
Your program, called a3a, should write the parity bits in the correct order to stdout
(e.g. cout or print) as characters, ”0” or ”1”.

example:
#### ./a3a ab

yields the parity bits
#### 01011

## a3b.cpp
a3b.cpp is a program that will automatically correct any one-bit error in
either the parity or the data string. 
The parity will be the first argument of the
program, and the data string will be the second argument of the program. Your
program, called a3b, should output the corrected parity bits to the first line of
stdout, and the corrected data string to the second line of stdout. If there is no
correction to be made, you should still output the original parity bits and the data
string. 

example:
#### ./a3b 01011 ac

yields the output
#### 01011
#### a
