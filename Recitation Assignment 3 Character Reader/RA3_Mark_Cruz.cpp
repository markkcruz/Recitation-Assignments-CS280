// CourseID:2021SPRING | CS 280: Programming Language Concepts
// Name: Mark Cruz
// Dr. Bassel Arafeh.
// Recitation Assignment 3 | File I/O
// Due Date: Friday, February 12, 2021, 23:59
// Total Points: 5

/*
Write a C++ program that reads from a file name specified in the command line as an argument, and ignores any extra command line arguments
that are provided after the file name. However, if no file name is provided, the program should use the standard input instead of a file.
If the file cannot be opened, print on a new line "File cannot be opened: ", followed the file name, and exit. The program should read from the
file character by character until the end of file. If the input file is empty, print out the message "File is empty." on a new line and then exit.
The program should count the number of lines, number of words, number of characters, number of digit characters (‘0’ - ‘9’), and the number of
alphabetic characters seen in the file.
*/


using namespace std;

int main(int argc, char*  argv[]) {
    // --Main Variables for iofstream--=
    ifstream finObj;
    string file_name; // Name of file we are working with. Either from argv[1] or cin (Case 3).
    string progname(argv[0]); // Name of the program
    string line; //temp string that store the value of each line

    // --Output Variables--
    // Lines are "line counts not including the last \n in a document | Words are any 1 or more char with no ' ' |
    // Chars are any character | Digits are any char from 0-9 | Letters are letters in the alphabet of 26
    int char_count = 0, line_count = 0, word_count = 0, digit_count = 0 , letter_count = 0;

    // Check if there are only 2 or more arguments
    if (argc >= 2) {
        file_name = argv[1]; //"myfile4.txt" // Set string to the name of the filename, which is argv[1]
        finObj.open(file_name); // Open the file with the istream object finObj
        // Check if the file is open
        if ( finObj.is_open() )
            //in = &finObj;
            ;
        else {
            cerr << "File cannot be opened: " << file_name << endl;
            exit(1);
        }
        //Do EVERYTHING here.
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
        // Close the file after it was successfuly read.
        finObj.close();
    } else {
        while (getline(cin, line)) {
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
    }
    // Check if any characters in the file. If it is 0, then the file is empty.
    if (char_count == 0) {
        cout << "File is empty." << endl;
        return 0;
    }
    // \n was not READ in our char count. Add to char count by the number of lines in the program.
    char_count += line_count;
    // Final output for grading
    cout << "LINES: " << line_count << endl << "WORDS: " << word_count  << endl << "CHARS: " << char_count << endl << "DIGITS: " << digit_count << endl << "LETTERS: " << letter_count << endl;
    return 0;
}