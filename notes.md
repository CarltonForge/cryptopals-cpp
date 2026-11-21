 
XOR stands for Exclusive OR.

It's a bitwise operation that compares two bits
and returns 1 if they are different, and 0 if they're the same.

Its symbol in C++ is ^.

The truth table:
A	  B	   A XOR B
0	  0 	     0
0	  1	       1
1	  0	       1
1	  1	       0


The easiest way to remember it:

Different = 1. Same = 0.

lets say we have two bytes:

A = 01001000
B = 01101000
compare each position:
    01001000
XOR 01101000
------------
    00100000

only the bits that differ produce 1.

The interesting part is that if you XOR the XOR data you get your
original data back. For example:

    01001000  (A)
XOR 01101000  (B)
------------
    00100000  (C)

    00100000  (C)
XOR 01101000  (B)
------------
    01001000  (A)

    this is called self- inverse and the entire operation is simply:
    
    int result = a ^ b;
*/

