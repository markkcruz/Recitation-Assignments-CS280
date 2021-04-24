#include "lex.h"


LexItem id_or_kw(const string& lexeme, int linenum){
    Token token;

    // Check if it is a registered keyword

    switch(kwmap[lexeme]) {
        case PROGRAM :
            token = kwmap[lexeme];
            break;
        case READ :
            token = kwmap[lexeme];
            break;
        case INTEGER :
            token = kwmap[lexeme];
            break;
        case REAL :
            token = kwmap[lexeme];
            break;
        case CHAR :
            token = kwmap[lexeme];
            break;
        case PRINT :
            token = kwmap[lexeme];
            break;
        case IF :
            token = kwmap[lexeme];
            break;
        case THEN :
            token = kwmap[lexeme];
            break;
        case END :
            token = kwmap[lexeme];
            break;
        default : // Then its an Identifier
            token = IDENT;
    }


    // If token is a keyword
    // return {kwmap[lexeme], lexeme, linenum};

    // If token is not a keyword

    if (lexeme == "circle" ||lexeme ==  "square" ||lexeme ==  "rectangle" || lexeme ==  "ellipse")
        token = IDENT;
    return {token, lexeme, linenum};
}

ostream& operator << (ostream& out, const LexItem& tok) {


    //out << tokenPrint[tok.GetToken()] << " (" << tok.GetLexeme() << ") " << "Line #: " << tok.GetLinenum() << std::endl;
    if (tokenPrint[tok.GetToken()] == "IDENT") {
        out << "IDENT " << "("<< tok.GetLexeme() << ") Line #: " << tok.GetLinenum() << std::endl;
    } else if(tokenPrint[tok.GetToken()] == "ERR") {
        out << tokenPrint[tok.GetToken()] << " ("<< tok.GetLexeme() << ") Line #: " << tok.GetLinenum() << std::endl;
    } else if (tokenPrint[tok.GetToken()] == "ICONST" || tokenPrint[tok.GetToken()] == "SCONST" || tokenPrint[tok.GetToken()] == "RCONST" ) {
        out << tokenPrint[tok.GetToken()] << " ("<< tok.GetLexeme() << ") Line #: " << tok.GetLinenum() << std::endl;
    } else {
        out << tokenPrint[tok.GetToken()] << " Line #: " << tok.GetLinenum() << std::endl;
    }
    return out;
}
