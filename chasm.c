#include <stdio.h>
#include <stdlib.h>

#include "nodemode/node.h"
#include "templator.h"
#include "chasm.h"

// TODO: default *.ch buffer name as argv[1]
int main(void) {
    printf("chasm.c copies\n");

    struct Parser parser = {
        .nodes = (NODE*)malloc(sizeof(NODE) * PARSER_BUFFER_SIZE),
        .root  = newRootNODE(),
    };

    parser.root->children = parser.nodes;
    
    const char* buffName = "../chasm.ch";

    if ((parser.buffer = fopen(buffName, "rb")) == NULL) {
        fprintf(stderr, "%s", "buffName path cannot be found\n");
        exit(1);
    }

    while ((parser.active = getc(parser.buffer)) != EOF) {
        char* literal = scanLiterals(&parser, NULL);
        printf("literal: %s\n", literal);
    }

    traverse(parser.root, 0);
    
    fclose(parser.buffer);
    free(parser.nodes);
    free(parser.root);

    return 0;
}
