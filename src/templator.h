#ifndef TEMPLATOR_H
#define TEMPLATOR_H

#include "nodemode/node.h"
#include <stddef.h>
#include <stdio.h>

typedef enum {
    UNKNOWN,
    DECLARATION,  // checks for the 'declaration' of a tag:    <html ... >content</html>
    CHILDNODE,    // checks for the creation of a nested node: <html *attributes*> <...> </html>
    VARIABLE,     // checks for references to cvars:           <p>{{...}}</html> 
    WHITESPACE,   // take into account whitespace:             <p *attributes*> ... </p>
} CONTEXT;

//   <p class='para'>what a nice paragraph! <span>       so cool!</span></p>
//    ^^^^^^^^^^^^^^ ^^^^^^^^^^^^^^^^^^^^^^ ^^^^^^       ^^^^^^^^
// >> UNKNOWN        DECLARATION            
//    DECLARATION    WHITESPACE             CHILDNODE    WHITESPACE
//                                          DECLARATION

struct Parser {
    NODE*  root;    // root->children = nodes
    NODE*  nodes;   //                  ^^^^^
    
    CONTEXT context;
    FILE*   buffer;
    char    active;
    bool    skipGet;
};

size_t skipWhitespace(struct Parser* parser);
char*  scanLiterals(struct Parser* parser, size_t* out);
void   beginBlock(CONTEXT context);

#endif
