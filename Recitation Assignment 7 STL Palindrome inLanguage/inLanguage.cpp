#include <iostream>
#include <string>
#include <stack>
#include <queue>


// L= {S$S’, where Sis a possibly empty string other than $, and S’ = reverse(S)}
/*
 * The strings A$A, ABC$CBA, and $ are in L.
 * The strings AB$AB, ABC, ABC$CB, ABC%CBA are not in L
 * Empty string is not in the language.
 */

/*
 * Write a C++ function to recognize strings in this language, called inLanguage, that uses both
 * a queue and a stack. The function takes a string as an argument and returns true if the input
 * string is in the language, and false otherwise. Thus,as you traverse the input string, insert each
 * character of S into a queue and each character of S’ into a stack. Assume that each input string
 * contains exactly one $.
 */

/*
 * If the input string is empty, the inLanguagefunction should printout the message "Empty
 * string is not in the Language.",thenreturnfalse. While if the input string does not include a
 * “$”, the function shouldprintout the message "string is missing $.",thenreturnfalse.
 *
 * The signature of the function is defined as:
 * bool inLanguage(string & inputString);
 */

/*
 * A  driver program is provided for testing the implementation, called “RA7prog.cpp”, on Vocareum.
 * The “RA7prog.cpp” will be propagated to your Work  directory.The  driver program opens a provided
 * file name from the command line for reading. For each sentence read fromthe file, it calls the function
 * inLanguageto check whether that sentence is in L or not. For example, if the sentence is “A$A”, it
 * prints the message “A$A is a sentence in  the  Language”.  Otherwise,  if  the  sentence  is  “ABC$BC“,
 * it  prints  the  message “ABC$BC is not a sentence in the Language.”
 */

using namespace std;

/*

int main() {

    // remove this in real program
    string input = "";

    if (inLanguage(input)) {
        cout << input << " is a sentence in the Language.\n";
    } else {
        cout << input << "  is not a sentence in the Language.\n";
    }
}
*/

bool inLanguage(string& input) {

    // Flag for checking size of left string and right string of $
    bool dollarFlag = true;

    // Check for empty string

    if (input.empty()) {
        cout << "Empty string is not in the Language.\n";
        exit(0);
    }


    // no$ and only% TESTCASES
    // check if $ is missing
    if (input.find('$') != std::string::npos){
        // found, check if stringsize == 1 | If it is, then output true.
        if (input.size() == 1) {
            // then its only $
            return true;
        }
    } else {
        cout << "string is missing $.\n"; // not found
        return false;
    }


    // Now check for palindrome by using queues and stacks
    stack<char> myStack;
    stack<char> myStackPopped;
    queue<char> myQueue;

    int containerSizeLeft = 0;
    int containerSizeRight = 0;

    for (char i : input) {
        // Stop pushing once we find $
        if (i == '$') {
            dollarFlag = false;
            continue;
        }
        //std::cout << i << ' '; // Used for Testing
        if (dollarFlag) {
            //Push onto stack AND queue.
            myStack.push(i);
            myQueue.push(i);
            // Counter for left chars
            containerSizeLeft++;
        } else {
            containerSizeRight++;
        }
    }

    // Check if the left and right sides of the $ are ==
    if (containerSizeLeft != containerSizeRight) {
        return false;
    }

    // Now pop from the stack
    for (int i = 0; i < containerSizeLeft; i++) {
        myStackPopped.push(myStack.top());
        myStack.pop();
    }

    // Now compare the QUEUE and the STACK by checking front == top. If equal, pop till end of size.
    // Example ABC$CBA

    for (int i = 0; i < containerSizeLeft; i++) {
        if (myStackPopped.top() == myQueue.front()){
            // Then its free to go. On the road to become a palindrome like it always dreamed of being.

            // Now pop both the queue and the stack!
            myStackPopped.pop();
            myQueue.pop();
        } else {
            // Not a match. Yikes.
            return false;
        }
    }

    // Passed all the test cases. It really is a palindrome!
    return true;
}