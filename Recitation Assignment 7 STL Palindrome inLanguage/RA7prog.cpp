#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool inLanguage(string&);

int main(int argc, char *argv [])
{
    string sentence;
    bool isInLanguage;
    int Lcount=0;

    ifstream file;
    if( argc >= 2 ) {
        file.open(argv[1]);
        if( !file)
        {
            /* error */
            cerr << "File cannot be opened: " << argv[1] << endl;
            exit (1);
        }

    }
    else
    {
        cerr << "No file is found" << endl;
        exit (1);
    }

    getline(file, sentence);

    while ( !file.eof()) {
        Lcount++;
        isInLanguage = inLanguage(sentence);
        if (isInLanguage)
        {
            cout << sentence << " is a sentence in the Language." << endl;
        }
        else
        {
            cout << sentence << " is not a sentence in the Language." << endl;
        }

        getline(file, sentence);
    }
}
