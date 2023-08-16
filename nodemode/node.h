#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct NODE NODE;

struct NODE {
    struct NODE* children;
    struct NODE* parent;

    char**  data;

    bool    finishedDeclaration;
    bool    isNested;

    size_t  dataCount,  dataBufferSize;
    size_t  childCount, childBufferSize;
};

NODE* newRootNODE();
NODE* newNODE(char** data);
void  traverse(NODE* node, int traverse_depth);
void  addChild(NODE* parent, NODE* child);

#endif
