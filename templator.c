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
        switch (parser->active) {
            case '<': 
                switch (parser->context) {
                    case WHITESPACE:
                        parser->context = CHILDNODE;
                        break;
                    default:
                        parser->context = DECLARATION;
                }

                break;

            case '>': 
                switch (parser->context) {
                    case DECLARATION:
                        parser->context = UNKNOWN;
                        break;
                    default:
                        parser->context = UNKNOWN;
                }

                break;
        }

        if (parser->context != WHITESPACE) skipWhitespace(parser);

        if (pos > size) 
            literal = (char*)realloc(literal, (size += 10));

        literal[pos++] = parser->active;
        parser->active = getc(parser->buffer);
    }

    if (out != NULL)
        *out = size;

    return literal;
}
