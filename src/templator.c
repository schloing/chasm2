#include "templator.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define scnltrl(parser) scanLiterals(parser, NULL)

size_t skipWhitespace(struct Parser* parser) {
    size_t skip = 0;

    while (isspace(parser->active) || !isprint(parser->active)) {
        parser->active = getc(parser->buffer);
        skip++;
    }

    return skip;
}

char* scanLiterals(struct Parser* parser, size_t* out) {
    char*  literal = (char*)malloc(sizeof(char) * 10);
    size_t size    = 10, pos = 0;

    while (isprint(parser->active)) {
        // this is hopefully a more efficient way of checking for upcoming '{{' by checking only one character ahead and
        // checking for other tokens without additional code or functions

        switch (parser->active) {
            char next = getc(parser->buffer);
            parser->skipGet = true;

            case '{':
                if (next == '{')
                    beginBlock(VARIABLE);

                break;
        
            case '<':
                break;
           
            case '>':
                break;
            
            case '"':
                break;
           
            case '\'':
                break;
        }

        // begin a variable block
        // define a new variable in the "heap" and create a node that refers to this "variable"
        // make this variable accessible in the heap, and upon updating

        if (pos > size) 
            literal = (char*)realloc(literal, (size += 10));

        literal[pos++] = parser->active;
        if (parser->skipGet)
            parser->active = getc(parser->buffer);
    }

    if (out != NULL)
        *out = size;

    return literal;
}
