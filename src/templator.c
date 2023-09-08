#include "templator.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

void parse(FILE* buffer) {
    regex_t regex;
    regmatch_t matches[1];

    fseek(buffer, 0, SEEK_END);
    long buffsiz = ftell(buffer);
    rewind(buffer);

    char* buffchar = (char*)malloc(buffsiz + 1);
    fread(buffchar, 1, buffsiz, buffer);
    buffchar[buffsiz] = '\0';

    size_t   comp_    = regcomp(&regex, "(?s)({{.*?}}|{%.*?%}|{#.*?#})", REG_EXTENDED);
    printf("%zu\n", comp_);
    size_t   exec_    = regexec(&regex, buffchar, 1, matches, 0);
    regoff_t position = matches[0].rm_so;

    printf("%lld", position);

    regfree(&regex);
    free(buffchar);
}
