// CourseID:2021SPRING | CS 280: Programming Language Concepts
// Name: Mark Cruz
// Dr. Bassel Arafeh.
// Recitation Assignment 2
// Due Wednesday, February 3rd, 2021, 23:59
// Total Points: 6

/*
 * Write a C++ program that reads lines from a file until the end of file.
 * The program should prompt the user for the file name to read from.
 * The program should open the file for reading, and if the file cannot be opened, print the message "File could not be opened",
 * followed by a space and the filename, and exit. The program should keep track of the number of lines, the number of non-blank lines,
 * the number of words, and the number of integers read from the file. An integer is defined as a one or more digits, with an optional sign
 * preceding the number, with no spaces separating the sign and the number. For example, 17234, -354, and +639 are integers, but 17.234, -+23 are not.
 * A word is defined as a sequence of one or more non-whitespace characters separated by whitespace.
 * At the end of file, the program should print out the total number of lines, the number of non-blank lines, the number of words,
 * and the number of integers. Note that a line having only whitespace characters is a non-blank line as well.
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main()
{
    //Final Values to output
    int num_of_lines = 0;
    int num_of_non_blank_lines = 0;
    int num_of_words = 0;
    int num_of_integers = 0;
    bool empty_line_space = false;

    string line; //temp string that store the value of each line
    string file_name; //name of the file to open
    cout << "Enter the name of a file to read from: " << endl;
    cin >> file_name;
    ifstream obj(file_name);
    if (obj)
    {
        while (getline(obj, line))
        {
            //successful read. Add 1 to line counter
            num_of_lines++;

            //line is the str we want to use ISS on
            string word;
            stringstream ss_obj(line);
            //create a vector to store the words
            vector<string> words;
            //check if word is valid
            while (ss_obj >> word)
            {
                words.push_back(word);
            }
            //integer checker
            for(auto & word : words)
            {
                string word_ops = word; //this is a string
                int size_of_word = word.length();
                for(int j = size_of_word-1; j > -1; j--)
                {
                    //check if word only + or -
                    if (size_of_word == 1 && (word_ops[j] == '-' || word_ops[j] == '+'))
                        break;

                    if (word_ops[j] == '.')
                    {
                        //cant have decimals in the integer. BREAK.
                        break;
                    }
                    if (isdigit(word_ops[j]))
                    {
                        j--;
                        if (j == 0) // nice! then this was the last char and was a digit
                        {
                            num_of_integers++;
                            break;
                        }
                        j++;
                        continue;
                    }
                    else
                    {
                        if (word_ops[j] == '-' || word_ops[j] == '+')
                        {

                            if (j == 0) //nice! then + or - was the last char. So this is a integer
                            {
                                num_of_integers++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }

            //check for blank line, if blank add 1 to num_of_blank_lines

                for(int k = 0; k < line.length(); k++)
                {
                    if (!(line[k] == ' ')) {
                        empty_line_space = false;
                        break;
                    }
                    else
                        empty_line_space = true;
                }
                if (empty_line_space)
                    num_of_non_blank_lines++;
                empty_line_space = false;
                if (words.size() != 0)
                    num_of_non_blank_lines++;



            num_of_words += words.size();
        }
        obj.close();
    }

    else
    {
        cout << "File could not be opened " << file_name << endl;
        return 0;
    }
    //final output
    cout << "Total Number of Lines: " << num_of_lines << endl;
    cout << "Number of non-blank lines: " << num_of_non_blank_lines << endl;
    cout << "Number of Words: " << num_of_words << endl;
    cout << "Number of Integers: " << num_of_integers << endl;
    return 0;
}


