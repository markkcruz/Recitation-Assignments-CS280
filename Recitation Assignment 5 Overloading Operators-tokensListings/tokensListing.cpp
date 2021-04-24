#include <iostream>
#include <map>
#include "lex.h"


/*
 * CS280 - Spring 2021
 */

#include <cctype>
#include <map>
using std::map;

using namespace std;

int main(int argc, char *argv[])
{
    LexItem	tok;
    LexItem kwtok;
    LexItem idtoks[] = {
            LexItem(IDENT,"PRINT",3),
            LexItem(IDENT,"circle",3),
            LexItem(IDENT,"square",11),
            LexItem(IDENT,"rectangle",12),
            LexItem(IDENT,"ellipse",14),
            LexItem(IDENT, "PROGRAM", 1),
            LexItem(IDENT, "READ", 8),
            LexItem(IDENT, "INTEGER",2),
            LexItem(IDENT, "REAL",3),
            LexItem(IDENT, "CHAR",4),
            LexItem(IDENT, "IF", 5),
            LexItem(IDENT, "THEN", 5),
            LexItem(IDENT, "END", 0)
    };
    LexItem toks[] = {
            LexItem(END,"END",15),
            LexItem(ICONST,"579",5),
            LexItem(SCONST,"hello NJIT",6),
            LexItem(RCONST,"5.79",7),
            LexItem(PLUS,"+",3),
            LexItem(MINUS,"-",3),
            LexItem(MULT,"*",3),
            LexItem(DIV,"/",3),
            LexItem(ASSOP,"=",3),
            LexItem(LPAREN,"(",3),
            LexItem(RPAREN,")",3),
            LexItem(COLON,":",3),
            LexItem(COMA,",",3),
            LexItem(COMA,",",3),
            LexItem( EQUAL, "EQUAL", 4),
            LexItem( LTHAN, "LTHAN", 4 ),
            LexItem( CONCAT, "CONCAT", 6 ),
            LexItem(ERR, "ERR", 3),
            LexItem(DONE,"DONE",3),
    };

    bool idsflag = false;
    bool tokflag = false;
    int i;

    if (argc == 1)
    {
        cerr << "No Specified arguments." << endl;
        return 0;
    }
    for( int i=1; i<argc; i++ ) {
        string arg( argv[i] );
        if( arg == "-idsonly" )
            idsflag = true;
        else if( arg == "-othertok" )
            tokflag = true;
        else if( arg[0] == '-' ) {
            cerr << "UNRECOGNIZED FLAG " << arg << endl;
            return 0;
        }
    }
    if(idsflag)
    {
        cout << "Identifiers and Keywords:" << endl;
        for( i = 0; idtoks[i].GetLexeme() != "END"; i++ )
        {
            kwtok = id_or_kw(idtoks[i].GetLexeme(), toks[i].GetLinenum());
            cout << kwtok;
        }
        kwtok = id_or_kw(idtoks[i].GetLexeme(), toks[i].GetLinenum());
        cout << kwtok;
    }
    if(tokflag)
    {
        cout << "Other tokens:" << endl;
        for( i = 0; toks[i] != DONE; i++ )
        {
            cout << toks[i];
        }
        cout << toks[i];
    }
    return 0;
}
