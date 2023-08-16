#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "node.h"

#define NODEMODE_PRINT_DATA

NODE* newRootNODE() {
    NODE* node = (NODE*)malloc(sizeof(NODE));

    node->childBufferSize = 10;
    node->childCount = 0;
    node->children = (NODE*)malloc(sizeof(NODE) * 10);

    return node;
}

NODE* newNODE(char** data) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    
    if (data != NULL)
        node->data = data;

    node->dataCount  = 0;
    node->childCount = 0;

    return node;
}

void addChild(NODE* parent, NODE* child) {
    if (parent->childCount >= parent->childBufferSize) {
        parent->childBufferSize += 10;
        parent->children = (NODE*)realloc(parent->children, sizeof(NODE) * parent->childBufferSize);
    }

    parent->children[parent->childCount] = *child;
    parent->childCount++;
}

void traverse(NODE* node, int traverse_depth) {
    traverse_depth++;

    if (node == NULL)
        return;

#ifdef NODEMODE_PRINT_DATA
    for (int i = 0; i < node->dataCount; i++)
        printf("%s, ", node->data[i]);

    printf("\n");
#endif

    for (size_t i = 0; i < node->childCount; ++i) {
#ifdef NODEMODE_PRINT_DATA
        for (int j = 0; j < traverse_depth; j++) printf("-");
        printf("> "); 
#endif

        traverse(&(node->children[i]), traverse_depth);
    }

    traverse_depth--;
}
