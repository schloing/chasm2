#ifndef TEMPLATOR_H
#define TEMPLATOR_H

#include "nodemode/node.h"
#include <stddef.h>
#include <stdio.h>

typedef enum {
    UNKNOWN,
    DECLARATION,  // checks for the 'declaration' of a tag:    <html ... >content</html>
    CHILDNODE,    // checks for the creation of a nested node: <html *attributes*> <...> </html>
    WHITESPACE,   // take into account whitespace:             <p *attributes*> ... </p>
} CONTEXT;

// <p class='para'>what a nice paragraph! <span>       so cool!</span></p>
//  ^^^^^^^^^^^^^^ ^^^^^^^^^^^^^^^^^^^^^^ ^^^^^^       ^^^^^^^^
//  DECLARATION    WHITESPACE             CHILDNODE    WHITESPACE
//                                        DECLARATION

struct Parser {
    NODE*  root;    // root->children = nodes
    NODE*  nodes;   //                  ^^^^^
    
    CONTEXT context;
    FILE*   buffer;
    char    active;
};

size_t skipWhitespace(struct Parser* parser);
char*  scanLiterals(struct Parser* parser, size_t* out);

#endif
