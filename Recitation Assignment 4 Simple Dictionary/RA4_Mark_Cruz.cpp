// CourseID:2021SPRING | CS 280: Programming Language Concepts
// Name: Mark Cruz
// Dr. Bassel Arafeh.
// Recitation Assignment 4 | <Maps> AKA Dictionaries(Python)
// Due Date: Wednesday, February 17, 2021, 23:59
// Total Points: 6

/*
Write a C++ program that creates a simple directory for the occurrences of printable characters read from an input file.
 The program should read from a file name specified in the command line as an argument, However, if no file name is provided,
 the program should print on a new line "No file is found", and exit. If the file cannot be opened, print
 on a new line "File cannot be opened: ", followed by the file name, and exit. The program should read from the file words
 until the end of file. If the input file is empty, print out on a new line the message "File is empty." and then exit. A word is defined as a
 contiguous number of non-whitespace characters separated by whitespace. The program should keep a record of the number of occurrences of each letter,
 decimal digit (09), and any non-alphanumeric characters (e.g., �e.�f, �e,�f, �e@�f, etc.) in a directory built using the <map> container. In
 order to avoid counting uppercase and lowercase letters, all letters should be converted to uppercase. After all input has been processed, the program should:
    ? Print each decimal digit and letter that was seen the largest number of times on a line by itself and the number of times it was seen in the file.
    ? Print each printable character read from the file and the number of times it was seen. The character should be printed in order.
    ? Print the number of non-alphanumeric characters that were seen in the file.

 Examples in the Doc.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype> // cctype - isdigit(), isalpha(), isspace()
#include <map>


using namespace std;



int main(int argc, char*  argv[]) {
    // --Main Variables for iofstream--=
    ifstream finObj;
    string file_name; // Name of file we are working with. Either from argv[1] or cin (Case 3).
    string progname(argv[0]); // Name of the program
    string line; //temp string that store the value of each line

    // Core variables
    map<char, int> Map; // General Map
    map<char, int> Map_Char; // Map for chars
    map<char, int> Map_Digit; // Map for Digits
    map<char, int> Map_NonAlpha; // Map for no alpha
    char ch;
    int max_value_char = -1;
    int max_value_digit = -1;
    vector<pair <char,int> > max_value_pairs_chars; // This is for returning the largest number of occurrences CHARS.
    vector<pair <char,int> > max_value_pairs_digit; // This is for returning the largest number of occurrences DIGITS.
    // --Output Variables--


    // Check if there are only 2 or more arguments
    if (argc >= 1) {
        file_name = "infile4"; //argv[1] // Set string to the name of the filename, which is argv[1]
        finObj.open(file_name); // Open the file with the istream object finObj
        // Check if the file is open
        if (finObj.is_open())
            //in = &finObj;
            ;
        else {
            cout << "File cannot be opened: " << file_name << endl;
            exit(1);
        }
        //Do EVERYTHING here.

        // For general Map
        while (finObj >> skipws >> ch) {
            ch = toupper(ch);

            // Map for alpha num. Use size to print out number of unique non-alphanums
            if (!isalnum(ch))
            {
                if (Map_NonAlpha.find(ch) == Map_NonAlpha.end()) {
                    Map_NonAlpha.insert(make_pair(ch, 1));
                } else {
                    // Exists, so just update the value with ++
                    Map_NonAlpha[ch] = Map_NonAlpha[ch]++;
                }
            }



            // cout << ch; // tester code
            // Value does not exist in the map. So create the key:value pair with value = 1.
            if (Map.find(ch) == Map.end()) {
                Map.insert(make_pair(ch, 1));
            } else {
                // Exists, so just update the value with ++
                Map[ch] = Map[ch]++;
            }
        }

        /*
        // For Char Map
        while (finObj >> skipws >> ch) {
            ch = toupper(ch);
            if (!isalpha(ch))
            // not a char, so dont put it in my map...
            {
                continue;
            }
            // cout << ch; // tester code
            // Value does not exist in the map. So create the key:value pair with value = 1.
            if ( Map_Char.find(ch) == Map_Char.end() ) {
                Map.insert(make_pair(ch, 1));
            } else {
                // Exists, so just update the value with ++
                Map_Char[ch] = Map_Char[ch]++;
            }
        }


        // For Digit Map
        while (finObj >> skipws >> ch) {
            ch = toupper(ch);
            if (!isdigit(ch))
                // not a char, so dont put it in my map...
            {
                continue;
            }
            // cout << ch; // tester code
            // Value does not exist in the map. So create the key:value pair with value = 1.
            if ( Map_Digit.find(ch) == Map_Digit.end() ) {
                Map.insert(make_pair(ch, 1));
            } else {
                // Exists, so just update the value with ++
                Map_Digit[ch] = Map_Digit[ch]++;
            }
        }
        */



        // FIND CHAR MAX VALUES ----------------------
        // find max value
        map<char, int>::iterator curDigit;
        pair<int, int> digitMaxValue = make_pair(0, 0);
        for (curDigit = Map.begin(); curDigit != Map.end(); ++curDigit) {

            // If entry >, replace.
            if (curDigit->second > digitMaxValue.second && isdigit(curDigit->first)) {
                digitMaxValue = make_pair(curDigit->first, curDigit->second);
            }
        }
        max_value_digit = digitMaxValue.second;



        // FIND Char MAX VALUES ----------------------
        // find max value
        map<char, int>::iterator curChar;
        pair<int, int> charMaxValue = make_pair(0, 0);
        for (curChar = Map.begin(); curChar != Map.end(); ++curChar) {

            // If entry >, replace.
            if (curChar->second > charMaxValue.second && isalpha(curChar->first)) {
                charMaxValue = make_pair(curChar->first, curChar->second);
            }
        }
        max_value_char = charMaxValue.second;


        // Now that we found the max values, we can print out all the key value pairs with the same max.

        // FOR CHARS
        // use max_value_pairs_chars
        for (auto &it : Map) {
            if (it.second == max_value_char && (isalpha(it.first))) {
                max_value_pairs_chars.push_back(make_pair(it.first, it.second));
            }
        }

        // use max_value_pairs_chars
        for (auto &it : Map) {
            if (it.second == max_value_digit && (isdigit(it.first))) {
                max_value_pairs_digit.push_back(make_pair(it.first, it.second));
            }
        }





        // Testing
        /*
        if (max_value_char != -1)
        {
            cout << "This is max value char xd: " << max_value_char << endl;
        }

        if (max_value_digit != -1)
        {
            cout << "This is max value digit xd: " << max_value_digit << endl;
        }
         */












        /*
        while (getline(finObj, line)) {
            line_count++; // Successful read, add 1 to line counter
            int length_of_line = line.length();
            // Traverses whole line
            // --Check for char, letter, digit using the line string--
            int temp_char = 0; // For counting chars
            for (int i = 0; i <= length_of_line; i++) {
                if (isdigit(line[i])) {
                    digit_count++;
                }
                if (isalpha(line[i])) {
                    letter_count++;
                }
                temp_char = i;
            }
            char_count += temp_char;
            // --WORD COUNTER--
            string word; // word is the str we want to use ISS on
            stringstream ss_obj(line);
            //create a vector to store the words
            vector<string> words;
            //check if word is valid
            while (ss_obj >> word) {
                words.push_back(word);
            }
            // Now each word is in a vector. So now we can count how many words in each line.
            word_count += words.size();
        }
        */



        // Close the file after it was successfuly read.
        finObj.close();
    } else {
        cout << "File cannot be opened: " << file_name << endl;
        return 0;
    }
    // Check if any characters in the file. If it is 0, then the file is empty.
    if (Map.size() == 0) {
        cout << "File is empty." << endl;
        return 0;
    }

    // step one: find max value
    // iterate through map and find key:value pairs that have the same value as max_value int
    // iterate through map and find values that are the same as that max value

    for (int i = 0; i < max_value_pairs_digit.size(); i++) {
        cout << "Digits of Largest number of occurrences: " << max_value_pairs_digit[i].first << ": " << max_value_pairs_digit[i].second << endl;
    }

    for (int i = 0; i < max_value_pairs_chars.size(); i++) {
        cout << "Letters of Largest number of occurrences: " << max_value_pairs_chars[i].first << ": " << max_value_pairs_chars[i].second << endl;
    }

    cout << "List of characters seen in the file and their number of occurrences:\n";
    //print out map
    for(auto & it : Map)
        cout << it.first << ":" << it.second <<endl;


    cout << "Number of non-alphanumeric characters seen in the file: " << Map_NonAlpha.size() << endl;
    return 0;
}
