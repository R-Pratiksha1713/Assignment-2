#ASN 03
1.TEAM DEATILS:
     NAME                      USN
1.R.PRATIKSHA               1KS18CS076
2.SINDU.A.S                 1KS18CS096
3.VARIDHI MADHURANATH       1KS18CS111

2.CONTRIBUTION OF EACH TEAM MEMBER:
a)R.PRATIKSHA:
Applying the basic mathematical operations and implementing the source code.Finding an approach to use Karatsuba algo in integer multiplication.
b)SINDU.A.S:
Correction of errors i.e., debugging.
c)VARIDHI MADHURANATH:
Helped out in logic tracing.Tried the implementation of code in Java.

3.INSTRUCTIONS TO RUN THE PROGRAM:
a)Create a file with two positive decimal numbers in a text editor.
b)Execute the program as "./a.out filename.txt"

4.DETAILS ON EXAMPLE INVOCATION AND OUTPUT:
Example:
INPUT:
12 12
OUTPUT:
Result of multiplication is:144

5.CHALLENGES FACED AND HOW DID YOU ADDRESS THESE:
a)Multiplication of decimal numbers using Divide and Conquer appraoch was quite challenging.
b)The concept of Karatsuba algorithm was learnt and implementing it as a code was out of box.
c)To improve the efficiency of program and by reducing the time complexity.
d)We had to surf through internet regarding this implementation.

6.WHAT DID YOU LEARN FROM THIS ASSIGNMENT:
a)Implementation of Karatsuba algorithm.
b)Learnt that using this approach instead of 4 subproblems,we need only 3 i.e.,
Example:To multiply two numbers 'x' and 'y',
	'a' is used for higher order bits,a=x(h)y(h)
	'd' is used for lower order bits,d=x(l)y(l)
	'e' is used to compute,e=(x(h)+x(l))(y(h)+y(l))-a-d
The product xy is given by,
xy=ar**n+er**n/2+d
c)Using the naive approach this problem would be solved in O(n**2),but Karatsuba algo would be solve this problem in a very less amount of time as compared to the naive approach.
d)Learnt fast multiplication.
e)Various library functions in C++ were learnt.
f)Dealing with strings concept was learnt.


