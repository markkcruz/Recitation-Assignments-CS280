// CourseID:2021SPRING | CS 280: Programming Language Concepts
// Name: Mark Cruz
// Dr. Bassel Arafeh.
// Recitation Assignment 1
// Due Wednesday, January 27, 2021, 23:59 PM

/*
Write a C++ program that displays a message as "Welcome to CS 280.", and prompts the user to enter his or her name as "What is your name?". 
The program should read the userÅfs name as a string and display a welcoming message. 
For a userÅfs name George, the program should printout the message:
+
Hello, George 

A full dialogue example is shown below:
Welcome to CS 280. 
What is your name? 
George
Hello, George
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
//Declarations
string name;

cout << "Welcome to CS 280.\nWhat is your name?\n";
cin >> name;
cout << "Hello, " << name;
}

