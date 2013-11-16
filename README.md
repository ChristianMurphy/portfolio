portfolio
=========

a portfolio of sample code

###prerequisites
A Unix base operating system (Linux or Mac)<br>
Make<br>
Clang c++ compiler (alternatively g++ can be used)<br>
Java Developement Kit 7 (code tested with open jdk 7)

###rational program
impliments a rational datatype in C++.<br>
Overloads basic operators and iostream.

to run code <code>make rational</code>

###maze program
creates an ASCII maze created in C++ displayed in the terminal

to run code <code>make maze</code>


###tournament programs
Solutions to the Spring 2013 Computer Science Club programming tournament.
Which I helped create, run and wrote the official solutions for.
All solutions are in Java.

####Question 1 - Sleep In
The parameter weekday is true if it is a weekday, and the parameter vacation is true if we are on vacation. We sleep in if it is not a weekday or we're on vacation. Return true if we sleep in. 

Input
Weekday: false
Vacation: false

Output
Sleep in: true

solution <code>make question1</code>


####Question 2 - Recursive Factorial
Given n of 1 or more, return the factorial of n, which is n * (n-1) * (n-2) ... 1. Compute the result recursively (without loops). 

factorial(1)    →    1
factorial(2)    →    2
factorial(3)    →    6

solution <code>make question2</code>


####Question 3 - Blackjack
Given 2 int values greater than 0, return whichever value is nearest to 21 without going over. Return 0 if they both go over. 

blackjack(19, 21)    →    21
blackjack(21, 19)    →    21
blackjack(19, 22)    →    19

solution <code>make question3</code>


####Question 4 - Base Conversion
Write a program that accepts base 10 (non-fractional) number and outputs base 2.
Input
10

Output
1010

solution <code>make question4</code>

####Question 5 - Exponent

Finding the exponent of any number can be very troublesome as it grows exponentially. But in this problem you will have to do a very simple task. Given two non-negative numbers m and n, you will have to find the last digit of m^n in decimal number system.

Input
Input from the user. Where the first value is the integer and the second is the exponent.

Output
For each set of input you must produce one line of output which contains a single digit. This digit is the last digit of m^n.


Sample Input                               Output for Sample Input
2 2
2 5
0 0
4
2

solution <code>make question5</code>


####Question 6 - Jolly Jumper (input.txt)

A sequence of n > 0 integers is called a jolly jumper if the absolute values of the difference between successive elements take on all the values 1 through n-1. For instance,
1 4 2 3

is a jolly jumper, because the absolutes differences are 3, 2, and 1 respectively. The definition implies that any sequence of a single integer is a jolly jumper. You are to write a program to determine whether or not each of a number of sequences is a jolly jumper.
Input
Each line of input contains an integer n <= 3000 followed by n integers representing the sequence. Have an input file called in named “input.txt” and submit it with your program.
Output
For each line of input, generate a line of output saying "Jolly" or "Not jolly".
Sample Input
4 1 4 2 3
5 1 4 2 -1 6

Sample Output
Jolly
Not jolly

solution <code>make question6</code>
